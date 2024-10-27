#include <stdio.h>
#include <string.h>

struct laporan {
	int date;
	int month;
	int year;
	int totalDate;
	char name[25];
	char genre[25];
	char title[100];
	int stock;
	int price;
	int total;
};

struct buku{
	char genre[20];
	char title[100];
	int stock;
	int price;
};

void addData(){
	FILE *fp;
	fp = fopen("sales.txt", "a");
	
	struct laporan tambah;
	
	printf("\nMasukkan tanggal transaksi: ");
	scanf("%d", &tambah.date);
	getchar();
	printf("Masukkan bulan transaksi: ");
	scanf("%d", &tambah.month);
	getchar();
	printf("Masukkan tahun transaksi: ");
	scanf("%d", &tambah.year);
	getchar();
	printf("Masukkan nama pelanggan: ");
	scanf("%[^\n]", tambah.name);
	getchar();
	printf("Masukkan jenis buku: ");
	scanf("%[^\n]", tambah.genre);
	getchar();
	printf("Masukkan judul buku: ");
	scanf("%[^\n]", tambah.title);
	getchar();
	printf("Masukkan jumlah buku: ");
	scanf("%d", &tambah.stock);
	getchar();
	printf("Masukkan harga buku: ");
	scanf("%d", &tambah.price);
	getchar();
	tambah.total = tambah.stock*tambah.price;
	printf("Total pembayaran adalah: %d", tambah.total);
	
	fprintf(fp, "%d-%d-%d; %s; %s; %s; %d; %d; %d\n", tambah.date, tambah.month, tambah.year, tambah.name, tambah.genre, tambah.title, tambah.stock, tambah.price, tambah.total);
	printf("\nData transaksi %s berhasil ditambahkan.", tambah.name);
	fclose(fp);
}

void cetakJudul() {
	printf("\n----------------------------LAPORAN DATA PENJUALAN----------------------------");
	printf("\n  TANGGAL	    NAMA	 GENRE	  STOK	HARGA	 TOTAL	   JUDUL BUKU\n");
}

void printData(){
	struct laporan cetak[100], swap;
	
	FILE *fp;
	fp = fopen("sales.txt", "r");
	
	printf("\nMENCETAK LAPORORAN DATA PENJUALAN");
	printf("\n1 Urutkan berdasarkan tanggal transaksi");
	printf("\n2 Urutkan berdasarkan besar transaksi");
	printf("\n3 Urutkan berdasarkan stok");
	printf("\nPilihanmu: ");
	
	int pilihan;
	scanf("%d", &pilihan);
	
	int count = 0;
	while(fscanf(fp, "%d-%d-%d; %[^;]; %[^;]; %[^;]; %d; %d; %d\r\n", &cetak[count].date, &cetak[count].month, &cetak[count].year, cetak[count].name, cetak[count].genre, cetak[count].title, &cetak[count].stock, &cetak[count].price, &cetak[count].total) != EOF) {		
	
		cetak[count].totalDate = cetak[count].date + (cetak[count].month*30) + cetak[count].year*365;
		count++;
	}
	
	switch(pilihan) {
		case 1:
			cetakJudul();
			for(int z=0; z<count-1; z++) {
        		for(int y=0; y<count-1; y++) {
            		if(cetak[y].totalDate < cetak[y+1].totalDate) { 
                		swap = cetak[y];
                		cetak[y] = cetak[y+1]; 
                		cetak[y+1] = swap;   
       		     	}
        		}
   			}
   			for(int i=0; i<count; i++) {
   				printf("%d-%d-%d	%s	%s	   %d	%d	%d	   %s\n", cetak[i].date, cetak[i].month, cetak[i].year, cetak[i].name, cetak[i].genre, cetak[i].stock, cetak[i].price, cetak[i].total, cetak[i].title);
			   }
			printf("Diurutkan berdasarkan pembelian dengan tanggal terkini");
			break;
		case 2:
			cetakJudul();
			for(int z=0; z<count-1; z++) {
        		for(int y=0; y<count-1; y++) {
            		if(cetak[y].total < cetak[y+1].total) { 
                		swap = cetak[y];
                		cetak[y] = cetak[y+1]; 
                		cetak[y+1] = swap;   
       		     	}
        		}
   			}
   			for(int i=0; i<count; i++) {
   				printf("%d-%d-%d	%s	%s	   %d	%d	%d	   %s\n", cetak[i].date, cetak[i].month, cetak[i].year, cetak[i].name, cetak[i].genre, cetak[i].stock, cetak[i].price, cetak[i].total, cetak[i].title);
			   }
			printf("Diurutkan berdasarkan pembelian dengan total transaksi terbesar");
			break;
		case 3:
			cetakJudul();
			for(int z=0; z<count-1; z++) {
        		for(int y=0; y<count-1; y++) {
            		if(cetak[y].stock < cetak[y+1].stock) { 
                		swap = cetak[y];   
                		cetak[y] = cetak[y+1]; 
                		cetak[y+1] = swap;   
       		     	}
        		}
   			}
   			for(int i=0; i<count; i++) {
   				printf("%d-%d-%d	%s	%s	   %d	%d	%d	   %s\n", cetak[i].date, cetak[i].month, cetak[i].year, cetak[i].name, cetak[i].genre, cetak[i].stock, cetak[i].price, cetak[i].total, cetak[i].title);
			   }
			printf("Diurutkan berdasarkan pembelian dengan stok terbanyak");
			break;
		default:
			printf("Anda salah memasukkan nomor!");
	}
	
	fclose(fp);
}
void searchBook(){
	struct buku cari[100];
	
	FILE *fp;
	fp = fopen("book.txt", "r");
	
	int count = 0;
	while(fscanf(fp, "%[^;]; %[^;]; %d; %d\r\n", cari[count].genre, cari[count].title, &cari[count].stock, &cari[count].price) != EOF) {
		count++;
	}
	fclose(fp);
	
	int pilihan;
	printf("\nPENCARIAN");
	printf("\n1 Berdasarkan judul");
	printf("\n2 Berdasarkan genre");
	printf("\nPilihanmu: ");
	scanf("%d", &pilihan);
	getchar();
	
	char input[100] = "";
	int inputNum;
	int counter = 0;
	
	switch(pilihan) {
		case 1:
			printf("Masukkan judul buku: ");
			scanf("%[^\n]", input);
			getchar();
			while(strcmp(input,cari[counter].title) != 0 && counter<count){
				counter++;
			}

			if(counter == count) printf("Buku tidak ditemukan");
			else {
				printf("\nBuku yang kamu cari adalah %s", input);
				printf("\nGenre:%s\nJudul:%s\nStok:%d\nHarga:Rp%d\n", cari[counter].genre, cari[counter].title, cari[counter].stock, cari[counter].price);
			}
			
			break;
		case 2:
			printf("\nCari Buku Berdasarkan Genre");
			printf("\n1 Romantis");
			printf("\n2 Horor");
			printf("\n3 Edukasi");
			printf("\n4 Fantasi");
			printf("\nPilihanmu: ");
			scanf("%d", &inputNum);
			getchar();
			
			switch(inputNum){
				case 1:
					strcpy(input,"Romantis");
					break;
				case 2:
					strcpy(input,"Horor");
					break;
				case 3:
					strcpy(input,"Edukasi");
					break;
				case 4:
					strcpy(input,"Fantasi");
					break;
				default:
					printf("Anda salah memasukkan nomor!");
			} 
			
			
			printf("\n====================Buku Dengan Genre %s====================", input);
			for(int i=0; i<count; i++)
				if(strcmp(input,cari[i].genre) == 0 && i<count){
					printf("\nGenre:%s	  Stok:%d	Harga:Rp%d	Judul:%s", cari[i].genre, cari[i].stock, cari[i].price, cari[i].title);
				}
			break;
		default:
			printf("Anda salah memasukkan nomor!");
	}
}

