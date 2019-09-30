using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace tes
{
	class contest
	{
		static void Main(string[] args)
		{
			 
			 var input = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            var list = Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
            var memo = new long[list.Length];
            var turnMemo = new int[list.Length];
            long[] cl = (long[])list.Clone();

            long ans = long.MaxValue;

            for (int i = 0; i < list.Count(); i++)
            {
                long temp = (long)input[1] * i;
                for(int j =0; j<list.Count(); j++)
                {
                    cl[j] = Math.Min(cl[j] , list[(j-i+input[0])%input[0]]);
                    temp += cl[j];

                }
                ans = Math.Min(ans, temp);

            }
            Console.WriteLine(ans);
			 
            
		}

	}
}