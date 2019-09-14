TString file1="value";
TString file2="hour";
TString file3="minute";
TString file4="second";
TString file5="chnel";
TString file6="style";
double x[62];
double hour[62];
double start1=22;
double min[62];
double start2=38;
double sec[62];
double start3=48;
double time[62];
double ch[62];
TString style[62];
void getfile(){
	std::filebuf ifile;
	if (!ifile.open(file1, std::ios::in))
		std::cout << "File does not exist!" << std::endl;
	else
	{
		TString str_line;
		std::istream iline(&ifile);
		int i=0;
//        while(iline) 
        for (int l=0;l<62;l++)
        {
			i++;
            str_line.ReadLine(iline);
			x[i]=str_line.Atof();
            std::cout << "x " <<i <<"="<< x[i]<< std::endl;
            //std::cout << x[i]<< std::endl;
		}
    }
	
    std::filebuf ifile;
	if (!ifile.open(file2, std::ios::in))
		std::cout << "File does not exist!" << std::endl;
	else
	{
		TString str_line;
		std::istream iline(&ifile);
		int i=0;
//        while(iline) 
        for (int l=0;l<62;l++)
        {
			i++;
            str_line.ReadLine(iline);
			hour[i]=str_line.Atof();
            hour[i]=hour[i]-start1;
            std::cout << "hour " <<i <<"="<< hour[i]<< std::endl;
            //std::cout << x[i]<< std::endl;
		}
    }
    
    std::filebuf ifile;
	if (!ifile.open(file3, std::ios::in))
		std::cout << "File does not exist!" << std::endl;
	else
	{
		TString str_line;
		std::istream iline(&ifile);
		int i=0;
//        while(iline) 
        for (int l=0;l<62;l++)
        {
			i++;
            str_line.ReadLine(iline);
			min[i]=str_line.Atof();
            min[i]=min[i]-start2;
            std::cout << "min " <<i <<"="<< min[i]<< std::endl;
            //std::cout << x[i]<< std::endl;
		}
    }

    std::filebuf ifile;
	if (!ifile.open(file4, std::ios::in))
		std::cout << "File does not exist!" << std::endl;
	else
	{
		TString str_line;
		std::istream iline(&ifile);
		int i=0;
//        while(iline) 
        for (int l=0;l<62;l++)
        {
			i++;
            str_line.ReadLine(iline);
			sec[i]=str_line.Atof();
            sec[i]=sec[i]-start3;
            std::cout << "second " <<i <<"="<< sec[i]<< std::endl;
            //std::cout << x[i]<< std::endl;
		}
    }
    
    for(int i=1;i<63;i++)
    {
        time[i]=hour[i]*3600 + min[i]*60 + sec[i];
        cout<<"time"<<i<<"="<<time[i]<<endl;
    }
    
    TCanvas *test = new TCanvas("test","test",1200,800);
    
    TH1F* h1 = new TH1F("h1","value",10000,0,9000);
    for(int k=1;k<63;k++)
    {
        h1->Fill(x[k]);
        std::cout << "x " <<k <<"="<< x[k]<< std::endl;
    
    }
    h1->GetXaxis()->SetTitle("X: value" );
    h1->GetYaxis()->SetTitle("Y: Number");

    TH1F* h2 =new TH1F("h2","time",1500,0,1500);
    for(int k=1;k<63;k++)
    {
        h2->Fill(time[k]);
        std::cout << "time " <<k <<"="<< time[k]<< std::endl;
    }
    h2->GetXaxis()->SetTitle("X: time/s" );
    h2->GetYaxis()->SetTitle("Y: Number");
    
    TH2F *h3 = new TH2F("h3","2d histo",1500,0,1500,10000,0,9000);
    for (int k=1;k<63;k++) {
         h3->Fill(time[k],x[k]) ; //填充2维直方图
    }
    h3->GetXaxis()->SetTitle("X: time/s" );
    h3->GetYaxis()->SetTitle("Y: value");

    test->Divide(2,2);
    test->cd(1);
    h1->Draw();
    test->cd(2);
    h2->Draw();
    test->cd(3);
    h3->Draw();
//    test->cd(4);
//    h4->Draw();
}

