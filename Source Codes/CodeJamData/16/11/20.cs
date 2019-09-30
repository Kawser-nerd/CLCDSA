using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam1a1
{
    class Program
    {
        static void Main(string[] args)
        {
            using(var reader = new StreamReader("C:/CodeJam/1a/Problem1/A-large (1).in"))
            {
                using(var writer = new StreamWriter("C:/CodeJam/1a/Problem1/output.txt"))
                {
                    var numTC = int.Parse(reader.ReadLine());
                    for(var tc = 1; tc <= numTC; tc++)
                    {
                        Console.Write("Case #{0}: ", tc);
                        writer.Write("Case #{0}: ", tc);
                        Solve(reader, writer);
                    }
                }
            }
            Console.ReadKey();

        }

        static void Solve(StreamReader reader, StreamWriter writer)
        {
            var word = reader.ReadLine();
            var s = new StringBuilder();
            var firstChar = word[0];
            s.Append(word[0]);
            foreach(var c in word.Substring(1))
            {
                if(c >= firstChar)
                {
                    s.Insert(0, c);
                    firstChar = c;
                }
                else
                {
                    s.Append(c);
                }
            }
            Console.WriteLine(s.ToString());
            writer.WriteLine(s.ToString());
        }
    }
}
