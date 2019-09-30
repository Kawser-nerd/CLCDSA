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
		int[][] a=new int[s[0]][];
		if(s[1]==1){Console.WriteLine(s[0]);return;}
		int[] h=new int[s[0]];
		bool[] b=new bool[s[1]+1];
		St st=new St(1,s[1],true);
		for(int i = 0;i<s[0];i++) {
			a[i]=sc.Ia;
			st.Ud(a[i][0],1);
		}
		long ans=Math.Min(s[0],st.Get(1,s[1]).d);
		for(int k = 0;k<s[1]-1;k++) {
			int q=st.Get(1,s[1]).n;
			st.Ud(q,-st.Get(1,s[1]).d);
			b[q]=true;
			for(int i = 0;i<s[0];i++) {
				if(a[i][h[i]]==q){
					while(b[a[i][h[i]]]){h[i]++;}
					st.Ud(a[i][h[i]],1);
				}
			}
			ans=Math.Min(ans,st.Get(1,s[1]).d);
		}
		Console.WriteLine(ans);
	}
}
public class St{
	public class Mo{
		public int n;
		public long d;
		public Mo(long d,int n){this.d=d;this.n=n;}
	}
	public Mo[] dat;
	private int m=1,f;
	private bool mm;
	private Mo du;
	private Func<Mo,Mo,bool> compare;
	public St(int f,int n,bool mm){
		this.f=f;
		n+=f^1;
		this.mm=mm;
		if(mm){du=new Mo(long.MinValue,-1);compare=CoMax;}
		else{du=new Mo(long.MaxValue,-1);compare=CoMin;}
		while(m<n){m*=2;}
		dat=new Mo[m+n];
		for(int i=0;i<m+n;i++){dat[i]=du;}
	}
	private bool CoMax(Mo x,Mo y){return x.d>y.d;}
	private bool CoMin(Mo x,Mo y){return x.d<y.d;}
	public void Ud(int q,long b){
		q+=m-1-f;
		if(dat[q]==du){
			int z=q;
			dat[q]=new Mo(b,q-(m-1-f));
			while(q>0&&compare(dat[z],dat[(q-1)/2])){
				dat[(q-1)/2]=dat[z];
				q=(q-1)/2;
			}
		}
		else{
			b+=dat[q].d;
			dat[q].d=du.d;
			dat[q]=new Mo(b,q-(m-1-f));
			q=(q-1)/2;
			while(q>=0){
				Mo o=compare(dat[2*q+1],dat[2*q+2])?dat[2*q+1]:dat[2*q+2];
				if(dat[q]==o){break;}
				dat[q]=o;
				q=(q-1)/2;
			}
		}
	}
	private Mo Fdg(int a,int b,int k,int l,int r){
		if(r<a||b<l){return du;}
		if(a<=l&&r<=b){return dat[k];}
		Mo p=Fdg(a,b,k*2+1,l,(l+r)/2);
		Mo q=Fdg(a,b,k*2+2,(l+r+1)/2,r);
		return compare(p,q)?p:q;
	}
	public Mo Get(int a,int b){return Fdg(a,b,0,f,m-(f^1));}
}

public class Sc{
	public int I{get{return int.Parse(Console.ReadLine());}}
	public long L{get{return long.Parse(Console.ReadLine());}}
	public double D{get{return double.Parse(Console.ReadLine());}}
	public string S{get{return Console.ReadLine();}}
	public int[] Ia{get{return Array.ConvertAll(Console.ReadLine().Split(),int.Parse);}}
	public int[] Ia2{get{return Array.ConvertAll((Console.ReadLine()+" 0").Split(),int.Parse);}}
	public long[] La{get{return Array.ConvertAll(Console.ReadLine().Split(),long.Parse);}}
	public long[] La2{get{return Array.ConvertAll(("0 "+Console.ReadLine()).Split(),long.Parse);}}
	public double[] Da{get{return Array.ConvertAll(Console.ReadLine().Split(),double.Parse);}}
	public string[] Sa{get{return Console.ReadLine().Split();}}
}