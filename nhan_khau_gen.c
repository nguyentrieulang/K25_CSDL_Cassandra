
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
const char* family[]= { "Nguyen", "Tran", "Ly", "Le", "Trieu", "Dinh", "Ha", "Truong", "Luu", "Hoang", "Dang"};
uint32_t max_family = 10 ;	
const char* midle_man_name[] = {"Van", "Anh", "Minh", "Tien", "Duc", "The", "Phu", "Manh","Thanh", "Dinh"};
uint32_t max_man_midle = 10 ;
const char* man_name[] = {"Long","Anh", "Thang", "Quyen", "Tuan", "Bao", "Hoa", "Hung", "Nghia", "Giang", "Bach", "Duong", "Dang","Vinh", "Hung"};
uint32_t max_man_name=15;


const char* midle_women_name[] = {"Thi", "Thu", "Phuong", "Thanh", "My", "Ngoc", "Xuan", "Ha","Hoang", "Mai"};
uint32_t max_women_midle = 10 ;


const char* women_name[] = {"Lan","Anh", "Tho", "Quyen", "Thuy", "Linh", "Hoa", "Huong", "Ngan", "Giang", "Mai", "Dung", "Duong","Van", "Ha"};
uint32_t max_women_name=15;

int provinde_gen( int max ) {
//	srand(time(NULL)) ;
	int r = rand() ;
//	printf("%d \n", r ) ;
	return (r % max );
}

const char* primary_meal    [] ={"Com", "Pho", "Bun", "Mien","Xoi"};
const char  primary_meal_id [] ={0    , 1,     2,     3,     4 };
uint32_t primary_meal_number= 5 ;
const char* soup            [] ={"Canh Rau muon", "Canh Khoa tay", "Canh ca", "Canh bi", "Canh mong toi"} ;
const char  soup_id 	    [] ={0              , 1              , 2        , 3         , 4};
uint32_t soup_number = 5 ;
const char* meat            [] ={"Thit cho"     ,    "Thit bo"   , "Ca",      "Thit heo",  "Thit ga","Thit trau"} ;
const char  meat_id         [] ={0          ,    1              ,2         ,3          ,4          ,5 };
uint32_t meat_number = 6 ;
const char* fruit           [] ={"Tao"   , "Cam", "Buoi", "Nho", "Xoai", "Man", "Nhan", "Vai"} ;
const char  fruit_id        [] ={0      , 1,       2     , 3    ,4      , 5    , 6     , 7    };
uint32_t    fruit_number = 8;
const char* drinke          [] ={"Nuoc", "Bia", "Ruou","Sua", "Soda"};
uint32_t    drinke_id       [] ={ 0    ,    1 ,      2,   3,     4} ;
uint32_t    drinke_number    = 5 ;

const char* provine[] = {"Mien bac", "Mien Nam", "Mien Trung"} ;
const char provine_id[] = {0,        1           ,2 };
char provine_number = 3;


const char* type_meal[] = {"Mon chinh", "Canh", "Thit", "Trang mieng", "Do uong"} ;
const char type_meal_id[] = {0,    1        ,2,     3,              4 };
char type_meal_number = 5;


const char* time_in_day[] = {"Bua sang", "Bua trua", "Bua toi"} ;
const char time_in_day_id[] = {0,        1           ,2 };
char time_in_day_number = 3;


#define SAVE_PATH "/opt/data/"	
#define PRONVINE_TABLE "vung_mien"
#define TYPE_MEAL_TABLE "loai_mon_an"
#define MEAL_TABLE "mon_an"
#define TIME_TABLE "bua_an"
#define PERSON_TABLE "nhan_khau"
#define DD_INFORM_TABLE "bang_dinh_duong"

