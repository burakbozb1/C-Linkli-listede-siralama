#include <stdio.h>
#include <string.h>



struct OGRENCI{
	int id;
	char ad[10];
	int yas;
	int ort;
};

void nota_gore_sirala(struct OGRENCI* , int);
void ada_gore_sirala(struct OGRENCI*, int);
void liste_yaz(struct OGRENCI*,int);


int main (){
	struct OGRENCI *ogrList;
	int n,i;
	
	printf("***Yapisal programlama 1. vize 2. soru | 18011706 Burak Boz***\n\n");
	
	printf("N Sayisini Giriniz\n");
	scanf("%d",&n);
	
	ogrList = (struct OGRENCI *)malloc(n*sizeof(struct OGRENCI));
	for(i=0;i<n;i++){
		printf("%d. ogrencinin id sini giriniz.\n",i+1);
		scanf("%d",&ogrList[i].id);
		printf("%d. ogrencinin adini giriniz.\n",i+1);
		scanf("%s",ogrList[i].ad);
		printf("%d. ogrencinin yasini giriniz.\n",i+1);
		scanf("%d",&ogrList[i].yas);
		printf("%d. ogrencinin ortalamasini giriniz.\n",i+1);
		scanf("%d",&ogrList[i].ort);
	}
	
	printf("Dizinin ilk hali \n");
	liste_yaz(ogrList,n);
	nota_gore_sirala(ogrList,n);
	printf("Nota gore siralanmis hali\n");
	liste_yaz(ogrList,n);
	ada_gore_sirala(ogrList,n);
	printf("Ada gore siralanmis hali \n");
	liste_yaz(ogrList,n);
	printf("\n\nListenin son hali\n");
	liste_yaz(ogrList,n);
	
	free(ogrList);
	return 0;
}

void nota_gore_sirala(struct OGRENCI *ogrList, int n ){
	int i,j;
	struct OGRENCI *tmp;
	tmp = (struct OGRENCI *)malloc(sizeof(struct OGRENCI));
	for (i = 0; i<n ; i++){
		for(j = i; j<n ; j++){
			if(ogrList[i].ort>ogrList[j].ort){
				*tmp = ogrList[i];
				ogrList[i] = ogrList[j];
				ogrList[j] = *tmp;
			}
		}
	}
	free(tmp);
}

void ada_gore_sirala(struct OGRENCI *ogrList, int n){
	int i,j;
	struct OGRENCI *tmp;
	tmp = (struct OGRENCI *)malloc(sizeof(struct OGRENCI));
	for (i = 0; i<n ; i++){
		for(j = i; j<n ; j++){
			if(strcmp(ogrList[i].ad,ogrList[j].ad) > 0){
				*tmp = ogrList[i];
				ogrList[i] = ogrList[j];
				ogrList[j] = *tmp;
			}
		}
	}
	free(tmp);
}

void liste_yaz(struct OGRENCI *ogrList,int n){
	int i;
	char id[3] = "ID", ad[3] = "AD", yas[4] = "YAS", ort[9] = "ORTALAMA";
	printf("%5s %5s %5s %5s\n",id,ad,yas,ort);
	for(i=0;i<n;i++){
		printf("%5d %5s %5d %5d\n",ogrList[i].id,ogrList[i].ad,ogrList[i].yas,ogrList[i].ort);
	}
}



