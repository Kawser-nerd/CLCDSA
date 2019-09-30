using System;
class Program{
	static void Main(){
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		long ans=0;
		for(int i=s[1]+1;i<=s[0];i++){
			ans+=(s[0]-i+1)/i*(i-s[1])+((s[0]-i+1)%i>s[1]?((s[0]-i+1)%i-s[1]):0)+i-s[1];
		}
		ans-=s[1]==0?s[0]:0;
		Console.WriteLine("{0}",ans);
	}
}