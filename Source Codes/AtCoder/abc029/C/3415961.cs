using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace program
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());

            List<string> a = new List<string>();
            a.Add("a");
            a.Add("b");
            a.Add("c");

            for (int i = 0; i < n - 1; i++)
            {
                var list2 = new List<string>(a);
                var list3 = new List<string>();
                foreach (string letter in list2)
                {
                    string plusA = letter + "a";
                    list3.Add(plusA);
                    string plusB = letter + "b";
                    list3.Add(plusB);
                    string plusC = letter + "c";
                    list3.Add(plusC);
                }
                a = new List<string>(list3);
                
            }

            var query = a
                .OrderBy(x => x)
                .Select(c => c)
                .ToList();

            foreach(string tmp in query)
            {
                Console.WriteLine(tmp);
            }
        }
    }
}