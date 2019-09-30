using System;
using System.Linq;
class Program
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        string s = Console.ReadLine();
        if (n % 2 == 0)
            Console.WriteLine("-1");
        else
        {
            string l = "b";
            int m = (n - 1) / 2;
            if (m > 0)
            {
                for (int i = 1; i <= m; i++)
                {
                    if (i % 3 == 1)
                        l = "a" + l + "c";
                    else if (i % 3 == 2)
                        l = "c" + l + "a";
                    else
                        l = "b" + l + "b";
                }
            }
            if (s == l)
                Console.WriteLine(m);
            else
                Console.WriteLine("-1");
        }
    }
}