#include <stdio.h>
int main(void){
    double x,y,z;
    printf("Enter two real numbers.\n");
    scanf("%lf %lf",&x,&y);
    z = x + y;
    printf("The sum of %lf + %lf is %lf.\n",x,y,z);
    printf("The product of %lf x %lf is %lf.\n",x,y,x*y);
    printf("x is %5.3lf, y is %8.2lf",x,y);



    return 0;
}
