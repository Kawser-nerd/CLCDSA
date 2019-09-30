using System;
class Program{
	static void Main(){
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		long[] a=Array.ConvertAll(Console.ReadLine().Split(),long.Parse);
		long[] b=new long[s[0]+1],c=new long[s[0]+1];
		b[1]=a[0];
		c[1]=a[0]>0?a[0]:0;
		for(int i=1;i<s[0];i++){
			b[i+1]+=a[i]+b[i];
			c[i+1]+=(a[i]>0?a[i]:0)+c[i];
		}
		long ans=long.MinValue;
		for(int i=s[1];i<=s[0];i++){
			ans=Math.Max(Math.Max(ans,b[i]-b[i-s[1]]+c[i-s[1]]+c[s[0]]-c[i]),c[i-s[1]]+c[s[0]]-c[i]);
		}
		Console.WriteLine("{0}",ans);
	}
}