using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
static class Program{
	const int mod=1000000007;
	static void Main(){
		Sc sc=new Sc();
		int n=sc.I;
		int[] a=sc.Ia2;
		int l=sc.I;
		int[] tr=new int[n+1];
		int[] kr=new int[n+1];
		int m=n,t=0,b=0;
		for(int i = n-1;i>0;i--) {
			while(a[m]-a[i]>l){m--;}
			tr[i]=m;
			kr[i]=kr[m]+1;
			t=Math.Max(t,kr[i]);
		}
		m=1;
		while(m<t){m<<=1;b++;}
		if(b==0){b=1;}
		int[][] h=new int[b][];
		h[0]=new int[n+1];
		for(int j = 0;j<=n;j++) {h[0][j]=tr[j];}
		h[0][n]=n;
		for(int i = 1;i<b;i++) {
			h[i]=new int[n+1];
			for(int j = 0;j<=n;j++) {
				h[i][j]=h[i-1][h[i-1][j]];
			}
		}
		int q=sc.I;
		int[] ans=new int[q];
		for(int i = 0;i<q;i++) {
			int[] e=sc.Ia;
			if(e[0]>e[1]){e[0]^=e[1];e[1]^=e[0];e[0]^=e[1];}
			int p=e[0],r=b-1;
			while(ans[i]==0){
				for(;r>=0;r--) {
					if(h[r][p]==e[1]){
						ans[i]=kr[e[0]]-kr[e[1]];
						break;
					}
					else if(h[r][p]<e[1]){
						p=h[r][p];
						r--;
						break;
					}
				}
				if(r==-1){
					ans[i]=kr[e[0]]-kr[h[0][p]];
					break;
				}
			}
		}
		Console.WriteLine("{0}",String.Join("\n",ans));
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