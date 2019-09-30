using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace TestApp
{
    class Program
    {
        static void Main(string[] args)
        {
            var str = Console.ReadLine();
            char last = ' ';
            int lastLong = 1;
            var ls = new List<KeyValuePair<char, int>>();
            var length = str.Length;
            last = str[0];
            for (int i = 1; i < length; i++)
            {
                if (str[i] == last)
                {
                    lastLong++;
                }
                else
                {
                    ls.Add(new KeyValuePair<char, int>(last, lastLong));
                    lastLong = 1;
                    last = str[i];
                }
            }
            ls.Add(new KeyValuePair<char, int>(last, lastLong));
            ls.ForEach(x =>
            {
                Console.Write(x.Key.ToString() + x.Value);
            });
            Console.WriteLine();
            Console.ReadLine();
        }
        
    }

}