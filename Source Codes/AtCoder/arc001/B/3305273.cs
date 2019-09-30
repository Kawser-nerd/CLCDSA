using System;
class Program{
	static void Main(){
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		int a=Math.Abs(s[0]-s[1]),b=0;
		b+=a/10;
		a%=10;
		if(a<4){b+=a;}
		else if(a>7){b+=11-a;}
		else{b+=Math.Abs(a-5)+1;}
		Console.WriteLine("{0}",b);
	}
}