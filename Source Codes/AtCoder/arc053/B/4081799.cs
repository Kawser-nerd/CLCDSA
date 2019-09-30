using System;
using System.Collections.Generic;
using System.Linq;
class Program{
	static void Main(){
		string s=Console.ReadLine();
		int[] h=new int[123];
		int a=0;
		for(int i=0;i<s.Length;i++){h[s[i]]++;}
		for(int i=97;i<123;i++){if(h[i]%2==1){a++;}}
		Console.WriteLine("{0}",a==0?s.Length:(((s.Length/a)&1)==1?(s.Length/a):(s.Length/a-1)));
	}
}