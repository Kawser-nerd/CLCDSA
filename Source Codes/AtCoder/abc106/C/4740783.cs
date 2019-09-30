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
            char[] s = Console.ReadLine().ToCharArray();
            long k = long.Parse(Console.ReadLine());

            if(s[0] != '1')
            {
                Console.WriteLine(s[0]);
                return;
            }
            for(long i=0;i<k && i < s.Length ;i++)
            {
                if(s[i] != '1')
                {
                    Console.WriteLine(s[i]);
                    return;
                }
            }
            Console.WriteLine("1");
            return;
        }
    }
}