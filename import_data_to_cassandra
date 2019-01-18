#!/bin/bash

TEN_BANG=vung_mien
USER=root
PASSWD=123456a@Abc
DB_NAME=che_do_dinh_duong
DATA_PATH=/opt/data
insert_table () {
TEN_BANG=$1
DATE=`date`
echo "${DATE}: Start insert $TEN_BANG table "
bin/cqlsh -e "truncate  ${DB_NAME}.${TEN_BANG}  ;"
bin/cqlsh -e "COPY  ${DB_NAME}.${TEN_BANG} FROM '${DATA_PATH}/${TEN_BANG}' WITH DELIMITER = ',' AND HEADER = true  ;"
DATE=`date`
echo "${DATE}: Finish insert $TEN_BANG success !!!"

}

insert_mon_an_table () {
TEN_BANG=$1
DATE=`date`
echo "${DATE}: Start insert $TEN_BANG table "
bin/cqlsh -e "truncate  ${DB_NAME}.${TEN_BANG}  ;"
bin/cqlsh -e "COPY  ${DB_NAME}.${TEN_BANG}(mon_an_id,ten_mon_an,loai_mon_an_id) FROM '${DATA_PATH}/${TEN_BANG}' WITH DELIMITER = ',' AND HEADER = true  ;"
DATE=`date`
echo "${DATE}: Finish insert $TEN_BANG success !!!"

}

insert_nhan_khau_table () {
TEN_BANG=$1
DATE=`date`
echo "${DATE}: Start insert $TEN_BANG table "
bin/cqlsh -e "truncate  ${DB_NAME}.${TEN_BANG}  ;"
bin/cqlsh -e "COPY  ${DB_NAME}.${TEN_BANG}(nk_id,ho,ten,gioi_tinh,vung_mien) FROM '${DATA_PATH}/${TEN_BANG}' WITH DELIMITER = ',' AND HEADER = true  ;"
DATE=`date`
echo "${DATE}: Finish insert $TEN_BANG success !!!"

}

insert_dinhduong_table () {
TEN_FILE=$2
TEN_BANG=$1
echo "1: $1, 2: $2"
DATE=`date`
echo "${DATE}: Start insert $TEN_FILE $TEN_BANG table "
bin/cqlsh -e "COPY ${DB_NAME}.${TEN_BANG}(id,nk_id,bua_an,mon_chinh,canh,thit,hoa_qua,do_uong,ngay,thang,nam)  FROM '${DATA_PATH}/${TEN_FILE}' WITH DELIMITER = ',' AND HEADER = true  ;"
DATE=`date`
echo "${DATE}: Finish insert $TEN_FILE success !!!"

}

#make
#./main
insert_table vung_mien
insert_table loai_mon_an
insert_mon_an_table mon_an
insert_table bua_an
insert_nhan_khau_table nhan_khau
bin/cqlsh -e "truncate ${DB_NAME}.bang_dinh_duong  ;"

CUR_DIR=`pwd`
cd $DATA_PATH
LIST_FILE=`ls -rt bang_dinh_*`
cd $CUR_DIR 
echo "CURRENT DIR :    "`pwd`
for x in ${LIST_FILE} ; do 
#	bin/cqlsh -e "COPY che_do_dinh_duong.vung_mien FROM '/opt/data/${x}' WITH DELIMITER = ',' AND HEADER = true  ;"
	insert_dinhduong_table bang_dinh_duong $x;
#	exit 0 ;
done
echo "Insert data FINISH!!!!!!!!!!!!!!!!!!!!!!!"
cd $CUR_DIR 




