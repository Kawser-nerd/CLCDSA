using System;

namespace arc052_a
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = Console.ReadLine();
            int ret = 0;
            for (int i = 0; ret == 0; i++)
            {
                if (int.TryParse(s[i].ToString(), out ret))
                {
                    int x = 0;
                    if (i != s.Length - 1)
                    {
                        if (int.TryParse(s.Substring(i, 2), out x))
                        {
                            if (x != 0) ret = x;
                        }
                    }
                }
            }
            Console.WriteLine(ret);
        }
    }
}