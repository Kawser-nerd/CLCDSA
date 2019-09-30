using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Language
{
    class Program
    {
        static void Main(string[] args)
        {
            new Program().SolveAll();
        }

        Dictionary<char, char> Mapping = new Dictionary<char, char>();

        void SolveAll()
        {
            AddMappings(
                "ejp mysljylc kd kxveddknmc re jsicpdrysi",
                "our language is impossible to understand");

            AddMappings(
                "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
                "there are twenty six factorial possibilities");

            AddMappings(
                "de kr kd eoya kw aej tysr re ujdr lkgc jv",
                "so it is okay if you want to just give up");

            AddMappings("zq", "qz");

            var testCases = int.Parse(Console.ReadLine());
            for (int i = 0; i < testCases; i++)
                Solve();
        }

        static int Case = 1;

        void Solve()
        {
            var s = Console.ReadLine();
            var result = "";
            for (int i = 0; i < s.Length; i++)
                result += Mapping[s[i]];
            Console.WriteLine("Case #{0}: {1}", Case++, result);
        }

        void AddMappings(string a, string b)
        {
            for (int i = 0; i < a.Length; i++)
                Mapping[a[i]] = b[i];
        }
    }
}
