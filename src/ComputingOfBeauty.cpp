#include "../include/ComputingOfBeauty.hpp"

ComputingOfBeauty::ComputingOfBeauty(int base, int num_len){
    if (base >= 2){
        this->f_base = base;
    }
    
    if (num_len >= 1){
        this->f_num_len = num_len;
    }
    
}

ComputingOfBeauty::~ComputingOfBeauty(){

}


int ComputingOfBeauty::sum_of_digits(unsigned int val){
    int sum{0};
    int base{this->get_base()};

    while (val!=0){
        sum+=val%base;
        val=val/base;
    }

    return sum;
}

unsigned long int ComputingOfBeauty::count_num_of_beauties(){
    unsigned long int count{0};
    int base{this->get_base()};
    int num_len{this->get_num_len()};

    unordered_map<int,int> counts_of_sums;

    for (auto i{0}; i < pow(base,(num_len/2)); ++i){
        auto sum = this->sum_of_digits(i);
        ++counts_of_sums[sum];
    }
    cout << "Sum" << "\t" << "Count" << endl;
    for (const auto& [sum, sc] : counts_of_sums){
        cout << sum << "\t" << sc << endl;
        count+=pow(sc,2);
    }

    if (num_len%2!=0){
        count*=base;
    }

    return count;
}

int ComputingOfBeauty::get_base(){
    return this->f_base;
}

int ComputingOfBeauty::get_num_len(){
    return this->f_num_len;
}