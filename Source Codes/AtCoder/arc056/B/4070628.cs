using System;
using System.Collections.Generic;
using System.Linq;
class Program{
	static List<int>[] li;
	static int[] h;
	static void Main(){
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		h=new int[s[0]+1];
		li=new List<int>[s[0]+1];
		List<int> ans=new List<int>();
		for(int i=1;i<=s[0];i++){li[i]=new List<int>();}
		for(int i=0;i<s[1];i++){
			int[] q=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
			li[q[0]].Add(q[1]);
			li[q[1]].Add(q[0]);
		}
		ans.Add(s[2]);
		Fu(s[2],s[2]);
		for(int i=s[2]-1;i>0;i--){
			if((h[i]&2)==2){
				Fu(i,i);
				ans.Add(i);
			}
		}
		ans.Sort();
		Console.WriteLine(String.Join("\n",ans));
	}
	static void Fu(int a,int b){
		h[a]|=1;
		for(int j=0;j<li[a].Count;j++){
			if((h[li[a][j]]&1)==0&&li[a][j]>b){Fu(li[a][j],b);}
			else if(li[a][j]<b){h[li[a][j]]|=2;}
		}
	}
}