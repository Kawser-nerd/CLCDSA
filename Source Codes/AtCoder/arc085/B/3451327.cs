using System;
class Program{
	static void Main(){
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		long[] a=Array.ConvertAll(Console.ReadLine().Split(),long.Parse);
		long ans=Math.Abs(s[2]-a[s[0]-1]);
		if(s[0]>1){ans=Math.Max(ans,Math.Abs(a[s[0]-2]-a[s[0]-1]));}
		Console.WriteLine(ans);
	}
}