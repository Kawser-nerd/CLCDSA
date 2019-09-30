using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
static class Program{
	const int mod=1000000007;
	const long o=1;
	static void Main(){
		Sc sc=new Sc();
		int n=sc.I;
		St2 st=new St2(1,200000);
		var sb=new StringBuilder();
		for(int i = 0;i<n;i++) {
			int[] q=sc.Ia;
			if(q[0]==1){st.Ud(q[1],1);}
			else{
				int lb=0,ub=200000,mid=0;
				while(ub-lb>1){
					mid=(ub+lb)/2;
					if(st.Get(1,mid)>q[1]-1){ub=mid;}
					else{lb=mid;}
				}
				sb.Append(ub+"\n");
				st.Ud(ub,-1);
			}
		}
		Console.Write(sb);
	}
}
public class St2{
	private long[] dat,dat2;
	private int m=1,f,sr=1,count=0;
	public St2(int f,int n){
		this.f=f;
		n+=f^1;
		while(m<n){m*=2;sr+=sr;}
		count=m+n-1;
		dat=new long[count];
		dat2=new long[count];
	}
	public void Ud(int q,long b){
		q+=m-1-f;
		dat[q]+=b;
		while(q>0){
			dat[(q-1)/2]=dat[(q-1)/2]+b;
			q=(q-1)/2;
		}
	}
	private long Fdg(int a,int b,int k,int l,int r){
		if(dat2[k]!=0){
			dat[k]+=dat2[k];
			if(2*k+1<count){dat2[2*k+1]+=dat2[k]/2;}
			if(2*k+2<count){dat2[2*k+2]+=dat2[k]/2;}
			dat2[k]=0;
		}
		if(r<a||b<l){return 0;}
		if(a<=l&&r<=b){return dat[k];}
		else{return Fdg(a,b,k*2+1,l,(l+r)/2)+Fdg(a,b,k*2+2,(l+r+1)/2,r);}
	}
	public long Get(int a,int b){return Fdg(a,b,0,f,m-(f^1));}
	public void Ud2(int a,int b,long d){Hn(a,b,0,f,m-(f^1),d*sr);}
	private long Hn(int a,int b,int k,int l,int r,long d){
		if(a<=l&&r<=b){dat2[k]+=d;return d;}
		else if(r>=a&&b>=l){
			long q=Hn(a,b,k*2+1,l,(l+r)/2,d/2);
			q+=Hn(a,b,k*2+2,(l+r+1)/2,r,d/2);
			dat[k]+=q;
			return q;
		}
		return 0;
	}
}

public class Sc{
	public int I{get{return int.Parse(Console.ReadLine());}}
	public long L{get{return long.Parse(Console.ReadLine());}}
	public double D{get{return double.Parse(Console.ReadLine());}}
	public string S{get{return Console.ReadLine();}}
	public int[] Ia{get{return Array.ConvertAll(Console.ReadLine().Split(),int.Parse);}}
	public long[] La{get{return Array.ConvertAll(Console.ReadLine().Split(),long.Parse);}}
	public long[] La2{get{return Array.ConvertAll(("0 "+Console.ReadLine()).Split(),long.Parse);}}
	public double[] Da{get{return Array.ConvertAll(Console.ReadLine().Split(),double.Parse);}}
	public string[] Sa{get{return Console.ReadLine().Split();}}
}