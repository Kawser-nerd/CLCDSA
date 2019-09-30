using System;
class Program{
	static void Main(){
		string s=Console.ReadLine();
		int n=int.Parse(Console.ReadLine());
		int a=0,b=0,c=0;
		for(int i=0;i<s.Length;i++){
			if(s[i]=='U'){a++;}
			else if(s[i]=='D'){a--;}
			else if(s[i]=='L'){b--;}
			else if(s[i]=='R'){b++;}
			else{c++;}
		}
		if(n==1){Console.WriteLine("{0}",Math.Abs(a)+Math.Abs(b)+c);}
		else if(Math.Abs(a)+Math.Abs(b)-c>-1){Console.WriteLine("{0}",Math.Abs(a)+Math.Abs(b)-c);}
		else{Console.WriteLine("{0}",(Math.Abs(a)+Math.Abs(b)-c)&1);}
	}
}