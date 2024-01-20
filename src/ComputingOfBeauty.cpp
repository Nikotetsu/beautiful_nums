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
    unsigned int num_len{this->get_num_len()};

    for(auto d{0}; d<num_len; ++d){
        sum+=val%base;
        val=val/base;
    }

    return sum;
}

unsigned long long ComputingOfBeauty::count_num_of_beauties(){
    unsigned long long count{0};
    unsigned int base{this->get_base()};
    unsigned int num_len{this->get_num_len()};

    unordered_map<unsigned long,unsigned long> counts_of_sums;

    //count variants of sums of digits for half of number`s notation
    for (auto i{pow(base,5)}; i < pow(base,(num_len/2)); i++){
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

void ComputingOfBeauty::count_num_of_beauties_2(unsigned int base, unsigned int num_len){
    vector<unsigned int> val;
    unsigned int t{0};

    for(unsigned int i{0}; i<pow(base,num_len); ++i){
        val.erase(val.cbegin(), val.cend());
        t = i;

        for(auto d{0}; d<num_len; ++d){
            if(t==0){
                val.emplace(val.cbegin(),0);
            }
            else{
                val.emplace(val.cbegin(),t%base);
                t/=base;
            }/*if else*/
        }/*for d*/

        for(unsigned int dig : val){
            cout << dig;
        }/*for dig*/

        cout<<"\ni="<<i<<endl;
    }/*for i*/
    
}/*void*/

