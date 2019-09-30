using System;
class Program{
	static void Main(){
		long[] s=Array.ConvertAll(Console.ReadLine().Split(),long.Parse);
		string ans="NO";
		for(int i=0;i<=s[0]/2;i++){
			long a=(s[0]-i-1)*s[3]-i*s[4];
			long b=(s[0]-i-1)*s[4]-i*s[3];
			if(s[1]+a<=s[2]&&s[1]+b>=s[2]){ans="YES";break;}
			else if(s[1]-b<=s[2]&&s[1]-a>=s[2]){ans="YES";break;}
		}
		Console.WriteLine("{0}",ans);
	}
}