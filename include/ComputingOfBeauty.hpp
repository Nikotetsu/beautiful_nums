#ifndef COMPUTING_OF_BEAUTY
#define COMPUTING_OF_BEAUTY

#include "main.hpp"

class ComputingOfBeauty{
    private:
        unsigned int f_base{2};
        unsigned int f_num_len{1};

    public:
        ComputingOfBeauty(unsigned int base, unsigned int num_len);
        ~ComputingOfBeauty();

        unsigned int sum_of_digits(unsigned int val);
        unsigned long long count_num_of_beauties();
        unsigned int get_base();
        unsigned int get_num_len();

        static void count_num_of_beauties_2(unsigned int base, unsigned int num_len);        
};


#endif