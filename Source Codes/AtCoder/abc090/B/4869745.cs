using System;
using System.Linq;

namespace B___Palindromic_Numbers
{
    class Program
    {
        static void Main(string[] args)
        {
            var A_B = Console.ReadLine().Split().Select(int.Parse).ToArray();
            var A = A_B[0];
            var B = A_B[1];
            int cnt = 0;

            for (int i = A; i <= B; i++)
            {
                if (i - int.Parse(new string(i.ToString().Reverse().ToArray())) == 0)
                    cnt++;
            }

            Console.WriteLine(cnt);
        }
    }
}