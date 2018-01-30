#include<stdio.h>
#include<math.h>
#define f(x) ((x*x*x)-(9*x)+(1))
#define F(x) (3*(x*x)-9)
//#define x0 3

double tolerance = 0.0001;  //predefined
double lastGuess;    //-INF

double findFirstGuess(){
    float a=5, b=10;    //change values of a and b to get a manual range
    while(f(a)*f(b) > 0){
        a-=0.5;
        b+=0.5;
    }
    printf("a=%f b=%f \n", a,b);

    return a;

    //return 3;
}

float findRoot(double currentGuess){
    double newGuess,root;

    double temp = f(currentGuess)/F(currentGuess);
    while(fabs(temp)>=tolerance){ //&& fabs(currentGuess-lastGuess <= tolerance )){
        temp = f(currentGuess)/F(currentGuess);
        lastGuess = currentGuess;

        currentGuess = currentGuess-temp;

       // root = findRoot(newGuess);
    }
    root = currentGuess;

    printf("The Root is = %f and f(%f) = %f \n", root, root, f(root));
}

int main(){
    int p;
    double currentGuess, root;
    scanf("%f", &tolerance);
    currentGuess = findFirstGuess();
    findRoot(currentGuess);


    return 0;
}
