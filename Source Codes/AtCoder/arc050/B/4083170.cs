using System;
using System.Collections.Generic;
using System.Linq;
class Program{
	static long[] s;
	static int[] t;
	static void Main(){
		s=Array.ConvertAll(Console.ReadLine().Split(),long.Parse);
		t=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		long m=Math.Min(s[0]/t[0],s[1]);
		long ans=Math.Max(Math.Min((s[1]-m)/t[1],s[0]-m*t[0])+m,Math.Min(s[1]/t[1],s[0]));
		long q=Tst(0,m);
		for(long i=Math.Min(q+100,m);i>=Math.Max(q-100,0);i--){ans=Math.Max(ans,Math.Min((s[1]-i)/t[1],s[0]-i*t[0])+i);}
		Console.WriteLine("{0}",ans);
	}
	static long Tst(long a,long b){
		long lb=a,ub=b,c1=0,c2=0,d1=0,d2=0;
		while(ub-lb>4){
			c1=(lb*2+ub)/3;
			c2=(lb+ub*2)/3;
			d1=Math.Min((s[1]-c1)/t[1],s[0]-c1*t[0])+c1;
			d2=Math.Min((s[1]-c2)/t[1],s[0]-c2*t[0])+c2;
			if(d1<d2){lb=c1;}
			else{ub=c2;}
		}
		return c1;
	}
}