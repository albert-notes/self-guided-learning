#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<vector>
#include<algorithm>
using namespace std;

int value[100]={0};//the applicants' value

int main(){
	//10000 times' version
	//make random array(no repeat)
	srand(time(NULL));
	for(int m=1;m<=100;m++){
		double total=0;
		vector<int>v;
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
			//median selection method
			int cnt1=0,cnt2=0;
			//Use the first m numbers to calculate the median
			double medium;
			for(int i=0;i<m;i++){
				v.push_back(value[i]);
			}
			sort(v.begin(),v.end());
			if(v.size()%2==1){
				medium=(double)(v[v.size()/2]);
			}else{
				medium=((double)(v[v.size()/2])+(double)(v[v.size()/2-1]))/2;	
			}
			for(int i=m;i<100;i++){
				if((double)(value[i])>medium){
					cnt1++;
					if(value[i]>50) cnt2++;
					if(cnt1==50) break;
				}
			}
			total+=cnt2;
			v.clear();
		}
		if(m==1){
			cout<<"When using the first "<<m<<" number to calculate the median, the result is "<<total/10000<<endl;
		}else{
			cout<<"When using the first "<<m<<" numbers to calculate the median, the result is "<<total/10000<<endl;
		}
	}
	return 0;
}

