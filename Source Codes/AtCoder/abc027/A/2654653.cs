using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ciq27_01
{
	class Program
	{
		static void Main(string[] args)
		{
			string[] array = Console.ReadLine().Split(' ');
			int[] split = new int[3];

			for(int i = 0;i < 3; i++)
			{
				split[i] = int.Parse(array[i]);
			}

			if(split[0] == split[1])
			{
				Console.WriteLine(split[2]);
			}
			else if(split[0] == split[2])
			{
				Console.WriteLine(split[1]);
			}
			else if (split[1] == split[2])
			{
				Console.WriteLine(split[0]);
			}
		}
	}
}