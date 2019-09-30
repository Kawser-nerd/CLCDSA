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
            if(Judge(n))
            {
                Console.WriteLine("Yes");
            }
            else
            {
                Console.WriteLine("No");
            }
        }
        static bool Judge(int n)
        {
            for(int f = 0; f <= (n / 4); f++)
            {
                if((n-4*f)%7==0)
                {
                    return true;
                }
            }
            for (int s = 0; s <= (n / 7); s++)
            {
                if ((n - 7 * s) % 4 == 0)
                {
                    return true;
                }
            }

            return false;
        }

    }
}