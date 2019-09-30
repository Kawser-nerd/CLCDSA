using System;


	public class abc002_1
	{
		public static void Main()
		{
			string[] inputs = Console.ReadLine().Split(' ');

			var first = int.Parse(inputs[0]);
			var second = int.Parse(inputs[1]);

			if ( first < second ) {
				Console.WriteLine($"{second}");
				return;
			}

			Console.WriteLine($"{first}");
		}
	}