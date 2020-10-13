# include <iostream>
# include <vector>

using namespace std;

//takes two elements in a vector and swaps their positions
void swap(vector<int> &vect, int idx1, int idx2){
    //stores first element in temp variable
    int temp = vect.at(idx1);
    //reassigns element at idx1 to be element at idx2
    vect.at(idx1) = vect.at(idx2);
    //reassigns element at idx2 to be element that was at idx1
    vect.at(idx2) = temp;
}

//implementation of selection sort that sorts elements in vector in ascending order
void selectionSort(vector<int> &vect){
    //iterates through all elements
    for(int i = 0; i < vect.size(); ++i){
        //variable meant to store the index of the largest element in vector
        //initialized to be the first element in the unsorted part of the vector
        int maxIdx = i;
        //inner for loop finds largest element in the unsorted part of the vector
        for(int j = i + 1; j < vect.size(); ++j){
            //if the current element is larger than the element at maxIdx, reassign maxIdx to j
            if(vect.at(j) > vect.at(maxIdx)){
                maxIdx = j;
            }
        }
        //swap the positions of the elements at maxIdx and i
        swap(vect, maxIdx, i);
    }
}

//given a vector makes a subvector based on the given starting and ending indices
//used in mergeSort function
vector<int> subVectorMaker(vector<int> &vect, int start, int end){
    vector<int> subVect;
    //subvector includes element at start index and excludes end index
    for(int i = start; i < end; ++i){
        subVect.push_back(vect.at(i));
    }
    return subVect;
}

//implementation of selection sort that sorts elements in vector in ascending order
//splits vector in half once, sorts each half using selectionSort function, then merges the two lists back together
void mergeSort(vector<int> &vect){
    //midpoint of given vect
    int mid = vect.size()/2;
    //left half of vect goes from index 0 to mid - 1
    vector<int> leftVec = subVectorMaker(vect, 0, mid);
    //left half of vect goes from index mid to vect.size()-1
    vector<int> rightVec = subVectorMaker(vect, mid, vect.size());

    //sorts left and right halves
    selectionSort(leftVec);
    selectionSort(rightVec);

    //initializes variables to track which elements of the subvectors have been merged back into the main vector
    int leftTracker = 0;
    int rightTracker = 0;

    //merging elements of subvectors back into the main vector
    for(int i = 0; i < vect.size(); ++i){
       //if all elements of the left subvector have been merged back into the main vector
        if(leftTracker >= leftVec.size()){
            //merge the next element of the right subvector into the main vector
            vect.at(i) = rightVec.at(rightTracker);
            rightTracker += 1;
        }
        //if all elements of the right subvector have been merged back into the main vector
        else if(rightTracker >= rightVec.size()){
            //merge the next element of the left subvector into the main vector
            vect.at(i) = leftVec.at(leftTracker);
            leftTracker += 1;
        }
        //if the element in the left subvector at leftTracker is greater than the element in the right subvector at rightTracker
        else if(leftVec.at(leftTracker) > rightVec.at(rightTracker)){
            //merge the left subvector element back into the main vector
            vect.at(i) = leftVec.at(leftTracker);
            //increment leftTracker
            leftTracker += 1;
        }
        //if the element in the right subvector at rightTracker is greater than the element in the left subvector at leftTracker
        else {
            //merge the right subvector element back into the main vector
            vect.at(i) = rightVec.at(rightTracker);
            //increment leftTracker
            rightTracker += 1;
        }
    }
}

//implementation of bubble sort that sorts elements in vector in ascending order
void bubbleSort(vector<int> &vect){
    //variable to track if a swap has been made during the current iteration of the outer for loop
    bool noSwaps;
    
    //iterates through all elements
    for(int i = 0; i < vect.size(); ++i){
        //initialized to true as no swaps have been made yet
        noSwaps = true;

        //every iteration, the smallest element is moved to the very end of the vector
        //each iteration starts at the beginning but does not go all the way to the end as all elements from vect.size() - (i+1) to vect.size() - 1 have been sorted
        for(int j = 0; j < vect.size() - (i+1); ++j){
            //if the element at j is smaller than the element at j+1
            if(vect.at(j) < vect.at(j+1)){
                //swap the two elements
                swap(vect, j, j+1);
                //a swap has been made so change noSwaps to false
                noSwaps = false;
            }
        }
        //if the inner for loop ran all the way through and no swaps have been made
        if(noSwaps == true){
            //the list is already sorted and the outer loop is broken
            break;
        }
    }
}

int main(){

    //list to be sorted
    vector<int> list;
    //variable to store which kind of sorting will be performed
    int operation;
    //variable to hold incoming numbers from input
    int num;

    cin >> operation;

    //while the inputs are ints
    while(cin >> num){
        //append the int to the list
        list.push_back(num);
    }

    switch(operation){
        //if operation is 0, perform bubble sort
        case 0:
            bubbleSort(list);
            break;
        //if operation is 0, perform merge sort
        case 1:
            mergeSort(list);
            break;
    }

    //print out sorted list
    for(int i = 0; i < list.size(); ++i){
        cout << list.at(i) << " ";
    }

    return 0;
   
}