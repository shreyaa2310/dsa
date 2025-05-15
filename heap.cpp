#include<iostream>
using namespace std;


class heap{
    public:
    int arr[100];
    int size;

    heap()
    {
        arr[0]=-1;
        size=0;
    }

    void insert(int val){
        size=size+1;
        int i =size;
        arr[i]=val;

        while(i>1){
            int parent =i/2;

            if (arr[parent]<arr[i]){
                swap(arr[parent],arr[i]);
                i=parent;
            }
            else{
                return;
            }
        }
    }

    void print(){
        for(int j=1;j<=size;j++){
            cout<<arr[j]<<" ";
        }cout<<endl;
    }

    void deletefromheap(){
        if(size ==0){
            cout<<"nothing to delete"<<endl;
            return;
        }

        arr[1]=arr[size];
        size--;

        int j=1;
        while(j<size){
            int leftIndex = 2*j;
            int rightIndex =2*j+1;

            if(leftIndex <size &&arr[j] < arr[leftIndex]){
                swap(arr[j],arr[leftIndex]);
                j=leftIndex;
            }
            else if(rightIndex <size &&arr[j] < arr[rightIndex]){
                swap(arr[j],arr[rightIndex]);
                j=rightIndex;
            }

            else{
                return ;
            }
        }
    }
};



int main() {
    heap h;
    int n, val;

    cout << "Enter number of elements to insert in the heap: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        h.insert(val);
    }

    cout << "Heap after insertion:\n";
    h.print();

    cout << "Do you want to delete the root element? (1 = yes, 0 = no): ";
    int del;
    cin >> del;

    if (del == 1) {
        h.deletefromheap();
        cout << "Heap after deletion:\n";
        h.print();
    }

    return 0;
}
