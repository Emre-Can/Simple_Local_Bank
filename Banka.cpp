#include <iostream>
#include <conio.h>
#include <unistd.h>
#include <time.h>
#include <string.h>


int main() {
	
	setlocale(LC_ALL, "Turkish");
	giriskayit:
	long long int tcno=0,ftcno=0,gecicitcno=0,paragontc=0,sifre=0,fsifre=0,bakiye=0,fbakiye=0,karsibakiye=0;
	int gk=0,tcbasamak=0,sifrebasamak=0,eklepara=0,tarihuzunluk=0;
	char ktarih[50],gecicitarih[50];
	time_t tarih=time(0);
	time(&tarih);
	struct tm *tarihzaman=localtime(&tarih);
	//printf("Day: %s",asctime(tarihzaman));
	bool girisdogrulama = false,kayitdogrulama = true,ygiriskontrol = true,paragonkontrol = true,paragonykontrol = true,tarihayni = true;
	FILE *girisbilgi,*girisbilgidegis,*hesapdokumu;
	hesapdokumu=fopen("hesapdokum.txt","a");
	fclose(hesapdokumu);
	girisbilgi=fopen("girisbilgi.txt","a");
	fclose(girisbilgi);
	
	int tc3kerey=0;
	do
	{
	printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-G�R�� YAP\n");
	printf("\t\t\t\t\t\t\t2-KAYIT OL\n\t\t\t\t\t\t\t");
	gk=getch();
	//printf("%d",gk);
	system("CLS");
	}while(gk!='1' && gk!='2');
	switch(gk)
	{
		case '1':
			do
			{
			tc3kerey++;
			if(tc3kerey==4)//3 yanl�� giri�te geri atar.
			{
				goto giriskayit;
			}
			printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tG�R�� YAP\n\t\t\t\t\t\t");
			printf("\n\t\t\t\t\t\tTC Kimlik Numaras� Giriniz\n\t\t\t\t\t\t");
			scanf("%lld",&tcno);
			printf("\n						�ifre\n						");
			scanf("%lld",&sifre);
	
			girisbilgi=fopen("girisbilgi.txt","r");
			if(girisbilgi==0)
			{
 			    girisbilgi=fopen("girisbilgi.txt","w");
			}
			do{								   
 			    fscanf(girisbilgi,"%lld %lld %lld",&ftcno,&fsifre,&fbakiye);
 			    if(ftcno==tcno && fsifre==sifre)
 				{
				    girisdogrulama = true;
				    bakiye=fbakiye;
			        break;
			 	}
			}while(!feof(girisbilgi));
			fclose(girisbilgi);
			system("CLS");
			}while(girisdogrulama!=true);
			break;
			
		case '2':

			do
			{
			long long int i;
			
			tcbasamak=0;
			
			if(kayitdogrulama==true)
			{
			printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tKAYIT OL\n\t\t\t\t\t\t");
			printf("\n\t\t\t\t\t\tTC Kimlik Numaras� Giriniz\n\t\t\t\t\t\t");
			}
			scanf("%lld",&tcno);
			fflush(stdin);
			for(i=tcno;i>0;i/=10)
			{
				tcbasamak++;
			}
			if(i<10 && i>0)
			{
				tcbasamak++;
			}
			if(tcbasamak!=11)
			{
				system("CLS");
			}
			girisbilgi=fopen("girisbilgi.txt","r");
			do{								   
 			    fscanf(girisbilgi,"%lld %lld",&ftcno,&fsifre);
 			    if(ftcno==tcno)
 				{
 					ygiriskontrol = false;//yanlu� giri� olup olmad���na bakar yanl�� giri� varsa a��a��da �ifre yanl�� girildi�inde zaten kullan�l�yor yaz�s� de�i�mez
				    kayitdogrulama = false;
				    system("CLS");
					printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tKAYIT OL");
					printf("\n\n\t\t\t\t    Girdi�iniz TC Kimlik Numaras� Zaten Kullan�l�yor\n\t\t\t\t\t\t");
					break;
			 	}
			 	else
			 	{
			 		kayitdogrulama = true;
	 			}
			}while(!feof(girisbilgi));
			fclose(girisbilgi);
			}while(tcbasamak!=11 || kayitdogrulama == false);
			long long int k;
			do
			{
			printf("\n\t\t\t\t�ifre Belirleyiniz (��FRE EN AZ 6 KARAKTERDEN OLU�MALIDIR)\n\t\t\t\t\t\t");
			scanf("%lld",&sifre);
			for(k=sifre;k>0;k/=10)
			{
				sifrebasamak++;
			}
			if(k<10 && k>0)
			{
				sifrebasamak++;
			}
			if(sifrebasamak<6)
			{
				if(ygiriskontrol==true)
				{
				system("CLS");
				printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tKAYIT OL\n\t\t\t\t\t\t");
				printf("\n\t\t\t\t\t\tTC Kimlik Numaras� Giriniz\n\t\t\t\t\t\t");
				printf("%lld\n",tcno);
				sifrebasamak=0;	
				}
				
				if(ygiriskontrol==false)
				{
				system("CLS");
				printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tKAYIT OL");
				printf("\n\n\t\t\t\t    Girdi�iniz TC Kimlik Numaras� Zaten Kullan�l�yor\n\t\t\t\t\t\t");
				printf("%lld\n",tcno);
				sifrebasamak=0;				
				}
			}
			}while(sifrebasamak<6);
			system("CLS");
			girisbilgi=fopen("girisbilgi.txt","a");
			fprintf(girisbilgi,"%lld %lld 0\n",tcno,sifre);
			fclose(girisbilgi);
			printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tKAYDINIZ BA�ARIYLA YAPILDI");
			sleep(5);
			system("CLS");
			goto giriskayit;
			break;
			
		default:
			break;
	}
	islemtekrar:
	do
	{							   
	printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t��lem Se�iniz\t\t\t\tBakiye : %lld",bakiye);
	printf("\n\n\t\t\t\t\t\t   1-Para Yat�r");
	printf("\n\t\t\t\t\t\t   2-Para �ek");
	printf("\n\t\t\t\t\t\t   3-Para G�nder");
	printf("\n\t\t\t\t\t\t   4-Fatura Yat�r");
	printf("\n\t\t\t\t\t\t   5-Hesap Ge�mi�i");
	printf("\n\t\t\t\t\t\t   0-��k�� Yap\n\t\t\t\t\t\t   ");
	gk=getch();
	system("CLS");
	}while(gk<'0' || gk>'5');
	switch(gk)
	{
		case '0':
			system("CLS");
			goto giriskayit;
		break;
		case '1':
			do
			{
			if(eklepara>1000 || eklepara<0)
			{
			printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tTek Seferde 0TL �le 1000TL Aras�na Yat�rabilirsiniz\tBakiye : %lld\n\t\t\t\t\t",bakiye);
			}
			else
			{
			printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tYat�r�lacak Para Miktar�n� Giriniz\tBakiye : %lld\n\t\t\t\t\t\t",bakiye);	
			}
			scanf("%lld",&eklepara);

			system("CLS");
			}while(eklepara>1000 || eklepara<0);
			bakiye+=eklepara;
	 		girisbilgidegis=fopen("girisbilgidegis.txt","w");
			girisbilgi=fopen("girisbilgi.txt","r");
			while(!feof(girisbilgi))
			{		
 			    fscanf(girisbilgi,"%lld %lld %lld",&ftcno,&fsifre,&fbakiye);

				if(ftcno!=tcno)
				{
					if(gecicitcno==ftcno)
					{
						continue;
					}
					fprintf(girisbilgidegis,"%lld %lld %lld\n",ftcno,fsifre,fbakiye);
				}
				if(ftcno==tcno)
				{
					fprintf(girisbilgidegis,"%lld %lld %lld\n",ftcno,fsifre,bakiye);
				}
				gecicitcno=ftcno;
			}
			
			fclose(girisbilgi);
			fclose(girisbilgidegis);
			remove("girisbilgi.txt");
			rename("girisbilgidegis.txt","girisbilgi.txt");	
			hesapdokumu=fopen("hesapdokum.txt","a");
			fprintf(hesapdokumu,"%lld +%d & %s",tcno,eklepara,asctime(tarihzaman));
			fclose(hesapdokumu);
			eklepara=0;
			gecicitcno=0;
			goto islemtekrar;
			break;
			
		case '2':		

			do
			{
			if(bakiye==0)
			{
				printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tMalesef Bakiyeniz Bulunmamaktad�r");
				sleep(5);
				system("CLS");
				goto islemtekrar;
			}
			if(eklepara>1000 || eklepara<0)
			{
			printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tTek Seferde 0TL �le 1000TL Aras�na Para �ekebilirsiniz\tBakiye : %lld\n\t\t\t\t\t",bakiye);
			}
			else if(eklepara>bakiye)
			{
			printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tTek Seferde 0TL �le %lldTL Aras�na Para �ekebilirsiniz\tBakiye : %lld\n\t\t\t\t\t",bakiye,bakiye);
			}
			else
			{
			printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t�ekmek �stedi�iniz Para Miktar�n� Giriniz\tBakiye : %lld\n\t\t\t\t\t\t",bakiye);	
			}
			scanf("%d",&eklepara);

			system("CLS");
			}while(eklepara>1000 || eklepara<0 || eklepara>bakiye);
			bakiye-=eklepara;
	 		girisbilgidegis=fopen("girisbilgidegis.txt","w");
			girisbilgi=fopen("girisbilgi.txt","r");
			while(!feof(girisbilgi))
			{		
 			    fscanf(girisbilgi,"%lld %lld %lld",&ftcno,&fsifre,&fbakiye);

				if(ftcno!=tcno)
				{
					if(gecicitcno==ftcno)
					{
						continue;
					}
					fprintf(girisbilgidegis,"%lld %lld %lld\n",ftcno,fsifre,fbakiye);
				}
				if(ftcno==tcno)
				{
					fprintf(girisbilgidegis,"%lld %lld %lld\n",ftcno,fsifre,bakiye);
				}
				gecicitcno=ftcno;
			}
			
			fclose(girisbilgi);
			fclose(girisbilgidegis);
			remove("girisbilgi.txt");
			rename("girisbilgidegis.txt","girisbilgi.txt");	
			hesapdokumu=fopen("hesapdokum.txt","a");
			fprintf(hesapdokumu,"%lld -%d & %s",tcno,eklepara,asctime(tarihzaman));
			fclose(hesapdokumu);
			eklepara=0;
			gecicitcno=0;
			goto islemtekrar;
			
			
			
			
			break;
			
		case '3':
			paragonykontrol=true;
			if(bakiye==0)
			{
				printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tMalesef Bakiyeniz Bulunmamaktad�r");
				sleep(5);
				system("CLS");
				goto islemtekrar;
			}
			printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tPara G�ndermek �stedi�iniz TC Numaras�n� Yaz�n�z\tBakiye : %lld\n\t\t\t\t\t",bakiye);
			do
			{
			if(paragonkontrol==false)
			{
				system("CLS");
				printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tGirdi�iniz TC Numaras� Ge�ersiz.\tBakiye : %lld\n\t\t\t\t\tL�tfen Ge�erli Bir TC Numaras� �le Tekrar Deneyiniz\n\t\t\t\t\t",bakiye);
				paragonykontrol = false;
			}
			scanf("%lld",&paragontc);
			
			girisbilgi=fopen("girisbilgi.txt","r");	
			while(!feof(girisbilgi))
			{
 			    fscanf(girisbilgi,"%lld %lld %lld",&ftcno,&fsifre,&fbakiye);
				if(paragontc==ftcno)
				{
					paragonkontrol = true;
					break;
				}
				else
				{
					paragonkontrol = false;
					
				}
			}
			fclose(girisbilgi);
   			}while(paragonkontrol==false);
			do
			{
				
			if(eklepara>bakiye)
			{
			printf("\n\t\t\t\t\tTek Seferde 0TL �le %lldTL Aras�na Para G�nderebilirsiniz\n\t\t\t\t\t",bakiye);
			}
			else if(eklepara>1000 || eklepara<0)
			{
			printf("\n\t\t\t\t\tTek Seferde 0TL �le 1000TL Aras�na Para G�nderebilirsiniz\n\t\t\t\t\t\t");
			}
			else
			{
			printf("\n\t\t\t\t\tG�ndermek �stedi�iniz Para Miktar�n� Giriniz\n\t\t\t\t\t");	
			}
			scanf("%d",&eklepara);

			system("CLS");
			if(eklepara>1000 || eklepara<0 || eklepara>bakiye)
			{
				if(paragonykontrol==true)
				{
				 	printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tPara G�ndermek �stedi�iniz TC Numaras�n� Yaz�n�z\tBakiye : %lld\n\t\t\t\t\t%lld\n",bakiye,paragontc);
				}
				else
				{
					printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tGirdi�iniz TC Numaras� Ge�ersiz.\tBakiye : %lld\n\t\t\t\t\tL�tfen Ge�erli Bir TC Numaras� �le Tekrar Deneyiniz\n\t\t\t\t\t%lld\n",bakiye,paragontc);
				}
			}
			}while(eklepara>1000 || eklepara<0 || eklepara>bakiye);
			bakiye-=eklepara;
	 		girisbilgidegis=fopen("girisbilgidegis.txt","w");
			girisbilgi=fopen("girisbilgi.txt","r");
			gecicitcno=0;
			while(!feof(girisbilgi))
			{		
 			    fscanf(girisbilgi,"%lld %lld %lld",&ftcno,&fsifre,&fbakiye);
				if(ftcno==paragontc && ftcno!=gecicitcno)
				{
					fprintf(girisbilgidegis,"%lld %lld %lld\n",ftcno,fsifre,fbakiye+eklepara);
					gecicitcno=ftcno;
					continue;
				}
				if(ftcno==tcno  && ftcno!=gecicitcno)
				{
					fprintf(girisbilgidegis,"%lld %lld %lld\n",ftcno,fsifre,bakiye);
					gecicitcno=ftcno;
					continue;
				}
				fprintf(girisbilgidegis,"%lld %lld %lld\n",ftcno,fsifre,fbakiye);
				gecicitcno=ftcno;
			}
			
			fclose(girisbilgi);
			fclose(girisbilgidegis);
			remove("girisbilgi.txt");
			rename("girisbilgidegis.txt","girisbilgi.txt");	
			hesapdokumu=fopen("hesapdokum.txt","a");
			fprintf(hesapdokumu,"%lld -%d & %s\n",tcno,eklepara,asctime(tarihzaman));
			fprintf(hesapdokumu,"%lld +%d & %s",paragontc,eklepara,asctime(tarihzaman));
			fclose(hesapdokumu);
			eklepara=0;
			gecicitcno=0;
			goto islemtekrar;
			
			
			
			
			break;
		case '4':

			do
			{
			if(bakiye==0)
			{
				printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tMalesef Bakiyeniz Bulunmamaktad�r");
				sleep(5);
				system("CLS");
				goto islemtekrar;
			}
			if(eklepara>1000 || eklepara<0)
			{
			printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tTek Seferde 0TL �le 1000TL Aras�naki Faturan�z� �deyebilirsiniz\tBakiye : %lld\n\t\t\t\t\t",bakiye);
			}
			else if(eklepara>bakiye)
			{
			printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tTek Seferde 0TL �le %lldTL Aras�naki Faturan�z� �deyebilirsiniz\tBakiye : %lld\n\t\t\t\t\t",bakiye,bakiye);
			}
			else
			{
			printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tFatura Miktar�n� Giriniz\tBakiye : %lld\n\t\t\t\t\t\t",bakiye);	
			}
			scanf("%d",&eklepara);

			system("CLS");
			}while(eklepara>1000 || eklepara<0 || eklepara>bakiye);
			bakiye-=eklepara;
	 		girisbilgidegis=fopen("girisbilgidegis.txt","w");
			girisbilgi=fopen("girisbilgi.txt","r");
			while(!feof(girisbilgi))
			{		
 			    fscanf(girisbilgi,"%lld %lld %lld",&ftcno,&fsifre,&fbakiye);

				if(ftcno!=tcno)
				{
					if(gecicitcno==ftcno)
					{
						continue;
					}
					fprintf(girisbilgidegis,"%lld %lld %lld\n",ftcno,fsifre,fbakiye);
				}
				if(ftcno==tcno)
				{
					fprintf(girisbilgidegis,"%lld %lld %lld\n",ftcno,fsifre,bakiye);
				}
				gecicitcno=ftcno;
			}
			
			fclose(girisbilgi);
			fclose(girisbilgidegis);
			remove("girisbilgi.txt");
			rename("girisbilgidegis.txt","girisbilgi.txt");	
			hesapdokumu=fopen("hesapdokum.txt","a");
			fprintf(hesapdokumu,"%lld -%d & %s",tcno,eklepara,asctime(tarihzaman));
			fclose(hesapdokumu);
			eklepara=0;
			gecicitcno=0;
			goto islemtekrar;
			break;
		case '5':

			printf("\n\n\t\t\t\t\tHesap Ge�mi�i\t\t\t\t\t\n");
			hesapdokumu=fopen("hesapdokum.txt","r");
			fscanf(hesapdokumu,"%lld %d & %[^\n]c",&ftcno,&eklepara,&ktarih);
			while(!feof(hesapdokumu)){		
 			    //fprintf(hesapdokumu,"%lld %lld %s\n",tcno,eklepara,asctime(tarihzaman));
				if(ftcno==tcno)
				{	
					if(eklepara!=0)
					{
					printf("%s   %d\n",ktarih,eklepara);
					}
				}
				fscanf(hesapdokumu,"%lld %d & %[^\n]c",&ftcno,&eklepara,&ktarih);
			}
			fclose(hesapdokumu);
			getch();
			system("CLS");
			goto islemtekrar;
			
			
			
			break;	
								
		default:
			break;
	}

	

	return 0;
}
