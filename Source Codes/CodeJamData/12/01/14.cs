using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static Dictionary<char, char> mapping = new Dictionary<char, char>();

        static void Main(string[] args)
        {
            Understand("ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand");
            Understand("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "there are twenty six factorial possibilities");
            Understand("de kr kd eoya kw aej tysr re ujdr lkgc jv", "so it is okay if you want to just give up");
            Understand("y qee", "a zoo");
            Understand("z", "q");

            using (StreamReader reader = new StreamReader(@"d:\A-small-attempt1.in"))
            {
                int count = int.Parse(reader.ReadLine());
                for (int i = 0; i < count; i++)
                {
                    Process(i + 1, reader.ReadLine());
                }
            }
        }

        private static void Process(int line, string googlerese)
        {
            Console.Write("Case #{0}: ", line);
            var a1 = googlerese.ToCharArray();
            for (int i = 0; i < a1.Length; i++)
            {
                Console.Write(mapping[a1[i]]);
            }
            Console.WriteLine();
        }

        private static void Understand(string googlerese, string english)
        {
            var a1 = googlerese.ToCharArray();
            var a2 = english.ToCharArray();

            for (int i = 0; i < a1.Length; i++)
            {
                mapping[a1[i]] = a2[i];
            }
        }
    }
}
