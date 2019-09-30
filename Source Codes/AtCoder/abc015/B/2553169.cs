using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ciq15_02
{
	class Program
	{
		static void Main(string[] args)
		{
			int num = int.Parse(Console.ReadLine());

			string[] split = Console.ReadLine().Split(' ');
			int[] bug = new int[num];
			int bugAmount = 0;
			int denom = 0;

			for(int i = 0;i < num; i++)
			{
				bug[i] = int.Parse(split[i]);
				bugAmount = bugAmount + bug[i];
				if(bug[i] != 0)
				{
					denom = denom + 1;
				}
			}
			if(bugAmount % denom == 0)
			{
				Console.WriteLine(bugAmount / denom);
			}
			else
			{
				Console.WriteLine((bugAmount / denom) + 1);
			}
		}
	}
}