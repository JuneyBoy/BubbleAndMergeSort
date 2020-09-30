# include <iostream>
# include <vector>

using namespace std;

void swap(vector<int> &vect, int idx){
    int temp = vect.at(idx);
    vect.at(idx) = vect.at(idx+1);
    vect.at(idx+1) = temp;
}

void bubbleSort(vector<int> &vect){
    
    bool noSwaps;
    
    for(int i = 0; i < vect.size(); ++i){
        
        noSwaps = true;

        for(int j = 0; j < vect.size() - (i+1); ++j){
            
            int a = vect.at(j);
            int b = vect.at(j+1);

            if(a < b){
                swap(vect, j);
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

    cout << endl;

    bubbleSort(list);

    for(int i = 0; i < list.size(); ++i){
        cout << list.at(i) << " ";
    }

    return 0;
   
}