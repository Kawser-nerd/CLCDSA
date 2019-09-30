using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ciq22_01
{
	class Program
	{
		static void Main(string[] args)
		{
			string[] array = Console.ReadLine().Split(' ');
			int day = int.Parse(array[0]);
			int min = int.Parse(array[1]);
			int max = int.Parse(array[2]);
			int weigt = 0;
			int count = 0;

			for(int i = 1;i <= day; i++)
			{
				weigt = weigt + int.Parse(Console.ReadLine());
				if (weigt >= min && weigt <= max)
				{
					count++;
				}
			}
			Console.WriteLine(count);
		}
	}
}