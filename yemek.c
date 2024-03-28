#include <stdio.h>
#include <stdlib.h>
#include <string.h>

	struct  Yemekbilgi{
		char yemekad[20];
		int yemekgramaj;
		float yemekfiyat;
		struct Yemekbilgi *next;
	};
	
	struct Yemekbilgi *head=NULL;
	struct Yemekbilgi *tail=NULL;
	
	void Yemekekle(){	
	printf("\nsirasiyla yemek adi , gramaji ve fiyatini giriniz\n");	
	struct Yemekbilgi *yemek=(struct Yemekbilgi*) malloc(sizeof (struct Yemekbilgi));
	
	if(head==NULL){//if list is empty
			scanf("%s%d%f",&yemek->yemekad,&yemek->yemekgramaj,&yemek->yemekfiyat);
			head=tail=yemek;
			tail->next=head;
			head->next=tail;}	
	else{
			struct Yemekbilgi *yemek=(struct Yemekbilgi*) malloc(sizeof (struct Yemekbilgi));
			scanf("%s%d%f",&yemek->yemekad,&yemek->yemekgramaj,&yemek->yemekfiyat);
			if(head==tail){//if list has a element
				if(head->yemekfiyat>=yemek->yemekfiyat){//if the head more expensive than new element
					head=yemek;	
					head->next=tail;
					tail->next=yemek;
				}				
				
				else{									//if the head cheaper than new element
					head->next=	yemek;
					tail=yemek;
					tail->next=head;
				}	
			}
			
			else{//if list has multiple elements
				struct Yemekbilgi *temp=head;
				temp=temp->next;
					if(yemek->yemekfiyat<head->yemekfiyat){//if new element's price is less than head
						yemek->next=head;
						head=yemek;
						tail->next=head;
					}
					else if(tail->yemekfiyat<=yemek->yemekfiyat){
						tail->next=yemek;
						tail=yemek;
						tail->next=head;
					}
					
					else{//if new element's price is more than temp
						struct Yemekbilgi *previous=head;
						while(1){
							if(yemek->yemekfiyat>temp->yemekfiyat){//if the new element price more than temp
							previous=previous->next;
							temp=temp->next;
							
							}
							else{									//if the new element price less than temp
								previous->next=yemek;
								yemek->next=temp;
								break;
						}
					}
				}
			}
		}
	}
	
					
	void textYemekekle(){
		FILE *filep =fopen("yemek.txt","r"); 
		while(!feof(filep)){
			struct Yemekbilgi *	yemek=(struct Yemekbilgi*)malloc(sizeof(struct Yemekbilgi));
			fscanf(filep,"%s%d%f",&yemek->yemekad,&yemek->yemekgramaj,&yemek->yemekfiyat);
		
			if(head==NULL){//if list is empty
			head=tail=yemek;
			tail->next=head;
			head->next=tail;	
		}
		else{
			if(head==tail){//if list has a element
				if(head->yemekfiyat>=yemek->yemekfiyat){//if the head more expensive than new element
					head=yemek;	
					head->next=tail;
					tail->next=yemek;
				}
				else{									//if the head cheaper than new element
					head->next=	yemek;
					tail=yemek;
					tail->next=head;
					}	
				}
			
			else{//if list has multiple elements
					if(yemek->yemekfiyat<head->yemekfiyat){//if new element's price is less than head
						yemek->next=head;
						head=yemek;
						tail->next=head;
					}
					else if(tail->yemekfiyat<=yemek->yemekfiyat){
						tail->next=yemek;
						tail=yemek;
						tail->next=head;
					}
					
					else{//if new element's price is more than temp
						struct Yemekbilgi *temp=head;
						struct Yemekbilgi *previous=temp;
						temp=temp->next;
						while(1){
							if(yemek->yemekfiyat>temp->yemekfiyat){//if the new element price more than temp
							previous=previous->next;
							temp=temp->next;
							}
							else{									//if the new element price less than temp
								previous->next=yemek;
								yemek->next=temp;
								break;
							}
						}
					}
				}
			}
		}
	}						
			
	
	void Listele(){
		if(tail==NULL){
			printf("\nkayiitli yemek bulunamadi		");
		}
		else{
			struct Yemekbilgi *temp=head;
			while(1){
				printf("\n%s	%d	%f",temp->yemekad,temp->yemekgramaj,temp->yemekfiyat);
				if(temp==tail)break;	
				else temp=temp->next;
					}
				}
			}


	void Sec(){
		struct Yemekbilgi *temp=tail;
		printf("\nsecmek istediginiz yemegi secmek icin 'e' , ilerlemek icin 'h' , ana menuye donmek icin 'a' giriniz ");
		char control='h';
		int i=0;	
		while(control=='h'){
			temp=temp->next;
			printf("\n%s	%d	%f		(e / h / a):	",temp->yemekad,temp->yemekgramaj,temp->yemekfiyat);
			scanf("%s",&control);
			switch(control){
			case 'a':break;
				
			case 'e':{
				printf("\n %s yemegini sectiniz , yemeginiz en kisa surede teslim edilecektir.		",temp->yemekad);
				break;
			}
			
			case 'h':{
				break;
			}
			default:{
			printf("\nyanlis giris yaptiniz		");
			break;
				}
			}
		}		
	}	
	
	
	void Sil(){
		printf("\nsilmek istediginiz yemegi giriniz		");
		char silinecek[20];
		scanf("%s",&silinecek);
		int keluzun;
		keluzun=strlen(silinecek);
		struct Yemekbilgi *temp=head;
		struct Yemekbilgi *previous=head;
		struct Yemekbilgi *temp1=head;
		int i=0;
		int control=0;
		
			for(temp1;temp1=tail;temp1=temp1->next)					{
				for(i=0;i<keluzun;i++){
					if(silinecek[i]==temp->yemekad[i]){
						control++;		//printf("control=%d	i=%d	keluzun=%d",control,i,keluzun);
						if(control==keluzun)break;
					}	
						
					else {
						control=0;
						previous=temp;
						temp=temp->next;
						break;
					}
													}
				if(temp==head)		break;
				if(control==keluzun)break;
																}
		if(control!=keluzun){
			printf("\nyanlis yemekadi girdiniz	control=%d		i=%d	temp=%s",control,i,temp->yemekad);
		}
		else{
			if(temp==head){//elimizdeki temp silinecek olan			previous ise tempten bir önceki
				head=temp->next;
				tail->next=head;
				printf("\n%s yemegi basariyla silinmistir	",temp->yemekad);
				free(temp);
				
			}
			else if(temp==tail){
				previous->next=head;
				tail=previous;
				tail->next=head;
				printf("\n%s yemegi basariyla silinmistir	",temp->yemekad);
				free(temp);
				
			}
			else{//ortadaysa
				previous->next=temp->next;
				printf("\n%s yemegi basariyla silinmistir	",temp->yemekad);
				free(temp);}
				}
			}

