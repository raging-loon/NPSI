# the installation file for the UTM 
printf "\033[0;32mInstalling required packages\033[0m\n"
apt install -y libssl-dev libsqlite3-dev liblua5.3-dev gcc make sqlite3
mkdir /usr/share/vigil
mkdir /usr/share/vigil/rules
cp ../vigil/rules/* /usr/share/vigil/rules/
mkdir /etc/vigil
cp vigil.conf /etc/vigil/vigil.conf
cp deny.conf /etc/vigil/deny.conf
cp domainm.conf /etc/vigil/
touch /etc/vigil/hosts.conf
mkdir /var/log/vigil/
touch /var/log/vigil/siglog.log
touch /etc/vigil/passwd
touch /usr/share/vigil/arpcache.csv
touch /var/log/vigil/login.log
touch /var/log/vigil/fail.log

mkdir /usr/share/vigil/scripts/
cp ../vigil/lua/scripts/* /usr/share/vigil/scripts/
cp lscript.conf /etc/vigil/

sqlite3 spi.db < ../vigil/database/install_spi.sql
cp spi.db /usr/share/vigil/

mkdir /usr/share/vigil/stats/
mkdir /usr/share/vigil/stats/pps/

cd ../vigil
make
cp vigil.exe /usr/bin/vigil
cd ../
cd ipcrouter
gcc main.c -o ipcrouter
cp ipcrouter /bin
cd ../install
openssl genrsa -out privkey.pem 2048
openssl rsa -in privkey.pem -pubout -out pubkey.crt
openssl pkcs8 -topk8 -inform PEM -outform PEM -nocrypt -in privkey.pem -out pkcs8.key
mkdir /etc/vigil/keys/
mv privkey.pem pubkey.crt pkcs8.key /etc/vigil/keys
mkdir /usr/share/vigil/crashes/
# clear
gzip ./vigil.8
mv vigil.8.gz /usr/share/man/man8/


printf "\033[0;32mInstallation Complete\033[0m\n"