void listBook() {
	struct buku baca[100];
	
	FILE *fp;
	fp = fopen("book.txt", "r");
	
	printf("\n------------------------------------DAFTAR BUKU------------------------------------");
	printf("\n    GENRE	  STOK		   HARGA			  JUDUL");
	
	int count = 0;
	while(fscanf(fp, "%[^;]; %[^;]; %d; %d\r\n", baca[count].genre, baca[count].title, &baca[count].stock, &baca[count].price) != EOF) {
		printf("\nGenre:%s	Stok:%d		Harga:Rp%d		Judul:%s", baca[count].genre, baca[count].stock, baca[count].price, baca[count].title);

		count++;
	}	
		
	
	fclose(fp);
}

void addBook(){
	struct buku tambah;
	
	FILE *fp;
	fp = fopen("book.txt", "a");
	
	printf("\nGenre buku: ");
	scanf("%s", tambah.genre);
	getchar();	
	printf("Judul buku: ");
	scanf("%[^\n]", tambah.title);
	getchar();	
	printf("Stok buku: ");
	scanf("%d", &tambah.stock);
	getchar();
	printf("Harga buku: ");
	scanf("%d", &tambah.price);
	getchar();
	
	fprintf(fp, "%s; %s; %d; %d\n", tambah.genre, tambah.title, tambah.stock, tambah.price);
	fclose(fp);
	
	printf("Berhasil menambahkan buku %s", tambah.title);
}



int main() {
	int pilihan = 0;
	while(pilihan != 6) {
	
		printf("SELAMAT DATANG\n");
		printf("1 Masukkan data penjualan\n");
		printf("2 Mencetak data penjualan\n");
		printf("3 Cari buku\n");
		printf("4 Cetak daftar buku\n");
		printf("5 Menambahkan buku\n");
		printf("6 Exit\n");
		printf("Pilihanmu: ");
		scanf("%d", &pilihan);
		getchar();
		
		switch(pilihan) {
			case 1:
				addData();
				break;
			case 2:
				printData();
				break;
			case 3:
				searchBook();
				break;
			case 4:
				listBook();
				break;
			case 5:
				addBook();
				break;
			case 6:
				printf("\nTerimakasih");
				break;
			default:
				printf("Anda salah memasukkan nomor menu!\n");
		}
		printf("\n\n");
	}
	return 0;
}