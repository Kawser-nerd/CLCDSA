using System;

namespace ABC051_B_Sum_of_Three_Integers
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			string[] input = Console.ReadLine().Split(' ');
			int k = int.Parse(input[0]);
			int s = int.Parse(input[1]);

			int count = 0;
			
			for (int x = 0; x <= k; x++) {
				for (int y = 0; y <= k; y++)
				{
					int z = s - x - y;
					if (x + y + z == s && z <= k && z >= 0)
					{
						//Console.WriteLine("x?" + x + " y?" + y + " z?" + z); 
						count++;
					}
				
				}
			}
			
			Console.WriteLine(count);
		}
	}
}