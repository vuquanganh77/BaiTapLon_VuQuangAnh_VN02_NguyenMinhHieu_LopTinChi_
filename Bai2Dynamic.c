#include<stdio.h>

struct Object{
	char name[10];
	int weight, value, quantity;
};

struct State{
	int value;
	int quantity[1000];
};


struct State pick(struct Object obj[], int n, int c, int position){
	struct State base_state;
	base_state.value=0;
	int i;
	for(i=0; i<1000; i++) base_state.quantity[i]=0;
	
	if (c == 0 || position == n) return base_state;
	if (obj[position].weight > c) return pick(obj, n, c, position+1) ;
	
	struct State state1 = pick(obj, n, c, position+1) ;
	struct State state2 = pick(obj, n, c-obj[position].weight, position);
	
	state2.value += obj[position].value;
	state2.quantity[position] += 1;
	
	if(state1.value > state2.value) {
		return state1;
	} else {
		return state2;
	}
}


int main(){
	int n, W;
	FILE *input_file = fopen("BAG.INP","r");
	int i;
	fscanf(input_file, "%d %d", &n, &W);
	struct Object obj[n];
	
	while(fscanf(input_file,"%s %d %d", &obj[i].name, &obj[i].weight, &obj[i].value) != EOF && i<n){
		i++;
	}
	struct State final_result = pick(obj, n, W, 0);

	printf("value max : %d \n", final_result.value);
	for (i = 0; i < n; i++) {
		printf("%s : %d \n", obj[i].name, final_result.quantity[i]);
	}
	
	fclose(input_file);
	return 0;
}
