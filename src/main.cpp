#include "../include/main.hpp"


int main(int argc, char* argv[]){
    
    int base{13};       //base of numbers
    int num_len{13};    //length of each number
    cout<<"Base of nums: "<< base << "\nLength of nums: "<<num_len<<endl;
    ComputingOfBeauty counter(base,num_len); //create an object of computing class
    unsigned long long rez = counter.count_num_of_beauties(); //count of beautiful numbers
    cout<<"\nAmount of beautiful numbers is "<< rez << endl;
    
    
    //system("Pause");
    return 0;
}