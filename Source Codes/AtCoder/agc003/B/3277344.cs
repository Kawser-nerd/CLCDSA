using System;
class Program{
	static void Main(){
		int n=int.Parse(Console.ReadLine());
		long[] a=new long[n];
		a[0]=int.Parse(Console.ReadLine());
		long ans=a[0]/2;
		a[0]%=2;
		for(int i=1;i<n;i++){
			a[i]=int.Parse(Console.ReadLine());
			ans+=(a[i-1]+a[i])/2;
			a[i]=a[i]>0?((a[i-1]+a[i])%2):0;
		}
		Console.WriteLine("{0}",ans);
	}
}