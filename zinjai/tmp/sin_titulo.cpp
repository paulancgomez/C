#include <stdio.h>
#include <math.h>
using namespace std;

int main(int argc, char *argv[]) {
	int v[5]={2,3,13,18};
	int e=0;
	int i=0, j=0;
	int N=4;
	while(i<=N){	
		if(v[i]<pow(10,e)){
			for(j=i;j<=N-1;j++){
				v[j]=v[j+1];
			}
			N=N-1;
		}
		else{
			e=e+1;
		    i=i+1;
		}
	}
	for(i=1;i<=N;i++){
		printf("Muestra: %d", v[i]);
	}
	return 0;
}

