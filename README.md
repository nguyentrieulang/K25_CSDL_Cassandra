# K25_CSDL_Cassandra
K25_CSDL_Cassandra chua file import du lieu mysql, cassandra, generate data:
1. Create directory at: /opt/data
2. Run script: generate_data.sh
3. For import to mysql:
  - open file import_data_to_mysql.sh
  - set correct ip, username, password, dbname 
  - run: sh import_data_to_mysql.sh
4. For import to Cassandra
  - Download dse 6.7 at: https://www.datastax.com/products/datastax-enterprise-6
  - copy download file to /opt/ and uncompress
  - put file import_data_to_cassandra.sh to install directory of dse
  - start cassandra: ./bin/dse cassandra -f -k 
  - run script: import_data_to_cassandra.sh to import data
