#include <iostream>
#include <vector>

using namespace std;

void createMaxHeap(int n, int arr[]){

    // After adding each new element, make sure the heap property is satisfied
    for(int i=0;i<n;i++){ // To select an element
        //Stop when heap property is satisifed or you reach the front
        int j=i;
        if(j>0){
            while(j>0 && (arr[j]>arr[(j-1)/2])){
                swap(arr[j],arr[(j-1)/2]);
                j=(j-1)/2;
            }
        }
    }
}

void heapSort(int n,int arr[]){

    createMaxHeap(n, arr);
    //Delete all the elements
    for(int k=0;k<n;k++){
        
        swap(arr[0],arr[n-1-k]);

        int i=0;
        int last=n-1-k;
        while(i<last){
            int left=2*i + 1;
            int right=2*i + 2;
            int largest=i;

            if(left<last && arr[left]>arr[largest])
                largest=left;
            if(right<last && arr[right]>arr[largest])
                largest=right;
            
            if(largest!=i){
                swap(arr[i],arr[largest]);
                i=largest;
            }
            else
                break;
        }
    }


}

int main(){

    int n;
    int marks;

    cout<<"Enter the number of students"<<endl;
    cin>>n;

    int arr[n];

    cout<<"Enter the marks of the students"<<endl;
    for(int i=0;i<n;i++){
        cin>>marks;
        arr[i]=marks;
    }
    heapSort(n,arr);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}