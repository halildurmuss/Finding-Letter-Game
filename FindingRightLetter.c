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

		c = (rand()%26)+'a'; // a'dan z'ye kadar rasgele harf olu�turur.

		printf("�stenilen karakter--> %c, %d sn icinde karakteri girmelisiniz.\n",c,slimit);

		start = clock(); // Zaman haf�zaya yaz�l�r
		g= getch(); // bir tu�a bas�lmas� istenir
		fark = clock() - start; // tu�a bas�ld�ktan sonraki zamanla ba�lang��taki zaman fark�n� al�r

		msec = fark * 1000 / CLOCKS_PER_SEC; // ms cinsinden s�reyi hesaplar

		if (g==2) { // CTRL+b girilip girilmedi�ini kontrol eder.
			printf("Oyun sonlandi toplam puan---> %d, dogru bilinen-----> %d\n",puan,dogru);
			cikis = 1;
		} else if (msec>slimit *1000) { // verilen s�renin dolup dolmad���n� kontrol eder.
			puan -=3;
			printf("Sure asildi, gecen sure:%d sn, puan---> %d\n",msec/1000,puan);
		} else if (g==c) { // Do�ru karakterin girilip girilmedi�ini kontrol eder.
			puan +=5; // puan verir
			dogru++; // do�ru say�s�n� art�r�r
			printf("Karakter dogru, gecen sure:%d sn, puan ---> %d\n",msec/1000,puan);
		} else { // hatal� karakter girilirse.
			puan -=3;
			printf("Hatali karakter, gecen sure:%d sn, puan---> %d\n",msec/1000,puan);
		}
	}
	return 0;
}
