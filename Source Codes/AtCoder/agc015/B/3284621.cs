using System;
class Program{
	static void Main(){
		string s=Console.ReadLine();
		long l=s.Length-1,ans=l*2;
		for(int i=1;i<l;i++){
			if(s[i]=='U'){ans+=i*2+l-i;}
			else{ans+=i+(l-i)*2;}
		}
		Console.WriteLine("{0}",ans);
	}
}