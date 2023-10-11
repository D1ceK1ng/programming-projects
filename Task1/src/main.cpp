#include <iostream>
#include <math.h>

using namespace std;

void Task11 ()
{
    double a = 3.2;
    double b = 17.5;
    double x = -4.8;

    double y = pow(b,3) * pow(tan(x),2) - (a/pow(sin(x/a),2));
    double z = a * exp(-sqrt(3)) * cos(b * x/a);
    cout <<"Task 1.1:\n"<< "Y = " << y << "\nZ = " << z << endl; 
}
void Task12()
{
  
    const double hx = 0.5;
    const double ha = 1;
    double y;
    cout << "\nTask 1.2:\n";
    for ( double x = 1; x <= 8; x+= hx)
    {
        for(double a = 2; a <= 10; a += ha)
        {
             
            if(a > x)
            {
                y = pow(a,2) + x;             
            }
            else if(a == x)
            {
                y = pow(a,2);          
            }
            else
            {
                y = pow(a,2) - x; 
            }
            cout << "x = "<< x << "\t\ta = "<< a << "\t\ty = " << y << endl;
        }
       
        
    }
    
}

int main(int argc, char *argv[])
{
    Task11();
    Task12();

  

    return 0;
}



