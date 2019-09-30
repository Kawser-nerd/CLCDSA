using System;
using System.Collections.Generic;
using System.Linq;
class Program{
	const int mod=1000000007;
	static void Main(){
		const long m=2000000000000;
		long[] s=Array.ConvertAll(Console.ReadLine().Split(),long.Parse);
		long a=0;
		if(s[1]!=0){
			while(s[0]<m){
				s[0]+=s[0]*s[1]+1;
				a++;
			}
		}
		else{a=m-s[0];}
		Console.WriteLine("{0}",a);
	}
}