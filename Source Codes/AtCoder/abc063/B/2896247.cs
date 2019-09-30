using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace AtCoder
{
    public class ABC_063_B
    {
        public static void Main()
        {
            var s = Console.ReadLine();
            var len = s.Length;
            var result = "yes";

            for (int i = 1; result=="yes"&&i < len; i++)
            {
                for (int j = 0; j < i; j++)
                {
                    if (s[i].ToString() == s[j].ToString())
                    {
                        result = "no";
                        break;
                    }
                }
            }
            Console.WriteLine(result);
            Console.Read();
        }


    }
}