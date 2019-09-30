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
		for(int i=0;i<s[0];i++){a[i]=sc.Ia;}
		Array.Sort(a,(u,v)=>(u[1]-u[0])-(v[1]-v[0]));
		St2 st=new St2(1,s[1]);
		StringBuilder sb=new StringBuilder();
		for(int i=1,j=0;i<=s[1];i++){
			while(j<s[0]&&a[j][1]-a[j][0]<i){
				if(a[j][1]==a[j][0]){st.Ud(a[j][0],1);}
				else{st.Ud2(a[j][0],a[j][1],1);}
				j++;
			}
			long ans=s[0]-j;
			for(int k=0;k<=s[1];k+=i){ans+=st.Get(k,k);}
			sb.Append(ans+"\n");
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
		count=m+n;
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
	public int[] Ia2{get{return Array.ConvertAll(("0 "+Console.ReadLine()).Split(),int.Parse);}}
	public long[] La{get{return Array.ConvertAll(Console.ReadLine().Split(),long.Parse);}}
	public long[] La2{get{return Array.ConvertAll(("0 "+Console.ReadLine()).Split(),long.Parse);}}
	public double[] Da{get{return Array.ConvertAll(Console.ReadLine().Split(),double.Parse);}}
	public string[] Sa{get{return Console.ReadLine().Split();}}
}