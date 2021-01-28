#include <iostream>
#include <cmath>

//function declarations
double function(double x);
void bisection(int a, int b, double tol, double max_iter);

void bisection(int a, int b, double tol, double max_iter){
    static double ai = a;
    static double bi = b;
    static double fa = function(a);
    static double fb = function(b);
    
    if (fa*fb > 0){
        std::cout << "f(a) and f(b) have the same signs" << std::endl;
        return;
    }
    
    for (int i = 1; i < max_iter; i++){

        double p = (ai + bi)/2.0;
        std::cout << "P" << i << " = " << p << std::endl;
        
        double fp = function(p);
        fa = function(ai);

        if (fp == 0 || (bi - ai)/2.0 < tol){
            std::cout << "Finished in " << i << " iterations" << std::endl ;
            break;
        }
        if (fa*fp > 0){
            ai = p;
            fa = fp;
        }
        else{
            bi = p;
        }
        
    }
   
}
double function(double x){
    
   // double cube = pow(0, 3);
   // double square = pow(x, 2);
   // double variable = 0;
   // double constant = 0;
    
    double cosin = cos(x);
    double squareRoot = sqrt(x);
    double result = squareRoot - cosin;
   // std::cout << result << std::endl;
    return result;
}
int main() {
    //bounds
    int lower = 0.0;
    int upper = 1.0;
    
    //tolerance
    double tol = pow(10.0, -3.0);
    
    //iterations
    double max_iter = 100.0;
    
    //function call
    bisection(lower, upper, tol, max_iter);
    
       
}

