using System;
using System.Collections.Generic;
class Program{
	static void Main(){
		string s=Console.ReadLine();
		long[] h=new long[26];
		long ans=1;
		for(int i=0;i<s.Length;i++){h[s[i]-'a']++;}
		for(int i=0;i<25;i++){
			for(int j=i+1;j<26;j++){ans+=h[i]*h[j];}
		}
		Console.WriteLine("{0}",ans);
	}
}