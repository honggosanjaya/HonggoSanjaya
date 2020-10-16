#include <stdio.h>
#include <string.h>

struct str_menu {
	int		No_Item;
	char	Nm_Item[20];
	int		Harga;	
} MENU;

struct str_order {
	int		No_Pesanan;
	int		No_Pelanggan;
	int		No_Item;	
	int		Harga;	
	int		Jumlah;
};

struct str_pelanggan {
	int		No_Pelanggan;
	char	Nm_Pelanggan[20];
};

FILE	*f_menu;
FILE	*f_order;
FILE	*f_pelanggan;

//=========== [ Library terkait Clear Screen ] =========
#ifdef __cplusplus__
  #include <cstdlib>
#else
  #include <stdlib.h>
#endif
//=========== [ Akhir Library terkait Clear Screen ] =========

void CLEAR_SCREEN(){
	if (system("CLS")) system("clear");
};

int NEW_ORDER()	
{	int NewNumber=0;
	struct	str_order ORDER;
	f_order = fopen("order.dat","r");
	while(fread(&ORDER,sizeof(ORDER),1,f_order)==1)
		if(ORDER.No_Pesanan>NewNumber)
			NewNumber=ORDER.No_Pesanan;
	fclose(f_order);
	return ++NewNumber;	
};

int NEW_CUSTOMER()	
{	int NewNumber=0;
	struct	str_pelanggan PELANGGAN;
	f_pelanggan = fopen("customer.dat","r");
	while(fread(&PELANGGAN,sizeof(PELANGGAN),1,f_pelanggan)==1)
		if(PELANGGAN.No_Pelanggan>NewNumber)
			NewNumber=PELANGGAN.No_Pelanggan;
	fclose(f_pelanggan);
	return ++NewNumber;	
};

int NEW_ITEM()	
{	int NewNumber=0;
	struct	str_menu MENU;
	f_menu = fopen("menu.dat","r");
	while(fread(&MENU,sizeof(MENU),1,f_menu)==1)
		if(MENU.No_Item>NewNumber)
			NewNumber=MENU.No_Item;
	fclose(f_menu);
	return ++NewNumber;	
};

void VIEW_ITEM(){
	printf("             DAFTAR MENU ITEM\n");
	printf("===============================================\n");
	printf("#ITEM | NAMA ITEM            |    HARGA\n");
	printf("===============================================\n");
	f_menu = fopen("menu.dat","r");
	while(fread(&MENU,sizeof(MENU),1,f_menu)==1) 
		printf("%5d | %-20s | Rp.%10d\n",MENU.No_Item, MENU.Nm_Item, MENU.Harga);
	printf("===============================================\n");
	fclose(f_menu);
};

void ADD_ITEM(){
	char	Lagi;
	
	do {
		CLEAR_SCREEN();
		VIEW_ITEM();
		MENU.No_Item = NEW_ITEM();
		f_menu = fopen("menu.dat","a");
		printf("Pengisian Menu Item");
		printf("\nNomor Item :%d", MENU.No_Item);
		printf("\nNama  Item :"); fflush(stdin);gets(MENU.Nm_Item);
		printf("Harga Item :"); fflush(stdin);scanf("%d",&MENU.Harga);	

		fwrite(&MENU,sizeof(MENU),1,f_menu);
		do {
			fflush(stdin);
			printf(" Apakah anda ingin menambah data item lagi ? [Y/N] : ");
			Lagi = getche();
		}while ((Lagi!='y')&&(Lagi!='Y')&&(Lagi!='n')&&(Lagi!='N'));
		fclose(f_menu);
	}while ((Lagi=='y')||(Lagi=='Y'));
};

