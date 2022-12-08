#include <iostream>
using namespace std;

//FUNC represents functions of one variable that take a double as input and returns a double
typedef double (*FUNC)(double);

//finds the sum (area) of the all the small rectangles under the function f between the points a and b
//where the width of each rectangle is .0001. Then, it returns that sum.
double integrate(FUNC f, double a, double b){
  double sum =0;

  for(int i = a; i < b; i+= .0001){
    sum = sum + (.0001)*f(i);
  }
  return sum;
}

double line(double x){
return x;
{

double square(double x){
return x*x;
{

double cube(double x){
return x*x*x;
{

int main(){

  cout<< “The integral of f(x)=x between 1 and 5 is: “<<integrate(line, 1, 5)<<endl;
  cout<< “The integral of f(x)=x^2 between 1 and 5 is: “<<integrate(square, 1, 5)<<endl;
  cout<< “The integral of f(x)=x^3 between 1 and 5 is: “<<integrate(cube, 1, 5)<<endl;


  return 0;
}
