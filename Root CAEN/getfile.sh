#sed '63,$d'CAENexample.dat >> CAENexample.dat  #改一下需要保留的行数,这里删除了63及以后的行
ls -l | cut -d " " -f10 CAENexample.dat>> value 
ls -l | cut -d " " -f8  CAENexample.dat >> style
ls -l | cut -d " " -f6  CAENexample.dat >> channel
ls -l | cut -c13-14 CAENexample.dat >> hour
ls -l | cut -c16-17 CAENexample.dat >> minute
ls -l | cut -c19-20 CAENexample.dat >> second
sed -i 's/^.//' value
sed -i 's/..$//' value
sed -i 's/.$//' style
sed -i 's/^.//' style
sed -i 's/.$//' channel
sed -i 's/^.//' channel
root -l getfile.C
