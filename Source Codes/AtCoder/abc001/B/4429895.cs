class Program {
	static void Main(System.String[] args){
		int m = int.Parse(System.Console.ReadLine());
      	int vv = 0;
      	if(m<100)vv=0;
      	else if(m<=5000)vv=m/100;
      	else if(m<=30000)vv=m/1000+50;
      	else if(m<=70000)vv=(m/1000-30)/5+80;
      	else vv = 89;
      	System.Console.WriteLine("{0:D02}",vv);
    }
}