using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ciq21_02
{
	class Program
	{
		static void Main(string[] args)
		{
			int townnum = int.Parse(Console.ReadLine());
			string[] placearray = Console.ReadLine().Split(' ');
			int takahasi = int.Parse(placearray[0]);
			int me = int.Parse(placearray[1]);
			int rootnum = int.Parse(Console.ReadLine());
			string[] rootarray = Console.ReadLine().Split(' ');

			int[] root = new int[rootarray.Length];
			int no = 0;

			for(int i = 0;i < rootarray.Length; i++)
			{
				root[i] = int.Parse(rootarray[i]);
				if(root[i] == takahasi || root[i] == me)
				{
					no = no + 2;
					break;
				}
			}
			for(int x = 0;x < rootarray.Length; x++)
			{
				if (no == 2)
				{
					break;
				}
				no = 0;
				for (int y = 0;y < rootarray.Length; y++)
				{
					if(root[y] == root[x])
					{
						no++;
					}
				}
			}
			if(no == 2)
			{
				Console.WriteLine("NO");
			}
			else
			{
				Console.WriteLine("YES");
			}
		}
	}
}