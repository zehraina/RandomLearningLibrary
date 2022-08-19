
 #include<iostream>
 using namespace std;
 int search(int arr[],int n,int s ){
    for(int i=0;i<s;i++){
        
            if (arr[i]==n)
                return i; 
            
            
        }
        return -1;

    }

 
 int main(){
    int s;
 int arr[100], n;
cout<<"Enter the size of the array"<<endl;
cin>>s;
cout<<"Enter the elements to populate the array"<<endl;

for (int i=0;i<s;i++){
    cin>>arr[i];
}
cout<<"Enter the element you wish to search for"<<endl;
cin>>n;
int index;
if (search(arr,n,s)!=-1){
    cout<<"Deleting the found element..."<<endl;
    index=search(arr,n,s);
   
{for(int i=index;i<s-1;i++){
    arr[i]=arr[i+1];
}}
s=s-1;
cout<<"Printing the array..."<<endl;
for (int i=0;i<s;i++){
    cout<<arr[i]<<endl;
}
}
else cout<<"Element not found.";



        return 0;
 }