void VIEW_CUSTOMER(){
	struct str_pelanggan PELANGGAN;
	printf("              DAFTAR PELANGGAN\n");
	printf("===============================================\n");
	printf("#PELANGGAN | NAMA PELANGGAN                       \n");
	printf("===============================================\n");
	f_pelanggan = fopen("customer.dat","r");
	while(fread(&PELANGGAN,sizeof(PELANGGAN),1,f_pelanggan)==1) 
		printf("%10d | %-20s\n",PELANGGAN.No_Pelanggan, PELANGGAN.Nm_Pelanggan);
	printf("===============================================\n");
	fclose(f_pelanggan);		
};

void ADD_CUSTOMER(){
	struct str_pelanggan PELANGGAN;
	CLEAR_SCREEN();
	VIEW_CUSTOMER();
	PELANGGAN.No_Pelanggan=NEW_CUSTOMER();
	f_pelanggan = fopen("customer.dat","a");
	printf("Penambahan Data Pelanggan");
	printf("\nNomor Pelanggan :%d",PELANGGAN.No_Pelanggan);
	printf("\nNama Pelanggan  :"); fflush(stdin);gets(PELANGGAN.Nm_Pelanggan);

	fwrite(&PELANGGAN,sizeof(PELANGGAN),1,f_pelanggan);
	fclose(f_pelanggan);
};

void GET_CUSTOMER_NAME(int NoPLG, char NmPelanggan[20])
{	int SELESAI=0;
	struct str_pelanggan PELANGGAN;
	f_pelanggan = fopen("customer.dat","r");
	strcpy(NmPelanggan,"N/A");
	while((fread(&PELANGGAN,sizeof(PELANGGAN),1,f_pelanggan)==1)&&SELESAI==0)
		if(PELANGGAN.No_Pelanggan==NoPLG) 
		{
			strcpy(NmPelanggan,PELANGGAN.Nm_Pelanggan);
			SELESAI=1;
		};
	fclose(f_pelanggan);
};

void GET_ITEM_RECORD(int NoItem, char NmItem[20], int *Harga) 
{	int SELESAI=0;
	f_menu = fopen("menu.dat","r");
	while((fread(&MENU,sizeof(MENU),1,f_menu)==1)&&SELESAI==0)
		if(MENU.No_Item==NoItem) {
			strcpy(NmItem,MENU.Nm_Item);
			*Harga = MENU.Harga;
			SELESAI=1;
		};
	fclose(f_menu);
};

void VIEW_HEADER_ORDER(struct str_order ORDER)
{
	char	NmPelanggan[20];
	GET_CUSTOMER_NAME(ORDER.No_Pelanggan, NmPelanggan);
	printf("\nPENDATAAN PESANAN");
	printf("\n\tNomor Pesanan  : %d",ORDER.No_Pesanan);
	printf("\n\tNo. Pelanggan  : %d - %-20s",ORDER.No_Pelanggan, NmPelanggan); 		
};

void VIEW_ALL_ORDER()
{
	struct	str_order ORDER;
	int		Total=0, Harga=0, NoItem=0, i=0;
	char	NmPelanggan[20];
	char	NmItem[20];
	
	f_order = fopen("order.dat","r");
	printf("\n                                             DAFTAR SELURUH PESANAN");
	printf("\n======================================================================================================================"); 
	printf("\nNo. | #Pesanan | #Pelanggan | Nama Pelanggan       | #Item | Nama Item            | Jum |   Harga    |     Nilai     |"); 
	printf("\n======================================================================================================================"); 
	while(fread(&ORDER,sizeof(ORDER),1,f_order)==1) 
	{	
		GET_CUSTOMER_NAME(ORDER.No_Pelanggan, NmPelanggan);
		GET_ITEM_RECORD(ORDER.No_Item, NmItem, &Harga);
		printf("\n%03d.  %8d   %10d   %-20s   %5d   %-20s   %3d   Rp.%7d   Rp.%10d",++i, ORDER.No_Pesanan, ORDER.No_Pelanggan, NmPelanggan, ORDER.No_Item, NmItem, ORDER.Jumlah, ORDER.Harga, ORDER.Jumlah*ORDER.Harga);
		Total = Total + (ORDER.Harga*ORDER.Jumlah);
	};
	printf("\n======================================================================================================================"); 
	printf("\nTOTAL NILAI : Rp. %d",Total);
	printf("\n======================================================================================================================"); 
	printf("\n                                      *** Akhir Daftar Seluruh Pesanan ***\n"); 
	fclose(f_order);	
};

