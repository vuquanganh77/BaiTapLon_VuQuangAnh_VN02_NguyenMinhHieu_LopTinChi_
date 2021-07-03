#include<stdio.h>
#include<stdlib.h>

unsigned long int C(int k, int n){ 
	if (k == 0 || k == n) 
		return 1;
    if (k == 1) 
		return n;
	else
    	return C(k - 1, n - 1) + C(k, n - 1);
}
int main(){
	int n, k;
	FILE *input_file, *output_file;
	input_file = fopen("TOHOP.INP","r");
	output_file = fopen("TOHOP.OUT","w+");
	
	
	if(input_file == NULL || output_file == NULL){
		printf("ERROR!");
		exit(1);
	}
	
	while(fscanf(input_file,"%d %d", &n, &k) != EOF){
		
		fprintf(output_file, "%ull \n", C(k,n));
	}
	fclose(input_file);
	fclose(output_file);
	return 0;
}
