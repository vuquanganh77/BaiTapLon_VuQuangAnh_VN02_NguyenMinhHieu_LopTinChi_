#include<stdio.h>

struct Object {
	char name[10];
	int weight, value, quantity;
};

void swap(struct Object obj[], int x, int y) {
	struct Object c = obj[x];
	obj[x] = obj[y];
	obj[y] = c;
}

float value_per_weight (struct Object obj) {
	return obj.value/(float)(obj.weight);
}

void sort(struct Object obj[], int N) {
	int i, j;
	for (i = 0; i < N-1; i++)    
	    for (j = 0; j < N-i-1; j++)
	        if (value_per_weight(obj[j]) < (value_per_weight(obj[j+1])))
	            swap(obj, j, j+1);
}

void pick(struct Object obj[], int N, int max_weight) {
	int i, current_weight = 0;
	int max_value = 0;
	sort(obj, N);
	for (i = 0; i < N; i ++) {
		if (current_weight >= max_weight) break;
		int quantity = (max_weight - current_weight) / obj[i].weight;
		
		obj[i].quantity = quantity;
		current_weight += quantity * obj[i].weight;
	}
	
	for(i=0; i<N; i++){
		max_value += obj[i].quantity*obj[i].value;
		printf("%s : %d \n", obj[i].name, obj[i].quantity);
	}
	
	printf("%d\n",max_value);
	
}


int main() {
	int N, W;
	FILE *input_file = fopen("BAG.INP","r");
	int i;
	fscanf(input_file, "%d %d", &N, &W);
	struct Object obj[N];
	
	while(fscanf(input_file,"%s %d %d", &obj[i].name, &obj[i].weight, &obj[i].value) != EOF && i<N){
		i++;
	}
	
	pick(obj, N, W);
	
	fclose(input_file);
	

	return 0;
}
