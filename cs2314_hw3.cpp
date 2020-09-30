# include <iostream>
# include <vector>

using namespace std;

void swap(vector<int> &vect, int idx1, int idx2){
    int temp = vect.at(idx1);
    vect.at(idx1) = vect.at(idx2);
    vect.at(idx2) = temp;
}

void selectionSort(vector<int> &vect){
    for(int i = 0; i < vect.size(); ++i){
        int maxIdx = i;
        for(int j = i + 1; j < vect.size(); ++j){
            if(vect.at(j) > vect.at(maxIdx)){
                maxIdx = j;
            }
        }
        swap(vect, maxIdx, i);
    }
}

vector<int> subVectorMaker(vector<int> &vect, int start, int end){
    vector<int> subVect;

    for(int i = start; i < end; ++i){
        subVect.push_back(vect.at(i));
    }
    return subVect;
}

void mergeSort(vector<int> &vect){
    int mid = vect.size()/2;
    vector<int> leftVec = subVectorMaker(vect, 0, mid);
    vector<int> rightVec = subVectorMaker(vect, mid, vect.size());

    cout << endl;

    for(int i = 0; i < leftVec.size(); ++i){
        cout << leftVec.at(i) << " ";
    }

    cout << endl;

    for(int i = 0; i < rightVec.size(); ++i){
        cout << rightVec.at(i) << " ";
    }

    cout << endl;

    selectionSort(leftVec);
    selectionSort(rightVec);

    for(int i = 0; i < leftVec.size(); ++i){
        cout << leftVec.at(i) << " ";
    }

    cout << endl;

    for(int i = 0; i < rightVec.size(); ++i){
        cout << rightVec.at(i) << " ";
    }

    cout << endl;

    int leftTracker = 0;
    int rightTracker = 0;

    for(int i = 0; i < vect.size(); ++i){
        if(leftTracker >= leftVec.size()){
            vect.at(i) = rightVec.at(rightTracker);
            rightTracker += 1;
        }
        else if (rightTracker >= rightVec.size()){
            vect.at(i) = leftVec.at(leftTracker);
            leftTracker += 1;
        }

        else if(leftVec.at(leftTracker) > rightVec.at(rightTracker)){
            vect.at(i) = leftVec.at(leftTracker);
            leftTracker += 1;
        }
        else{
            vect.at(i) = rightVec.at(rightTracker);
            rightTracker += 1;
        }
    }
}

void bubbleSort(vector<int> &vect){
    
    bool noSwaps;
    
    for(int i = 0; i < vect.size(); ++i){
        
        noSwaps = true;

        for(int j = 0; j < vect.size() - (i+1); ++j){
            
            int a = vect.at(j);
            int b = vect.at(j+1);

            if(a < b){
                swap(vect, j, j+1);
                noSwaps = false;
            }
        }
        if(noSwaps == true){
            break;
        }
    }
}

void pushIt(vector<int> &vect){
    vect.push_back(19);
}


int main(){

    vector<int> list;

    list.push_back(5);
    list.push_back(2);
    list.push_back(17);
    list.push_back(21);
    list.push_back(9);
    list.push_back(1);
    list.push_back(7);

    for(int i = 0; i < list.size(); ++i){
        cout << list.at(i) << " ";
    }

    mergeSort(list);

    for(int i = 0; i < list.size(); ++i){
        cout << list.at(i) << " ";
    }

    cout << endl;

    return 0;
   
}