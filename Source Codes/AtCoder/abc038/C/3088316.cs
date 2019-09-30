using System;
class Program{
	static void Main(){
		int n=int.Parse(Console.ReadLine()),m=0;
		int[] a=Array.ConvertAll(("0 "+Console.ReadLine()).Split(),int.Parse);
		long ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]>a[i-1]){m++;}
			else{m=1;}
			ans+=m;
		}
		Console.WriteLine("{0}",ans);
	}
}