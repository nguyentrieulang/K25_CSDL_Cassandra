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
mysql -u ${USER} -p${PASSWD} -e "truncate ${DB_NAME}.${TEN_BANG};"
mysql -u ${USER} -p${PASSWD}  -e "LOAD DATA INFILE '${DATA_PATH}/${TEN_BANG}' INTO TABLE ${DB_NAME}.${TEN_BANG} FIELDS TERMINATED BY ','  LINES TERMINATED BY '\n' IGNORE 1 ROWS;"
DATE=`date`
echo "${DATE}: Finish insert $TEN_BANG success !!!"

}

insert_dinhduong_table () {
TEN_FILE=$2
TEN_BANG=$1
echo "1: $1, 2: $2"
DATE=`date`
echo "${DATE}: Start insert $TEN_FILE $TEN_BANG table "
#mysql -u ${USER} -p${PASSWD} -e "truncate {DB_NAME}.${TEN_BANG};"
mysql -u ${USER} -p${PASSWD}  -e "LOAD DATA INFILE '${DATA_PATH}/${TEN_FILE}' INTO TABLE ${DB_NAME}.${TEN_BANG} FIELDS TERMINATED BY ','  LINES TERMINATED BY '\n' IGNORE 1 ROWS;"
DATE=`date`
echo "${DATE}: Finish insert $TEN_FILE success !!!"

}

#make
#./main
insert_table vung_mien
insert_table loai_mon_an
insert_table mon_an
insert_table bua_an
insert_table nhan_khau
mysql -u ${USER} -p${PASSWD} -e "truncate ${DB_NAME}.bang_dinh_duong;"
CUR_DIR=`pwd`
cd $DATA_PATH
LIST_FILE=`ls -rt bang_dinh_duong*`
for x in ${LIST_FILE} ; do 
	insert_dinhduong_table bang_dinh_duong $x
done
echo "Insert data FINISH!!!!!!!!!!!!!!!!!!!!!!!"





