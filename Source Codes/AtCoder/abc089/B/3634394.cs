using System;

namespace ABC089_B_Hina_Arare
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			int n = int.Parse(Console.ReadLine());
			string[] arareColor = Console.ReadLine().Split(' ');

			for (int i = 0; i < n; i++) {
				if (arareColor[i] == "Y")
				{
					Console.WriteLine("Four");
					return;
				}
			}
			Console.WriteLine("Three");
		}
	}
}