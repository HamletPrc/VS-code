#include <iostream>
#include <fstream>
#include <string>

TString file1="value";
TString file2="hour";
TString file3="minuteute";
TString file4="second";
TString file5="channel";
TString file6="style";
const int number=62;
double x[number];
double hour[number];
double start1=22;
double minute[number];
double start2=38;
double sec[number];
double start3=48;
double ttime[number];
double channel[number];
TString style[number];

void getfile(){
	//获取文件字符
    std::filebuf ifile;
    if (!ifile.open(file6, std::ios::in))
		std::cout << "File does not exist!" << std::endl;
	else
	{
		TString str_line;
		std::istream iline(&ifile);
		int i=0;
        for (int l=0;l<number;l++)
        {
			i++;
            str_line.ReadLine(iline);
			style[i]=str_line;
            style[i]=style[i];
            std::cout << "style " <<i <<"="<< style[i]<< std::endl;
		}
    }
	//获取文件数据
    std::filebuf iifile;
	if (!iifile.open(file1, std::ios::in))
		std::cout << "File does not exist!" << std::endl;
	else
	{
		TString str_line;
		std::istream iline(&iifile);
		int i=0;
//        while(iline) 
        for (int l=0;l<number;l++)
        {
			i++;
            str_line.ReadLine(iline);
			x[i]=str_line.Atof();
            std::cout << "x " <<i <<"="<< x[i]<< std::endl;
		}
    }
	//获取文件数据
    std::filebuf iiifile;
	if (!iiifile.open(file2, std::ios::in))
		std::cout << "File does not exist!" << std::endl;
	else
	{
		TString str_line;
		std::istream iline(&iiifile);
		int i=0;
        for (int l=0;l<number;l++)
        {
			i++;
            str_line.ReadLine(iline);
			hour[i]=str_line.Atof();
            hour[i]=hour[i]-start1;
            std::cout << "hour " <<i <<"="<< hour[i]<< std::endl;
		}
    }
    //获取文件数据
    std::filebuf iiiifile;
	if (!iiiifile.open(file3, std::ios::in))
		std::cout << "File does not exist!" << std::endl;
	else
	{
		TString str_line;
		std::istream iline(&iiiifile);
		int i=0;
        for (int l=0;l<number;l++)
        {
			i++;
            str_line.ReadLine(iline);
			minute[i]=str_line.Atof();
            minute[i]=minute[i]-start2;
            std::cout << "minute " <<i <<"="<< minute[i]<< std::endl;
		}
    }
    //获取文件数据
    std::filebuf iiiiifile;
	if (!iiiiifile.open(file4, std::ios::in))
		std::cout << "File does not exist!" << std::endl;
	else
	{
		TString str_line;
		std::istream iline(&iiiiifile);
		int i=0;
        for (int l=0;l<number;l++)
        {
			i++;
            str_line.ReadLine(iline);
			sec[i]=str_line.Atof();
            sec[i]=sec[i]-start3;
            std::cout << "second " <<i <<"="<< sec[i]<< std::endl;
		}
    }
    //获取文件数据
    std::filebuf iiiiiifile;
	if (!iiiiiifile.open(file5, std::ios::in))
		std::cout << "File does not exist!" << std::endl;
	else
	{
		TString str_line;
		std::istream iline(&iiiiiifile);
		int i=0;
        for (int l=0;l<number;l++)
        {
			i++;
            str_line.ReadLine(iline);
			channel[i]=str_line.Atof();
            channel[i]=channel[i];
            std::cout << "channelond " <<i <<"="<< channel[i]<< std::endl;
		}
    }
    //计算时间差
    for(int i=1;i<63;i++)
    {
        ttime[i]=hour[i]*3600 + minute[i]*60 + sec[i];
        cout<<"ttime"<<i<<"="<<ttime[i]<<endl;
    }
    //画图
    TCanvas *test = new TCanvas("test","test",1200,800);
    
    TH1F* h1 = new TH1F("h1","value",10000,0,9000);
    for(int k=1;k<63;k++)
    {
        h1->Fill(x[k]);
        std::cout << "x " <<k <<"="<< x[k]<< std::endl;
    
    }
    h1->GetXaxis()->SetTitle("X: value" );
    h1->GetYaxis()->SetTitle("Y: Number");

    TH1F* h2 =new TH1F("h2","ttime",1500,0,1500);
    for(int k=1;k<63;k++)
    {
        h2->Fill(ttime[k]);
        std::cout << "ttime " <<k <<"="<< ttime[k]<< std::endl;
    }
    h2->GetXaxis()->SetTitle("X: ttime/s" );
    h2->GetYaxis()->SetTitle("Y: Number");
    
    TH2F *h3 = new TH2F("h3","2d histo",1500,0,1500,10000,0,9000);
    for (int k=1;k<63;k++) {
         h3->Fill(ttime[k],x[k]) ; //填充2维直方图
    }
    h3->GetXaxis()->SetTitle("X: ttime/s" );
    h3->GetYaxis()->SetTitle("Y: value");

    TH1F* h4 =new TH1F("h4","channel-ttime",1500,0,1500);
    for(int k=1;k<63;k++)
    {
        if (channel[k]==0)   //选定channel号
        {
        h4->Fill(ttime[k]);
        std::cout << "ttime " <<k <<"="<< ttime[k]<< std::endl;
        }
    }
    h4->GetXaxis()->SetTitle("X: ttime/s" );
    h4->GetYaxis()->SetTitle("Y: Number");
    
    test->Divide(2,2);
    test->cd(1);
    h1->Draw();
    test->cd(2);
    h2->Draw();
    test->cd(3);
    h3->Draw();
    test->cd(4);
    h4->Draw();
}

