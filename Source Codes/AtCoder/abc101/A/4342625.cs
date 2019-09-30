using System;

namespace AtCoder.ABC101
{
    public class A
    {
        public static void Solve()
        {
            string[] input = Console.ReadLine().Split(' ');
            string s1 = input[0];

            int cnt = 0;
            for (int i = 0; i < s1.Length; i++)
            {
                if (s1[i].ToString() == "+")
                {
                    cnt++;
                }
                if (s1[i].ToString() == "-")
                {
                    cnt--;
                }
            }
            
            Console.WriteLine(cnt);
        }    
    }
}

namespace AtCoder {
    class Program
    {
        static void Main(string[] args)
        {
            ABC101.A.Solve();
        }
    }
}