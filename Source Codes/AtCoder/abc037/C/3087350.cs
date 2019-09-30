using System;
class Program{
	static void Main(){
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		long[] a=Array.ConvertAll(Console.ReadLine().Split(),long.Parse);
		long ans=0,n=0;
		for(int i=0;i<s[0];i++){
			n+=a[i];
			if(i>=s[1]-1){
				ans+=n;
				n-=a[i+1-s[1]];
			}
		}
		Console.WriteLine("{0}",ans);
	}
}