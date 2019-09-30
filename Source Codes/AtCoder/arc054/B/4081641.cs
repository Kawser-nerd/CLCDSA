using System;
using System.Collections.Generic;
using System.Linq;
class Program{
	const int mod=1000000007;
	static void Main(){
		double p=double.Parse(Console.ReadLine());
		Console.WriteLine("{0}",Gss(0,p));
	}
	static double phi=(1+Math.Sqrt(5))*0.5;
	static double Gss(double a,double b){
		double lb=a,ub=b,c1=0,c2=0,d1=0,d2=0;
		c1=(lb*phi+ub)/(1+phi);
		c2=(lb+phi*ub)/(1+phi);
		while(ub-lb>1e-9){
			d1=b/Math.Pow(2,c1/1.5)+c1;
			d2=b/Math.Pow(2,c2/1.5)+c2;
			if(d1>d2){lb=c1;c1=c2;c2=(lb+phi*ub)/(1+phi);}
			else{ub=c2;c2=c1;c1=(lb*phi+ub)/(1+phi);}
		}
		return d1;
	}
}