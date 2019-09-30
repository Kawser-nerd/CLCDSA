using System;
using System.Collections.Generic;
class Program{
	static void Main(){
		int n=int.Parse(Console.ReadLine());
		long[] s=Array.ConvertAll(Console.ReadLine().Split(),long.Parse);
		string ans="-1";
		long a=2,b=3;
		bool d=false;
		if(s[n-1]==2){
			for(int i=n-2;i>=0;i--){
				if(s[i]>b){d=true;break;}
				else if(a%s[i]!=0){a=a+(s[i]-(a%s[i]));}
				b+=(s[i]-(b%s[i])-1);
				if(a>b){d=true;break;}
			}
			if(!d){ans=a.ToString()+" "+b.ToString();}
		}
		Console.WriteLine("{0}",ans);
	}
}