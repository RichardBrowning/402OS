#ifndef DOUBLE_T_A_H
#define DOUBLE_T_A_H

class doubleTypeArray
{
    private:
        double *a;
        int size;
    public:
        doubleTypeArray(int size);
        ~doubleTypeArray();
        double& operator[](int i);
        doubleTypeArray& operator=(const doubleTypeArray& rhs);
        doubleTypeArray(const doubleTypeArray& rhs);
};

#endif