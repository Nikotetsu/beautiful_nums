#ifndef COMPUTING_OF_BEAUTY
#define COMPUTING_OF_BEAUTY

#include "main.hpp"

class ComputingOfBeauty{
    private:
        int f_base{2};
        int f_num_len{1};

    public:
        ComputingOfBeauty(int base, int num_len);
        ~ComputingOfBeauty();

        int sum_of_digits(unsigned int val);
        unsigned long int count_num_of_beauties();
        int get_base();
        int get_num_len();
};


#endif