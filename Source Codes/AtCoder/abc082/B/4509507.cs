using System;
class Program
{
	static void Main(string[] args)
	{
		char[] s = Console.ReadLine().ToCharArray();
      	char[] t = Console.ReadLine().ToCharArray();
      
      	Array.Sort(s);
      	Array.Sort(t);
      	Array.Reverse(t);
      
      	Console.WriteLine( string.Compare( new string(s), new string(t) ) < 0 ? "Yes" : "No" );
	}
}