#ifndef __VAR__
#define __VAR__



union number{
    int Int;
    float Float;
    short int Short;
    long int Long;
    double Double;
}

union carac{
    char Char;
    char* String;
}

union var{
    union number Number;
    union carac Text;
};





#endif