using System;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            MainStream();
        }
        static void MainStream()
        {
            int n = int.Parse(Console.ReadLine());
            int count = 0;
            for (int i = 1; i <= n; i += 2)
            {
                if (Judge(i))
                {
                    count += 1;
                }
            }
            Console.WriteLine(count);
        }

        static bool Judge(int n)
        {
            int yakusu_count = 0;

            for(int i = 1;i <= n;i += 2)
            {
                if(n % i == 0)
                {
                    yakusu_count += 1;
                }
            }
            if(yakusu_count == 8 )
            {
                return true;
            }
            return false;
        }
    }
}