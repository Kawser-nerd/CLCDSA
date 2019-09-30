using System;

namespace AC_RC002
{
    class Program
    {
        static void Main(string[] args)
        {
            int a = int.Parse(Console.ReadLine());
            if (a % 4 == 0 && a % 100 != 0)
            {
                Console.WriteLine("YES");
            }
            else if(a % 400 !=0)
            {
                Console.WriteLine("NO");
            }
            else if (a % 400 == 0)
            {
                Console.WriteLine("YES");
            }
            else
            {
                Console.WriteLine("NO");
            }
        }
    }
}