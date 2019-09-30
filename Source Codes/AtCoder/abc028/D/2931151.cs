using System;
class Program{
	static void Main(){
		long[] s=Array.ConvertAll(Console.ReadLine().Split(),long.Parse);
		s[1]-=1;
		double a=s[0]*s[0]*s[0];
		Console.WriteLine("{0}",(s[0]*3+s[1]*(s[0]-s[1]-1)*6-2)/a);
	}
}