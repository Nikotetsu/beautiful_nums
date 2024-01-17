#include "../include/ComputingOfBeauty.hpp"

ComputingOfBeauty::ComputingOfBeauty(unsigned int base, unsigned int num_len){
    
    //check restrictions, else still it stay default
    if (base >= 2){
        this->f_base = base;
    }
    
    if (num_len >= 1){
        this->f_num_len = num_len;
    }
    
}

ComputingOfBeauty::~ComputingOfBeauty(){

}


unsigned int ComputingOfBeauty::sum_of_digits(unsigned int val){
    unsigned int sum{0};
    unsigned int base{this->get_base()};

    while (val>0){
        sum+=val%base;
        val=val/base;
    }
    
    return sum;
}

unsigned long long ComputingOfBeauty::count_num_of_beauties(){
    unsigned long long count{0};
    unsigned int base{this->get_base()};
    unsigned int num_len{this->get_num_len()};

    unordered_map<unsigned int,unsigned int> counts_of_sums;

    //count variants of sums of digits for half of number`s notation
    for (auto i{0}; i < pow(base,(num_len/2)); i++){
        auto sum = this->sum_of_digits(i);
        ++counts_of_sums[sum];
    }
    
    //combine all "beautiful" variants
    cout << "Sum" << "\t" << "Count" << endl;
    for (const auto& [sum, sc] : counts_of_sums){
        cout << sum << "\t" << sc << endl;
        count+=pow(sc,2);
    }

    //if length of number is odd, have extra variants
    if (num_len%2!=0){
        count*=base;
    }

    return count;
}

unsigned int ComputingOfBeauty::get_base(){
    return this->f_base;
}

unsigned int ComputingOfBeauty::get_num_len(){
    return this->f_num_len;
}