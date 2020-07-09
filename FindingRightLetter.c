#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {

	char c;
	int g;
	clock_t start, fark;
	int msec;
	int puan;
	int cikis =0;
	int dogru =0;
	int slimit = 2;

	srand(time(NULL));

	while(!cikis) {

		c = (rand()%26)+'a'; // a'dan z'ye kadar rasgele harf oluþturur.

		printf("Ýstenilen karakter--> %c, %d sn icinde karakteri girmelisiniz.\n",c,slimit);

		start = clock(); // Zaman hafýzaya yazýlýr
		g= getch(); // bir tuþa basýlmasý istenir
		fark = clock() - start; // tuþa basýldýktan sonraki zamanla baþlangýçtaki zaman farkýný alýr

		msec = fark * 1000 / CLOCKS_PER_SEC; // ms cinsinden süreyi hesaplar

		if (g==2) { // CTRL+b girilip girilmediðini kontrol eder.
			printf("Oyun sonlandi toplam puan---> %d, dogru bilinen-----> %d\n",puan,dogru);
			cikis = 1;
		} else if (msec>slimit *1000) { // verilen sürenin dolup dolmadýðýný kontrol eder.
			puan -=3;
			printf("Sure asildi, gecen sure:%d sn, puan---> %d\n",msec/1000,puan);
		} else if (g==c) { // Doðru karakterin girilip girilmediðini kontrol eder.
			puan +=5; // puan verir
			dogru++; // doðru sayýsýný artýrýr
			printf("Karakter dogru, gecen sure:%d sn, puan ---> %d\n",msec/1000,puan);
		} else { // hatalý karakter girilirse.
			puan -=3;
			printf("Hatali karakter, gecen sure:%d sn, puan---> %d\n",msec/1000,puan);
		}
	}
	return 0;
}
