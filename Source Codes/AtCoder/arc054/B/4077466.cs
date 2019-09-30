using System;
using System.Collections.Generic;
using System.Linq;
class Program{
	const int mod=1000000007;
	static void Main(){
		double p=double.Parse(Console.ReadLine());
		double lb=0,ub=p,c1=p/3,c2=p/3*2,d1=0,d2=0;
		while(ub-lb>0.000000001){
			c1=(lb*2+ub)/3;
			c2=(lb+ub*2)/3;
			d1=p/Math.Pow(2,c1/1.5)+c1;
			d2=p/Math.Pow(2,c2/1.5)+c2;
			if(d1>d2){lb=c1;}
			else{ub=c2;}
		}
		Console.WriteLine("{0}",d1);
	}
}