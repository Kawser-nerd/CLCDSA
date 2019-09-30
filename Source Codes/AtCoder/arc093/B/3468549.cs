using System;
using System.Collections.Generic;
class Program{
	static void Main(){
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		List<string> li=new List<string>();
		li.Add(new string('.',100));
		li.Add(new string('#',100));
		s[0]--;
		s[1]--;
		while(s[1]>0){
			if(li[0].Length!=100){li[0]+=".#";}
			else{
				li.Insert(0,new string('.',100));
				li.Insert(0,".#");
			}
			s[1]--;
		}
		li[0]+=new string('.',100-li[0].Length);
		while(s[0]>0){
			if(li[li.Count-1].Length!=100){li[li.Count-1]+=".#";}
			else{
				li.Add(new string('#',100));
				li.Add(".#");
			}
			s[0]--;
		}
		li[li.Count-1]+=new string('#',100-li[li.Count-1].Length);
		Console.WriteLine("{0} 100",li.Count);
		Console.WriteLine(String.Join("\n",li));
	}
}