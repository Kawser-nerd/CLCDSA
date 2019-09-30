using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ciq24_01
{
	class Program
	{
		static void Main(string[] args)
		{
			string[] array1 = Console.ReadLine().Split(' ');
			string[] array2 = Console.ReadLine().Split(' ');

			int chprise = int.Parse(array1[0]);
			int adprise = int.Parse(array1[1]);
			int dis = int.Parse(array1[2]);
			int num = int.Parse(array1[3]);

			int ch = int.Parse(array2[0]);
			int ad = int.Parse(array2[1]);
			int sum;

			sum = ch * chprise + ad * adprise;

			if(ch + ad >= num)
			{
				sum = sum - (dis * (ch + ad));
			}
			Console.WriteLine(sum);
		}
	}
}