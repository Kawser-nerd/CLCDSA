using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
static class Program{
	const int mod=1000000007;
	static void Main(){
		Sc sc=new Sc();
		int[] s=sc.Ia;
		int[][] a=new int[s[2]][];
		List<int[]> li=new List<int[]>();
		for(int i = 0;i<s[2];i++) {
			a[i]=sc.Ia;
			if((a[i][0]==0||a[i][0]==s[0]||a[i][1]==0||a[i][1]==s[1])&&(a[i][2]==0||a[i][2]==s[0]||a[i][3]==0||a[i][3]==s[1])){
				if(a[i][1]==0){li.Add(new int[]{a[i][0],i});}
				else if(a[i][0]==s[0]){li.Add(new int[]{a[i][1]+(int)2e8,i});}
				else if(a[i][1]==s[1]){li.Add(new int[]{(int)5e8-a[i][0],i});}
				else{li.Add(new int[]{(int)8e8-a[i][1],i});}
				if(a[i][3]==0){li.Add(new int[]{a[i][2],i});}
				else if(a[i][2]==s[0]){li.Add(new int[]{a[i][3]+(int)2e8,i});}
				else if(a[i][3]==s[1]){li.Add(new int[]{(int)5e8-a[i][2],i});}
				else{li.Add(new int[]{(int)8e8-a[i][3],i});}
			}
		}
		li.Sort((u,v)=>u[0]-v[0]);
		Stack<int> stk = new Stack<int>(new int[]{-1});
		for(int i = 0;i<li.Count;i++) {
			if(stk.Peek()!=li[i][1]){stk.Push(li[i][1]);}
			else{stk.Pop();}
		}
		Console.WriteLine(stk.Count==1?"YES":"NO");
	}
}

public class Sc{
	public int I{get{return int.Parse(Console.ReadLine());}}
	public long L{get{return long.Parse(Console.ReadLine());}}
	public double D{get{return double.Parse(Console.ReadLine());}}
	public string S{get{return Console.ReadLine();}}
	public int[] Ia{get{return Array.ConvertAll(Console.ReadLine().Split(),int.Parse);}}
	public int[] Ia2{get{return Array.ConvertAll(("0 "+Console.ReadLine()).Split(),int.Parse);}}
	public long[] La{get{return Array.ConvertAll(Console.ReadLine().Split(),long.Parse);}}
	public long[] La2{get{return Array.ConvertAll(("0 "+Console.ReadLine()).Split(),long.Parse);}}
	public double[] Da{get{return Array.ConvertAll(Console.ReadLine().Split(),double.Parse);}}
	public string[] Sa{get{return Console.ReadLine().Split();}}
}