using System;
using System.Collections.Generic;
class Program{
	static void Main(){
		int s=int.Parse(Console.ReadLine());
		int[] a=new int[s];
		int[] b=new int[s];
		var hs=new Dictionary<int,int>();

		for(int i=0;i<s;i++){
			a[i]=int.Parse(Console.ReadLine());
			b[i]=a[i];
		}
		Array.Sort(b,ca);
		int c=0,d=-1;
		for(int i=0;i<s;i++){
			if(b[i]!=d){
				d=b[i];
				hs.Add(d,c);
				c++;
			}
		}
		for(int i=0;i<s;i++){Console.WriteLine("{0}",hs[a[i]]);}
	}
	static int ca(int a,int b){
		if(a>b){return 1;}
		else if(a<b){return -1;}
		else{return 0;}
	}
}