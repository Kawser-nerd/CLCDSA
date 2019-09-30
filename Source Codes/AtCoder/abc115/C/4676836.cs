using System;
using System.Linq;

namespace CSharp
{
	class Program
	{
		static void Main(string[] args)
		{
			var input = Console.ReadLine().Split().Select(int.Parse).ToArray();

			var N = input[0];
			var K = input[1];
			

			var H = new int[N];

			for (var i = 0; i < N; i++)
			{
				H[i] = Console.ReadLine().Split().Select(int.Parse).ToArray()[0];
			}
			
			Array.Sort(H);
	
			var min = H[K -1] - H[0];
			for (var i = 0; i + K -1 < N; i++)
			{
				min = Math.Min(min, H[i + K -1] - H[i]);
			}
			Console.WriteLine(min);
		}
	}
}