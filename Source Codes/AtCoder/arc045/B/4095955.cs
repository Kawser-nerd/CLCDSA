using System;
using System.Collections.Generic;
using System.Linq;
class Program{
	static void Main(){
		Sc sc=new Sc();
		int[] s=sc.Ia;
		int[][] a=new int[s[1]+1][];
		int[] h=new int[s[0]+2];
		St st=new St(1,s[0]);
		for(int i=1;i<=s[1];i++){
			a[i]=sc.Ia;
			h[a[i][0]]++;
			h[a[i][1]+1]--;
		}
		for(int i=1;i<=s[0];i++){
			h[i]+=h[i-1];
			st.Ud(i,h[i]);
		}
		List<int> li=new List<int>();
		for(int i=1;i<=s[1];i++){
			if(st.Get(a[i][0],a[i][1]).d>1){li.Add(i);}
		}
		Console.WriteLine(li.Count);
		if(li.Count!=0){Console.WriteLine(String.Join("\n",li));}
	}
}
public class St{
	public class Mo{
		public int n;
		public long d;
		public Mo(long d,int n){this.d=d;this.n=n;}
	}
	private Mo[] dat;
	private int m=1,f;
	private Mo du=new Mo(long.MaxValue,-1);//
	public St(int f,int n){
		this.f=f;
		n+=f^1;
		while(m<n){m*=2;}
		dat=new Mo[m+n-1];
		for(int i=0;i<m+n-1;i++){dat[i]=du;}
	}
	private bool Compare(Mo x,Mo y){return x.d<y.d;}//
	public void Ud(int q,long b){
		q+=m-1-f;
		if(dat[q]==du){
			int z=q;
			dat[q]=new Mo(b,q-(m-1-f));
			while(q>0&&Compare(dat[z],dat[(q-1)/2])){
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
				Mo o=Compare(dat[2*q+1],dat[2*q+2])?dat[2*q+1]:dat[2*q+2];
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
		return Compare(p,q)?p:q;
	}
	public Mo Get(int a,int b){return Fdg(a,b,0,f,m-(f^1));}
}

class Sc{
	public int I{get{return int.Parse(Console.ReadLine());}}
	public long L{get{return long.Parse(Console.ReadLine());}}
	public double D{get{return double.Parse(Console.ReadLine());}}
	public string S{get{return Console.ReadLine();}}
	public int[] Ia{get{return Array.ConvertAll(Console.ReadLine().Split(),int.Parse);}}
	public long[] La{get{return Array.ConvertAll(Console.ReadLine().Split(),long.Parse);}}
	public double[] Da{get{return Array.ConvertAll(Console.ReadLine().Split(),double.Parse);}}
}