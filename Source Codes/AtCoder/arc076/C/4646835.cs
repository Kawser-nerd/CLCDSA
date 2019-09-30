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
		string ans="YES";
		bool[] b=new bool[s[2]];
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
				b[i]=true;
			}
			a[i][0]=-1;
			a[i][1]=-1;
		}
		li.Sort((u,v)=>u[0]-v[0]);
		St st1=new St(0,li.Count,true);
		St st2=new St(0,li.Count,false);
		for(int i = 0;i<li.Count;i++) {
			if(a[li[i][1]][0]==-1){a[li[i][1]][0]=i;}
			else{
				st1.Ud(a[li[i][1]][0],i);
				st2.Ud(a[li[i][1]][0],i);
				st1.Ud(i,a[li[i][1]][0]);
				st2.Ud(i,a[li[i][1]][0]);
				a[li[i][1]][1]=i;
			}
		}
		for(int i = 0;i<s[2];i++) {
			if(b[i]&&a[i][1]-a[i][0]!=1){
				if(st1.Get(a[i][0]+1,a[i][1]-1).d>a[i][1]||st2.Get(a[i][0]+1,a[i][1]-1).d<a[i][0]){ans="NO";}
			}
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
		dat=new Mo[m+n-1];
		for(int i=0;i<m+n-1;i++){dat[i]=du;}
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
	public int[] Ia2{get{return Array.ConvertAll(("0 "+Console.ReadLine()).Split(),int.Parse);}}
	public long[] La{get{return Array.ConvertAll(Console.ReadLine().Split(),long.Parse);}}
	public long[] La2{get{return Array.ConvertAll(("0 "+Console.ReadLine()).Split(),long.Parse);}}
	public double[] Da{get{return Array.ConvertAll(Console.ReadLine().Split(),double.Parse);}}
	public string[] Sa{get{return Console.ReadLine().Split();}}
}