using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace abc106_d
{
    class Program
    {
        static void Main(string[] args)
        {
            int n, m, q;
            int l, r;
            string[] nums;
            int[,] sum = new int[501, 501];

            nums = Console.ReadLine().Split(' ');
            n = int.Parse(nums[0]);
            m = int.Parse(nums[1]);
            q = int.Parse(nums[2]);

            for(int i = 0; i < m; ++i)
            {
                nums = Console.ReadLine().Split(' ');
                l = int.Parse(nums[0]);
                r = int.Parse(nums[1]);

                ++sum[l, r];
            }

            for (int i = 1; i <= n; ++i)
            {
                for(int j = 1; j <= n; ++j)
                {
                    sum[i, j] += sum[i, j - 1];
                }
            }

            for(int i = 1; i <= n; ++i)
            {
                for(int j = 1; j <= n; ++j)
                {
                    sum[i, j] += sum[i - 1, j];
                }
            }

            for(int i = 0; i < q; ++i)
            {
                nums = Console.ReadLine().Split(' ');
                l = int.Parse(nums[0]);
                r = int.Parse(nums[1]);

                Console.WriteLine(sum[r, r] - sum[r, l - 1] - sum[l - 1, r] + sum[l - 1, l - 1]);
            }            
        }
    }
}