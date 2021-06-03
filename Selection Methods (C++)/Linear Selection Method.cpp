#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

int value[100]={0};//the applicants' value

int main(){
	//10000 times' version
	//make random array(no repeat)
	double total=0;
	srand(time(NULL));
	for(int n=0;n<10000;n++){
		for(int i=0;i<100;i++){
    		value[i]=0;//reset the array
    	}
    	for(int i=0;i<100;i++){
    		while(1){
    			int flag=0;
    			int x=rand()%100+1;
    			for(int j=0;j<i;j++){
    				if(value[j]==x){//repeat examination
    					flag=1;
    					break;
					}
				}
				if(flag==0){
					value[i]=x;
					break;
				}
			}
		}
		//linear selection method
		int cnt1=0,cnt2=0;
		int start=value[0];
		int end=0;
		double m=((double)(start)-(double)(end))/100;
		for(int i=0;i<100;i++){
			if((double)(start)-m*(double)(i)<(double)(value[i])){
				cnt1++;
				if(value[i]>50) cnt2++;
				if(cnt1==50) break;
			}
		}
		total+=(double)(cnt2);
	}
	cout<<"The result of linear selection method is "<<total/10000<<endl;
	return 0;
}

