using System;
class Program{
	static void Main(){
		long[] s=Array.ConvertAll(Console.ReadLine().Split(),long.Parse);
		long[][] h=new long[s[0]+1][];
		long[] a=new long[s[0]+1];
		long[] b=new long[s[0]+1];
		long[] c=new long[s[0]+1];
		long[] d=new long[s[0]+1];
		h[0]=new long[2];
		long ans=0,k=0;
		for(int i=1;i<=s[0];i++){
			h[i]=Array.ConvertAll(Console.ReadLine().Split(),long.Parse);
			a[i]=a[i-1]+h[i][1]-(h[i][0]-h[i-1][0]);
			c[i]=Math.Max(c[i-1],a[i]-h[i][0]);
		}
		for(int i=1;i<=s[0];i++){
			b[i]=b[i-1]+k-(s[1]-h[s[0]+1-i][0])+h[s[0]+1-i][1];
			k=s[1]-h[s[0]+1-i][0];
			d[i]=Math.Max(d[i-1],b[i]-k);
			ans=Math.Max(ans,Math.Max(a[i],Math.Max(d[i]+a[s[0]-i],Math.Max(b[i],b[i]+c[s[0]-i]))));
		}
		Console.WriteLine(ans);
	}
}