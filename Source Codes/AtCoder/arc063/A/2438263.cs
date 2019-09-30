using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC63_C
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = Console.ReadLine();
            int count = 0;
            for (int i = 1; i < s.Length; i++)
            {
                if(s[i] != s[i-1])
                {
                    count++;
                }
            }

            Console.WriteLine(count);
        }
    }
}