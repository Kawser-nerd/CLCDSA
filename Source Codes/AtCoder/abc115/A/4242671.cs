using System;

namespace A
{
	class Program
	{
		static void Main(string[] args)
		{
			var line = Console.ReadLine();
			// var lineSplited = line.Split(new char[] {' '}, StringSplitOptions.RemoveEmptyEntries);

			var D = Int32.Parse(line);

			switch (D) {
				case 22:
					Console.WriteLine("Christmas Eve Eve Eve");
					break;
				case 23:
					Console.WriteLine("Christmas Eve Eve");
					break;
				case 24:
					Console.WriteLine("Christmas Eve");
					break;
				case 25:
					Console.WriteLine("Christmas");
					break;
				default:
					break;
			}
		}
	}
}