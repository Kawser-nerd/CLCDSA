using System;
using System.Collections;
using System.Linq;
class Program
{
    static void Main()
    {
        //??100000????????
        ArrayList ps = new ArrayList();
        bool[] nums = new bool[100001];
        nums[0] = true;
        nums[1] = true;
        for (int i = 0; i < 100001; i++)
        {
            if (!nums[i])
            {
                nums[i] = true;
                ps.Add(i);
                for (int j = 2; j <= 100000 / i; j++)
                    nums[i * j] = true;
            }
        }
        int[] primes = (int[])ps.ToArray(typeof(int));

        //?????
        //for (int i = 0; i < 50; i++)
        //    Console.Write("{0} ", primes[i]);
        //Console.WriteLine();

        //??2017liked?????????????
        int[] sum = new int[50001];
        for (int i = 1; i < 50001; i++)
        {
            sum[i] = sum[i - 1];
            if (Array.IndexOf(primes, 2 * i - 1) >= 0 && Array.IndexOf(primes, i) >= 0)
                sum[i]++;
        }

        //??????
        //for (int i = 0; i < 50; i++)
        //    Console.Write("{0} ", sum[i]);
        //Console.WriteLine();

        //?????????(Q??)
        int q = int.Parse(Console.ReadLine());

        //???????????????????
        for (int i = 0; i < q; i++)
        {
            string[] lr = Console.ReadLine().Split(' ');
            Console.WriteLine(sum[(int.Parse(lr[1]) + 1) / 2] - sum[(int.Parse(lr[0]) + 1) / 2 - 1]);
        }
    }
}