void SORT_KEY(int KEY[],int N)
{
	int i=0,j=0, Temp;

	for(i=0;i<N;i++)
		for(j=N-1;j>i;j--)
			if (KEY[j]<KEY[j-1]){
				Temp		= KEY[j];
				KEY[j]		= KEY[j-1];
				KEY[j-1]	= Temp;
			};
	
};

void VIEW_ALL_ORDER_SORT_BY_ITEM()
{
	struct	str_order ORDER[100], ORD;
	int		SortKey[100];
	int		TotalItem=0, Total=0, Harga=0, NoItem=0, Indek=0, i=0, JumData=0, JumKey=0, ADA=0, No=0;
	char	NmPelanggan[20];
	char	NmItem[20];
	
	f_order = fopen("order.dat","r");
	while(fread(&ORD,sizeof(ORD),1,f_order)==1) 
	{
		i=0, ADA =0;
		
		ORDER[JumData].No_Pesanan=ORD.No_Pesanan;
		ORDER[JumData].No_Pelanggan=ORD.No_Pelanggan;
		ORDER[JumData].No_Item=ORD.No_Item;
		ORDER[JumData].Jumlah=ORD.Jumlah;
		ORDER[JumData].Harga=ORD.Harga;
		
		do {
			if(ORDER[JumData].No_Item==SortKey[i])
				ADA = 1;
			i++;
		} while((i<JumData)&&(ADA==0));
		if (ADA==0)	{
			SortKey[JumKey]=ORDER[JumData].No_Item;
			JumKey++;
		};
		JumData++;
	};
	fclose(f_order);	

	SORT_KEY(SortKey, JumKey);
	
	printf("\n                                             DAFTAR SELURUH PESANAN");
	printf("\n                                             Urut Berdasarkan #Item");
	printf("\n======================================================================================================================"); 
	printf("\n #Item | Nama Item            |No. | #Pesanan | #Pelanggan | Nama Pelanggan       | Jum |   Harga    |     Nilai     |"); 
	printf("\n======================================================================================================================"); 
	for(Indek=0;Indek<JumKey;Indek++)
	{	
		i=0;
		No=0;
		TotalItem = 0;
		GET_ITEM_RECORD(SortKey[Indek], NmItem, &Harga);
		printf("\n%6d   %-20s  ",SortKey[Indek], NmItem);
		while (i<JumData)
		{
			if (ORDER[i].No_Item==SortKey[Indek])
			{
				GET_CUSTOMER_NAME(ORDER[i].No_Pelanggan, NmPelanggan);
				if(No>0)
					printf("                                   ");
				printf("%03d.  %8d   %10d   %-20s   %3d   Rp.%7d   Rp.%10d",++No, ORDER[i].No_Pesanan, ORDER[i].No_Pelanggan, NmPelanggan, ORDER[i].Jumlah, ORDER[i].Harga, ORDER[i].Jumlah*ORDER[i].Harga);
				TotalItem = TotalItem + (ORDER[i].Harga*ORDER[i].Jumlah);
				Total = Total + (ORDER[i].Harga*ORDER[i].Jumlah);
			};
			i++;
		};
		printf("\n                              ----------------------------------------------------------------------------------------");
		printf("\n                               Total Nilai Item : Rp. %d\n",TotalItem);
	};
	printf("\n======================================================================================================================"); 
	printf("\nTOTAL NILAI : Rp. %d",Total);
	printf("\n======================================================================================================================"); 
	printf("\n                                      *** Akhir Daftar Seluruh Pesanan ***\n"); 
};

