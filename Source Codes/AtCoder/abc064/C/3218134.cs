using System;
class Program{
	static void Main(){
		int n=int.Parse(Console.ReadLine());
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		int[] h=new int[9];
		for(int i=0;i<n;i++){h[s[i]/400<9?s[i]/400:8]++;}
		int ans=0;
		for(int i=0;i<8;i++){ans+=h[i]>0?1:0;}
		if(ans==0){ans=1;h[8]--;}
		Console.WriteLine("{0} {1}",ans,ans+h[8]);
	}
}