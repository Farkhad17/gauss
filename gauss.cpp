#include <iostream>
#include <math.h>

double gauss(double k2, double ki, double ke);
double my_integral(double k2, double kl, double k0);

int main(int argc, char* argv[]){

    double k2, k1, k0, inter;

    try{
        k2 = std::stod(argv[1]);
        k1 = std::stod(argv[2]);
        k0 = std::stod(argv[3]);
    }
    catch(...){
        std::cout << "Not able to parse arguments" << std::endl;
    }
    if(argc < 4)return 1;

    inter = gauss(k2, k1, k0);

    std::cout << inter - my_integral(k2, k1, k0) << std::endl;
    return 0;
}

double gauss(double k2, double k1, double k0){
    double x1, x2, fx1, fx2, c1, c2;

    x1 = sqrt(3.0/5.0);
    x2 = -sqrt(3.0/5.0);

    fx1 = k2*x1*x1 + k1*x1 + k0;
    fx2 = k2*x2*x2 + k1*x2 + k0;

    c1 = 1.0/3.0;
    c2 = 1.0/3.0;

    return c1*fx1 + c2*fx2;
}

double my_integral(double k2, double kl, double k0){
    return 0.4*k2 + (2.0/3.0)*k0;
}
