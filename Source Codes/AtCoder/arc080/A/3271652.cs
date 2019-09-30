using System;
class Program{
	static void Main(){
		int n=int.Parse(Console.ReadLine());
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		int a=0,b=0;
		string ans="No";
		foreach(int i in s){
			if(i%4==0){a++;}
			else if(i%2!=0){b++;}
		}
		if(a>=b||(a+1==b&&a+b==n)){ans="Yes";}
		Console.WriteLine("{0}",ans);
	}
}