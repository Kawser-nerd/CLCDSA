using System;
class Program{
	static void Main(){
		int n=int.Parse(Console.ReadLine()),q=-1;
		int[] a=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		int[] h=new int[21];
		for(int j=0;j<21;j++){h[j]=-1;}
		long ans=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<21;j++){
				if((a[i]&(1<<j))!=0){
					q=Math.Max(q,h[j]);
					h[j]=i;
				}
			}
			ans+=i-q;
		}
		Console.WriteLine(ans);
	}
}