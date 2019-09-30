using System;

namespace AGC027A
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input1 = Console.ReadLine().Split(' ');
            int N = int.Parse(input1[0]);
            int x = int.Parse(input1[1]);

            int[] a = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
            Array.Sort(a); //???????
            int ans = 0; //???????

            for(int i = 0; i < N && x >= a[i]; i++)
            {
                x -= a[i];
                ans++;
            }
            //??????????????ans==N????????????1??????????????
            if (ans == N && x > 0)
            {
                ans--;
            }
            Console.WriteLine(ans);
        }
    }
}