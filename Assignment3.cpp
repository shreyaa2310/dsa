#include <iostream>
#include <queue>

using namespace std;

int main(){

    priority_queue<int> max_heap;

    int n;
    cout<<"Enter the number of students: "<<endl;
    cin>>n;

    int marks;
    cout<<"Enter the marks of each student"<<"\n";
    for(int i=0;i<n;i++){
        cin>>marks;
        max_heap.push(marks);
    }

    while(!max_heap.empty()){
        cout<<max_heap.top()<<" ";
        max_heap.pop();
    }

}


