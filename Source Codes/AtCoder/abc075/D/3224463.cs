using System;
class Program{
	static int[] s;
	static void Main(){
		s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		long[][] arr=new long[2][];
		arr[0]=new long[s[0]];
		arr[1]=new long[s[0]];
		long ans=long.MaxValue;
		for(int i=0;i<s[0];i++){
			long[] q=Array.ConvertAll(Console.ReadLine().Split(),long.Parse);
			arr[0][i]=q[0];
			arr[1][i]=q[1];
		}
		int[,] w=new int[s[0]+1,s[0]+1];
		long[][] x=new long[s[0]+1][];
		long[][] y=new long[s[0]+1][];
		long[,] h=new long[s[0]+1,2];
		for(int i=1;i<=s[0];i++){
			x[i]=new long[]{arr[0][i-1],i};
			y[i]=new long[]{arr[1][i-1],i};
		}
		x[0]=new long[]{long.MinValue,0};
		y[0]=new long[]{long.MinValue,0};
		Array.Sort(x,ca);
		Array.Sort(y,ca);
		for(int i=1;i<=s[0];i++){
			h[x[i][1],0]=i;
			h[y[i][1],1]=i;
		}
		for(int i=1;i<=s[0];i++){w[h[i,0],h[i,1]]=1;}
		for(int i=1;i<=s[0];i++){
			for(int j=1;j<=s[0];j++){w[i,j]+=w[i,j-1];}
		}
		for(int i=1;i<=s[0];i++){
			for(int j=1;j<=s[0];j++){w[j,i]+=w[j-1,i];}
		}
		for(int i=1;i<s[0];i++){
			for(int j=i+1;j<=s[0];j++){
				for(int k=1;k<s[0];k++){
					for(int l=k+1;l<=s[0];l++){
						long a=Math.Min(h[i,0],h[j,0]);
						long b=Math.Min(h[k,1],h[l,1]);
						long c=Math.Max(h[i,0],h[j,0]);
						long d=Math.Max(h[k,1],h[l,1]);
						if(w[c,d]-w[a-1,d]-w[c,b-1]+w[a-1,b-1]>=s[1]){
							ans=Math.Min(ans,(x[c][0]-x[a][0])*(y[d][0]-y[b][0]));
						}
					}
				}
			}
		}
		Console.WriteLine("{0}",ans);
	}
	static int ca(long[] a,long[] b){
		if(a[0]>b[0]){return 1;}
		else if(a[0]<b[0]){return -1;}
		else{return 0;}
	}
}