int main () {
	int fml, srn, nm;
	FILE* f = NULL;
	char name_file[256] ;
	char buf[1024];
	int i = 0 ;
	int j = 0 ;
	uint32_t current_id = 0 ;
	uint32_t mon_chinh_index = 0 ;
	uint32_t soup_index = 0;
	uint32_t thit_index = 0 ;
	uint32_t trang_mieng_index = 0 ;
	uint32_t do_uong_index = 0 ;
	uint32_t persion_id = 0 ;
	uint32_t date_id = 1 ;
	uint32_t thang_id= 1;
        uint32_t nam_id = 2000;
	uint32_t person_inform[6000];	
	srand(time(NULL)) ;
	uint32_t count_raw = 0 ;
	uint32_t dinh_duong_id = 0 ;
	uint32_t bua_an_id = 0 ;
	uint32_t file_id = 0 ;
	
	sprintf(name_file,"%s/%s", SAVE_PATH, PRONVINE_TABLE ) ;
	f= fopen(name_file,"w") ;
	fputs("vung_id,ten_vung\n",f) ;
	for ( i = 0 ; i < provine_number ; i++ ) {
		sprintf(buf,"%d,%s\n", provine_id[i], provine[i]) ;
		fputs(buf, f);
	}
	fclose(f) ;


	sprintf(name_file,"%s/%s", SAVE_PATH, TYPE_MEAL_TABLE ) ;
//	printf("Name file: %s\n", name_file) ;
	f= fopen(name_file,"w") ;
	fputs("loai_mon_an_id,ten_loai\n",f) ;
	for ( i = 0 ; i < type_meal_number ; i++ ) {
		sprintf(buf,"%d,%s\n", type_meal_id[i], type_meal[i]) ;
		fputs(buf, f);
	}
	fclose(f) ;

	sprintf(name_file,"%s/%s", SAVE_PATH, MEAL_TABLE ) ;
	f= fopen(name_file,"w") ;
	j = 0 ;
	fputs("mon_an_id,ten_mon_an,loai_mon_an_id\n",f) ;
	
	current_id = 0 ;
	for ( i = 0 ; i < primary_meal_number ; i++ ) {
		sprintf(buf,"%d,%s,%d\n", primary_meal_id[i]+ current_id, primary_meal[i],j) ;
		fputs(buf, f);
	}

	current_id += primary_meal_number;
	
	soup_index = current_id ;
	j++ ;
	for ( i = 0 ; i < soup_number ; i++ ) {
		sprintf(buf,"%d,%s,%d\n", soup_id[i]+ current_id, soup[i],j) ;
		fputs(buf, f);
	}

	current_id += soup_number;
	thit_index = current_id ;
	j++ ;
	for ( i = 0 ; i < meat_number ; i++ ) {
		sprintf(buf,"%d,%s,%d\n", meat_id[i]+ current_id, meat[i],j) ;
		fputs(buf, f);
	}
	current_id += meat_number;

	trang_mieng_index = current_id ;

	j++ ;
	for ( i = 0 ; i < fruit_number ; i++ ) {
		sprintf(buf,"%d,%s,%d\n", fruit_id[i]+ current_id, fruit[i],j) ;
		fputs(buf, f);
	}
	current_id += fruit_number;
	do_uong_index = current_id ;
	j++ ;
	for ( i = 0 ; i < drinke_number ; i++ ) {
		sprintf(buf,"%d,%s,%d\n", drinke_id[i]+ current_id, drinke[i],j) ;
		fputs(buf, f);
	}



	fclose(f) ;

	sprintf(name_file,"%s/%s", SAVE_PATH, TIME_TABLE ) ;
	f= fopen(name_file,"w") ;
	fputs("bua_an_id,ten_bua\n",f) ;
	for ( i = 0 ; i < time_in_day_number ; i++ ) {
		sprintf(buf,"%d,%s\n", time_in_day_id[i], time_in_day[i]) ;
		fputs(buf, f);
	}
	fclose(f) ;


	sprintf(name_file,"%s/%s", SAVE_PATH, PERSON_TABLE ) ;
	f= fopen(name_file,"w") ;
	fputs("nk_id,ho,ten,gioi_tinh,vung_mien\n",f) ;

       	for ( fml = 0 ; fml < max_family; fml ++ ) 
	{
		for ( srn = 0 ; srn < max_man_midle; srn ++ )
			for ( nm = 0 ; nm < max_man_name ; nm ++ ) {
				person_inform[persion_id] = persion_id ;
				sprintf(buf,"%d,%s,%s %s,%d,%d\n",persion_id, family[fml], midle_man_name[srn], man_name[nm],1,provinde_gen(provine_number) ) ;
				fputs(buf, f);
				persion_id++ ;
			}
			//	printf("'%s', '%s %s',1,%d\n", family[fml], midle_man_name[srn], man_name[nm],provinde_gen(3)) ; 	
	}
   	for ( fml = 0 ; fml < max_family; fml ++ ) 
	{
		for ( srn = 0 ; srn < max_women_midle; srn ++ )
			for ( nm = 0 ; nm < max_women_name ; nm ++ ){ 
				person_inform[persion_id] = persion_id ;

				sprintf(buf,"%d,%s,%s %s,%d,%d\n",persion_id, family[fml], midle_women_name[srn], women_name[nm],0,provinde_gen(provine_number) ) ;
				fputs(buf, f);
				persion_id++ ;

			//	printf("'%s', '%s %s',0,%d\n", family[fml], midle_women_name[srn], women_name[nm],provinde_gen(3)) ;
			}	
	}

	fclose(f) ;

	sprintf(name_file,"%s/%s_%d", SAVE_PATH, DD_INFORM_TABLE, file_id++ ) ;
	f= fopen(name_file,"w") ;
	fputs("id,nk_id,bua_an,mon_chinh,canh,thit,hoa_qua,do_uong,ngay,thang,nam\n",f) ;
//	printf("persion_id: %d, time_in_day_number:%d\n", persion_id , time_in_day_number) ;
	for ( nam_id = 1980; nam_id <=2012; nam_id ++ ) {
		for ( thang_id = 1 ; thang_id <= 12; thang_id ++ ) {
			printf("On %d/%d: Gen data\n", thang_id, nam_id ) ;
			for ( date_id = 1 ; date_id <= 30 ; date_id ++ ) {
				for ( bua_an_id = 0 ; bua_an_id < time_in_day_number; bua_an_id ++ ) {
					for ( j = 0 ; j < persion_id ; j ++ ) {
						sprintf(buf,"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",
							dinh_duong_id++,
							person_inform[j],
							bua_an_id,
							provinde_gen(3)	,
							provinde_gen(soup_number) + soup_index,
							provinde_gen(meat_number)	+ thit_index,
							provinde_gen(fruit_number)	+ trang_mieng_index,
							provinde_gen(drinke_number)	+ do_uong_index,
							date_id,
							thang_id,
							nam_id
							) ;
							fputs(buf, f);
					//		printf("AAAA") ;
						count_raw ++ ;
						if ( count_raw == 1000000 ) {
							count_raw = 0 ;
							fclose(f) ;
	//						exit(0) ;
							sprintf(name_file,"%s/%s_%d", SAVE_PATH, DD_INFORM_TABLE, file_id++ ) ;
							f= fopen(name_file,"w") ;
							fputs("id,nk_id,bua_an,mon_chinh,canh,thit,hoa_qua,do_uong,ngay,thang,nam\n",f) ;


						}
					}
				}

			}


//	fputs("mon_an_id,ten_mon_an,loai_mon_an_id\n",f) ;
	
//	current_id = 0 ;
//	for ( i = 0 ; i < primary_meal_number ; i++ ) {
//		sprintf(buf,"%d,%s,%d\n", primary_meal_id[i]+ current_id, primary_meal[i],j) ;
//		fputs(buf, f);
//	}
		}
	}

}
