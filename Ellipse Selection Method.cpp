#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<math.h>
using namespace std;

int value[100]={0};//the applicants' value

int main(){
	//10000 times' version
	//make random array(no repeat)
	double total=0;
	srand(time(NULL));
	double ttl=0;
	for(int k=1;k<=100;k++){
		total=0;
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
			//ellipse selection method
			//function:x^2/10000+y^2/k^2=1
			int cnt1=0,cnt2=0;
			for(int i=0;i<100;i++){
				double y=sqrt((double)(k*k)*(double)(10000-(double)(i*i))/10000);
				if((double)(value[i])>y){
					cnt1++;
					if(value[i]>50) cnt2++;
					if(cnt1==50) break;
				}
			}
			total+=cnt2;
		}	
		ttl+=total/10000;
		cout<<"When y="<<k<<", the result of ellipse selection method is "<<total/10000<<endl;
	}
	cout<<"The average is "<<ttl/100<<endl;
	return 0;
}