int main(int argc, char *argv[]) {
	char islem;
	
	printf("\ncikmak icin c / yemek eklemek icin p  /yemegi texten ekmek icin t		GIRINIZ\nlistelemek icin l /yemek secimi icin e /yemek silmik icin s			GIRINIZ ");
	while(islem!='c'){
	scanf("%s",&islem);
	switch(islem){
		
		case 'c':{
			break;
		}
		
		case 's':{
			Sil();
			printf("\n\ncikmak icin c / yemek eklemek icin p  /yemegi texten ekmek icin t		GIRINIZ\nlistelemek icin l /yemek secimi icin e /yemek silmik icin s			GIRINIZ ");
			break;
		}
		
		case 'l':{
			Listele();
			printf("\n\ncikmak icin c / yemek eklemek icin p  /yemegi texten ekmek icin t		GIRINIZ\nlistelemek icin l /yemek secimi icin e /yemek silmik icin s			GIRINIZ ");
			break;
		}
		
		case'e':{
			Sec();
			printf("\n\ncikmak icin c / yemek eklemek icin p  /yemegi texten ekmek icin t		GIRINIZ\nlistelemek icin l /yemek secimi icin e /yemek silmik icin s			GIRINIZ ");
			break;
		}
		
		case 'p':{
			Yemekekle();
			printf("\n\ncikmak icin c / yemek eklemek icin p  /yemegi texten ekmek icin t		GIRINIZ\nlistelemek icin l /yemek secimi icin e /yemek silmik icin s			GIRINIZ ");
			break;
		}
		
		case 't':{
			textYemekekle();
			printf("\n\ncikmak icin c / yemek eklemek icin p  /yemegi texten ekmek icin t		GIRINIZ\nlistelemek icin l /yemek secimi icin e /yemek silmik icin s			GIRINIZ ");
			break;
		}
		
		default:{
			printf("\nyanlis giris yaptiniz(main)");
			printf("\n\ncikmak icin c / yemek eklemek icin p  /yemegi texten ekmek icin t		GIRINIZ\nlistelemek icin l /yemek secimi icin e /yemek silmik icin s			GIRINIZ ");
			}
		}
	}
	
	return 0;
}
