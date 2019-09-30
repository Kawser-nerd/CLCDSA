using System;
class Program{
	static void Main(){
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		long[] x=Array.ConvertAll(Console.ReadLine().Split(),long.Parse);
		long ans=0;
		for(int i=0;i<s[0]-1;i++){
			if((x[i+1]-x[i])*s[1]>s[2]){ans+=s[2];}
			else{ans+=(x[i+1]-x[i])*s[1];}
		}
		Console.WriteLine(ans);
	}
}