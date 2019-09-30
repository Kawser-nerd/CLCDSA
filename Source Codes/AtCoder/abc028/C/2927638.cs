using System;
using System.Collections.Generic;
using System.Linq;
class Program{
	static bool[] b=new bool[5];
	static int[] s;
	static int ans=0;
	static List<int> li=new List<int>();
	static List<int> a=new List<int>();
	static void Main(){
		s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		fu1(0);
		IEnumerable<int> result=li.Distinct();
		foreach(int i in result){a.Add(i);}
		a.Sort();
		Console.WriteLine("{0}",a[a.Count-3]);
	}
	static void fu1(int a){
		for(int i=0;i<5;i++){
			if(!b[i]){
				ans+=s[i];
				if(a==2){li.Add(ans);}
				else{
					b[i]=true;
					fu1(a+1);
					b[i]=false;
				}
				ans-=s[i];
			}
		}
	}
}