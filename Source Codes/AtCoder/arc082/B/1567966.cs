using System;
using System.Linq;
 
namespace arc082_b
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int ret = 0;
            bool flag = false;
            for (int i = 0; i < n; i++)
            {
                if (x[i] == i + 1)
                {
                    if (!flag)
                    {
                        ret++;
                    }
                    flag = !flag;
                }
                else if (flag) flag = false;
            }
            Console.WriteLine(ret);
        }
    }
}