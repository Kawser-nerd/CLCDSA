using System;

namespace joi
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			string a = Console.ReadLine ();
			Console.WriteLine (a[a.Length - 1] == 'T' ? "YES" : "NO");
		}
	}
}