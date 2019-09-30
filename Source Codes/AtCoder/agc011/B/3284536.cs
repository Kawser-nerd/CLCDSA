using System;
class Program{
	static void Main(){
		int n=int.Parse(Console.ReadLine());
		long[] a=Array.ConvertAll(Console.ReadLine().Split(),long.Parse);
		Array.Sort(a);
		long ans=1,r=a[0];
		for(int i=1;i<n;i++){
			if(r*2>=a[i]){ans++;}
			else{ans=1;}
			r+=a[i];
		}
		Console.WriteLine("{0}",ans);
	}
}