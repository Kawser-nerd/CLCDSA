using System;
class Program{
	static void Main(){
		long[] s=Array.ConvertAll(Console.ReadLine().Split(),long.Parse);
		long[] a=Array.ConvertAll(Console.ReadLine().Split(),long.Parse);
		long[,] h=new long[s[0],s[0]];
		long ans=long.MaxValue;
		for(int i=0;i<s[0];i++){
			h[i,0]=a[i];
			long q=a[i],k=1;
			for(long j=s[0]+i-1;j!=i;j--,k++){
				h[i,k]=Math.Min(a[j%s[0]],h[i,k-1]);
			}
		}
		for(int i=0;i<s[0];i++){
			long q=i*s[1];
			for(int j=0;j<s[0];j++){q+=h[j,i];}
			ans=Math.Min(ans,q);
		}
		Console.WriteLine("{0}",ans);
	}
}