void ORDER_ITEM() {
	char	Lagi;
	struct	str_order ORDER;
	int		Total=0, Bayar=0, Kembali=0;
	char	NmPelanggan[20];
	char	NmItem[20];
	
	VIEW_ITEM();
	printf("\nPENDATAAN PESANAN");
	ORDER.No_Pesanan = NEW_ORDER();
	printf("\n\tNomor Pesanan  : %d",ORDER.No_Pesanan);
	printf("\n\tNomor Pelangan : "); fflush(stdin);scanf("%d",&ORDER.No_Pelanggan);
	f_order = fopen("order.dat","a");
	GET_CUSTOMER_NAME(ORDER.No_Pelanggan, NmPelanggan); 
	printf("-%s",NmPelanggan); 		
	do 
	{	CLEAR_SCREEN();
		VIEW_ITEM();
		VIEW_HEADER_ORDER(ORDER);
		printf("\n\tNomor Item     : "); fflush(stdin);scanf("%d",&ORDER.No_Item);
		GET_ITEM_RECORD(ORDER.No_Item, NmItem, &ORDER.Harga);
		printf("\n\tNama Item      : %s",NmItem); 
		printf("\n\tHarga          : %d",ORDER.Harga); 
		printf("\n\tJumlah Pesanan : "); fflush(stdin);scanf("%d",&ORDER.Jumlah);
		Total = Total + (ORDER.Harga*ORDER.Jumlah);
		printf("\n-----------------------------------------------");
		printf("\nTotal Nilai Pesanan Rp. %d",Total);
		printf("\n-----------------------------------------------");
		
		fwrite(&ORDER,sizeof(ORDER),1,f_order);
		
		do {
			fflush(stdin);
			printf("\nPesan item lagi ? [Y/N] : ");
			Lagi = getche();
		}while ((Lagi!='y')&&(Lagi!='Y') &&(Lagi!='n')&&(Lagi!='N'));
	}while ((Lagi=='y')||(Lagi=='Y'));
	printf("\nPembayaran     : Rp. "); fflush(stdin); scanf("%d",&Bayar);
	Kembali	= Bayar-Total;
	printf("Pengembalian   : Rp. %d",Kembali);
	printf("\n===============================================\n\n");	
	fclose(f_order);
};


void MALANG_RESTO()
{
	printf("MALANG RESTO");	
	printf("\n============");	
	printf("\n\nPILIHAN PROSES :");	
	printf("\n1.Tambah Menu Item");	
	printf("\n2.Tambah Pelanggan");	
	printf("\n3.Tambah Pesanan Item");		
	printf("\n4.Tampilkan Menu Item");	
	printf("\n5.Tampilkan Pelanggan");	
	printf("\n6.Tampilkan Seluruh Pesanan");	
	printf("\n7.Tampilkan Seluruh Pesanan (urut #item)");	
	printf("\n8.Keluar");	
};

void	main(){
	char PIL;
	do {
		CLEAR_SCREEN();
		MALANG_RESTO();	
		do {
			fflush(stdin);
			printf("\n\nPilihan Anda : ");
			PIL = getche();
		}while ((PIL!='1')&&(PIL!='2')&&(PIL!='3')&&(PIL!='4')&&(PIL!='5')&&(PIL!='6')&&(PIL!='7')&&(PIL!='8'));
		switch (PIL)
		{
			case '1' : CLEAR_SCREEN();ADD_ITEM();break;	
			case '2' : CLEAR_SCREEN();ADD_CUSTOMER();break;	
			case '3' : CLEAR_SCREEN();ORDER_ITEM();break;	
			case '4' : CLEAR_SCREEN();VIEW_ITEM();break;	
			case '5' : CLEAR_SCREEN();VIEW_CUSTOMER();break;	
			case '6' : CLEAR_SCREEN();VIEW_ALL_ORDER();break;	
			case '7' : CLEAR_SCREEN();VIEW_ALL_ORDER_SORT_BY_ITEM();break;	
		};
		if (PIL!='8'){
			printf("Tekan sembarang tombol untuk melanjutkan !");
			getche();
		}
	}while (PIL!='8');
};
