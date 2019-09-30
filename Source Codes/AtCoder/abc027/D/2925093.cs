using System;
using System.Collections.Generic;
class Program{
	static void Main(){
		string s=Console.ReadLine();
		int ans=0,p=0,m=0;
		List<int> li=new List<int>();
		for(int i=0;i<s.Length;i++){
			if(s[i].ToString()=="+"){p++;}
			else if(s[i].ToString()=="-"){m++;}
		}
		for(int i=0;i<s.Length;i++){
			if(s[i].ToString()=="M"){li.Add(p-m);}
			else if(s[i].ToString()=="+"){p--;}
			else{m--;}
		}
		li.Sort();
		for(int i=0;i<li.Count;i++){
			if(i<li.Count/2){ans-=li[i];}
			else{ans+=li[i];}
		}
		Console.WriteLine("{0}",ans);
	}
}