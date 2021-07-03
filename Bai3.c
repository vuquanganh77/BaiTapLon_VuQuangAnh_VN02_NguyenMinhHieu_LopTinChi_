#include<stdio.h>
#include<string.h>
#include"student.h"

void hienthiTTSV(struct SinhVien sv){
	printf("%-10s %-10s %-10s %-10f\n",sv.hoVaTen.ho, sv.hoVaTen.dem, sv.hoVaTen.ten, sv.diem);
}


void hienthiDSSV(struct SinhVien *ds, int slsv){
	int i;
	printf("-------------------------------------------\n");
	printf("%-10s %-10s %-10s %-10s\n","Ho", "Dem", "Ten", "Diem");
	for(i=0; i<slsv; i++){
		hienthiTTSV(ds[i]);
	}
	
}

void timtheoten(struct SinhVien *ds, int slsv){
	FILE *output_file = fopen("output.txt", "w");
	char ten[20];
	int i, timsv=0;
	printf("Nhap ten:\n");
	scanf("%s",ten);
	printf("----------------------------------------------------------------\n");
	printf("%-10s %-10s %-10s %-10s\n","Ho", "Dem", "Ten", "Diem");
	for(i=0; i<slsv; i++){
		if(strcmp(ten,ds[i].hoVaTen.ten)==0){
			hienthiTTSV(ds[i]);
			fprintf(output_file,"%-10s %-10s %-10s %-10s\n","Ho", "Dem", "Ten", "Diem" );
			fprintf(output_file,"%-10s %-10s %-10s %-10f",ds[i].hoVaTen.ho, ds[i].hoVaTen.dem, ds[i].hoVaTen.ten, ds[i].diem);
			timsv = 1;
		}
	}
	if(timsv == 0){
		printf("Khong tim duoc sinh vien %s !",ten);
	}
	fclose(output_file);
}


void readfile(struct SinhVien *ds, int *slsv){
	FILE *input_file = fopen("SV2021.dat","r");
	int i=0;
	for(;;){
		struct SinhVien sv;
		fscanf(input_file, "%10s %10s %10s %10f ", sv.hoVaTen.ho, sv.hoVaTen.dem, sv.hoVaTen.ten, &sv.diem);
		ds[i++]=sv;
		if(feof(input_file)){
			break;
		}
	}
	
	fclose(input_file);
	*slsv = i;
}

struct SinhVien nhapSV(){
	
	struct SinhVien sv;
	printf("Nhap ho:\n");
	scanf("%s",&sv.hoVaTen.ho);
	printf("Nhap dem:\n");
	scanf("%s",&sv.hoVaTen.dem);
	printf("Nhap ten:\n");
	scanf("%s",&sv.hoVaTen.ten);
	printf("Nhap diem:\n");
	scanf("%f",&sv.diem);
	
	return sv;
}

int main(){
	int key;
	struct SinhVien dssv[100];
	int slsv = 0;
	
	readfile(dssv,&slsv);
	
	struct SinhVien sv;
	do{
	printf("\tChuong trinh quan ly sinh vien\n");
	printf("      _________________________________\n");
	printf("1.Xem danh sach sinh vien\n");
	printf("2.Nhap them sinh vien\n");
	printf("3.Tim sinh vien theo ten\n");
	printf("4.Thoat\n");
	scanf("%d",&key);
	
	switch(key){
		case 1:
			printf("Ban da chon xem danh sach sinh vien!\n");
			hienthiDSSV(dssv,slsv);
			break;
			
		case 2:
			printf("Ban da chon nhap them sinh vien!\n");
			sv = nhapSV();
			dssv[slsv++] = sv;
			FILE *input = fopen("SV2021.dat","a");
			fprintf(input, "\n%s %s %s %f ", sv.hoVaTen.ho, sv.hoVaTen.dem, sv.hoVaTen.ten, sv.diem);
			fclose(input);
			break;
		case 3:
			printf("Ban da chon tim sinh vien theo ten!\n");
			timtheoten(dssv,slsv);
			break;
		case 4:
			printf("Ban da thoat chuong trinh\n");
			break;
		default:
			printf("Sai chuc nang, vui long chon lai!\n");
			break;
		}
	}
	while(key!=4);
	
	
	return 0;
}
