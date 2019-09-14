sed '63,$d' CAENGECO2020.log >>weused  #改一下需要保留的行数,这里删除了63及以后的行
ls -l | cut -d " " -f10 weused>> value 
ls -l | cut -d " " -f8  weused >> style
ls -l | cut -d " " -f6  weused >> channel
ls -l | cut -c13-14 weused >> hour
ls -l | cut -c16-17 weused >> minute
ls -l | cut -c19-20 weused >> second
sed -i 's/^.//' value
sed -i 's/..$//' value
sed -i 's/.$//' style
sed -i 's/^.//' style
sed -i 's/.$//' channel
sed -i 's/^.//' channel
root -l getfile.C
