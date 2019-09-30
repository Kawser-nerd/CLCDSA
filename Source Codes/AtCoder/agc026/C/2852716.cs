using System;
using System.Collections.Generic;
using System.Text;
class Program{
	static int s;
	static string q;
	static Dictionary<string,int> hs=new Dictionary<string,int>();
	static StringBuilder u;
	static long ans=0;
	static void Main(){
		s=int.Parse(Console.ReadLine());
		q=Console.ReadLine();
		u=new StringBuilder(q.Substring(0,s));
		fu1(0,0,"");
		q=q.Substring(s);
		u=new StringBuilder(q);
		fu2(s-1,0,"");
		Console.WriteLine(ans);
	}
	static void fu2(int n,int k,string t){
		if(n>-1){
			fu2(n-1,k,t);
			u.Remove(n,1);
			u.Insert(n,"_");
			fu2(n-1,k+1,t+q[n]);
			u.Remove(n,1);
			u.Insert(n,q[n]);
		}
		else{
			string key=u.ToString();
			key=key.Replace("_","");
			key=k+" "+t+key;
			if(hs.ContainsKey(key)){ans+=hs[key];}
		}
	}
	static void fu1(int n,int k,string t){
		if(n<s){
			fu1(n+1,k,t);
			u.Remove(n,1);
			u.Insert(n,"_");
			fu1(n+1,k+1,t+q[n]);
			u.Remove(n,1);
			u.Insert(n,q[n]);
		}
		else{
			string key=u.ToString();
			key=key.Replace("_","");
			char[] a=key.ToCharArray();
			Array.Reverse(a);
			key=new string(a);
			key=k+" "+t+key;
			if(hs.ContainsKey(key)){hs[key]++;}
			else{hs.Add(key,1);}
		}
	}
}