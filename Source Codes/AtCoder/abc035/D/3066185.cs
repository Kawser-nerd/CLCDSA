using System;
using System.Collections.Generic;
class Program{
	static List<long[]>[] arr;
	static List<long[]>[] gg;
	static List<long[]> he=new List<long[]>();
	static void Main(){
		long[] s=Array.ConvertAll(Console.ReadLine().Split(),long.Parse);
		long[] a=Array.ConvertAll(Console.ReadLine().Split(),long.Parse);
		arr=new List<long[]>[s[0]+1];
		gg=new List<long[]>[s[0]+1];
		long[] hs=new long[s[0]+1];
		long[] hsg=new long[s[0]+1];
		for(long i=1;i<=s[0];i++){arr[i]=new List<long[]>();gg[i]=new List<long[]>();hs[i]=10000000000000;hsg[i]=10000000000000;}
		for(long i=0;i<s[1];i++){
			long[] q=Array.ConvertAll(Console.ReadLine().Split(),long.Parse);
			arr[q[0]].Add(new long[]{q[2],q[1]});
			gg[q[1]].Add(new long[]{q[2],q[0]});
		}

		hs[1]=0;
		foreach(long[] j in arr[1]){heapa(j[0],j[1]);}
		while(he.Count>0){
			if(hs[he[0][1]]>he[0][0]){
				long n=he[0][1];
				hs[n]=he[0][0];
				heapr();
				foreach(long[] j in arr[n]){heapa(j[0]+hs[n],j[1]);}
			}
			else{heapr();}
		}

		hsg[1]=0;
		foreach(long[] j in gg[1]){heapa(j[0],j[1]);}
		while(he.Count>0){
			if(hsg[he[0][1]]>he[0][0]){
				long n=he[0][1];
				hsg[n]=he[0][0];
				heapr();
				foreach(long[] j in gg[n]){heapa(j[0]+hsg[n],j[1]);}
			}
			else{heapr();}
		}
		long ans=0;
		for(long i=1;i<=s[0];i++){ans=Math.Max(ans,(s[2]-hs[i]-hsg[i])*a[i-1]);}
		Console.WriteLine("{0}",ans);
	}
	static void heapa(long a,long b){
		he.Add(new long[]{a,b});
		int j=he.Count-1;
		while(he[j][0]<he[(j-1)/2][0]){
			long v=he[j][0];
			he[j][0]=he[(j-1)/2][0];
			he[(j-1)/2][0]=v;

			v=he[j][1];
			he[j][1]=he[(j-1)/2][1];
			he[(j-1)/2][1]=v;
			j=(j-1)/2;
		}
	}
	static void heapr(){
		he[0][0]=he[he.Count-1][0];
		he[0][1]=he[he.Count-1][1];
		he.RemoveAt(he.Count-1);
		int j=0;
		while(true){
			if(j*2+2<he.Count){
				if(he[j*2+1][0]<he[j*2+2][0]){j=j*2+1;}
				else{j=j*2+2;}
			}
			else if(j*2+1<he.Count){j=j*2+1;}
			else{break;}
			if(he[j][0]>=he[(j-1)/2][0]){break;}
			long v=he[j][0];
			he[j][0]=he[(j-1)/2][0];
			he[(j-1)/2][0]=v;

			v=he[j][1];
			he[j][1]=he[(j-1)/2][1];
			he[(j-1)/2][1]=v;
		}
	}
}