/*
abhishek madhu
*/

#include <stdio.h>

double f(double x){
    return ( (x*x*x) - (3*x) + (1.06) );
}

int main(){
    double c,a,b,ans,approx,k;
    int flag=0;
    char choice = 'N';
    approx=0.000010;
    a=0.0;
    b=1.0;
    
    printf("Enter the approximation range you wish to attain:\t");
    scanf("%f", &approx);
    
    printf("Want to provide custom interval?(Y/N):\t");
    fflush(stdin);
    scanf("%c", &choice);
    
    if(choice=='Y' || choice=='y'){
    	printf("Enter the value of a and b separated by a space:\t");
    	fflush(stdin);
    	scanf("%f%f", &a,&b);
	}
	else{
		printf("Set to defaults ( a=0 | b=1 )\n");
		a=0.0;
		b=1.0;
	}
    do{
        c=(a+b)/2;
        k=f(c);
        printf("c=%f\n", c);//
        
        if(k==0){
            ans=c;
            flag=1;
            break;
        }
        else if(fabs(k) <= approx){
        	printf("%f is an approximate root with range +-%f\n", c,approx);
        	printf("The value of f(x) for this root is %f.\n", k);
        	return 0;
		}
        else{
            if(k>0){
                a=c;
            }
            else{
                b=c;
            }
        }
    }while(fabs(k) > approx && a<b);

    if(flag){
        printf("Root is %f.\n", ans);
    }
    else{
        printf("Root Not Found in the given approximation.\n");
        printf("Last value of f(c) = %f | c=%f | a=%f | b=%f |\n", k,c,a,b);
    }

    return 0;
}
