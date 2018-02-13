#include<stdio.h>
#define interval 0.0001
#define f(x) x*x*x
#define a 0
#define b 2


int main(){
    float b1,b2,h,left,right,x;
    float approx, ans;

    printf("Enter the interval range : ");
    scanf("%f", &approx);
	left=a;
	right=a+approx;

	ans=0;
	while(right<b){
		//find area bw b1 and b2
		b1 = f(left);
		b2 = f(right);
		x = (b1+b2)/2;
		ans += approx * x;

		left=right;
		right=right+approx;
	}

	printf("The final area under the curve is : %6.4f", ans);

    return 0;
}
