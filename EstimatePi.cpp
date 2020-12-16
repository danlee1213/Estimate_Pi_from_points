#include <iostream>
#include <cstdlib>
#include <cmath>

/**************************************************************************
 * Project to estimate pi from no. of points in and outside of the circle*
 * Referenced by 
 **************************************************************************/

//Generate random float number between 0 ~ 1 (python random.uniform)
long double randomUniform(float a, float b){
    float random = ((float)rand()) / (float)RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}

int main(){
   
    int n = 0;
    float x = 0.0;
    float y = 0.0;
    long double result = 0.0;
    long double distance = 0.0;

    long double num_point_circle = 0.0;
    long double num_point_total = 0.0;
    std::cout<<"Enter the number of points: ";
    std::cin>>n;

    for(int i=0; i<n; ++i){
        x = randomUniform(0.0, 1.0);
        y = randomUniform(0.0, 1.0);
        //Distance between two points = sqrt(x^2 + y^2)
        distance = sqrt(pow(x,2) + pow(y,2));

        if(distance <= 1){
            num_point_circle ++;
        }
        num_point_total ++;   
    }

    result = 4 * (num_point_circle/num_point_total);
    std::cout << "Estimate Pi is: " << result << std::endl;

    return 0;
}