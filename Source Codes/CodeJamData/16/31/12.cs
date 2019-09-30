using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            using(var reader = new StreamReader("C:\\CodeJam\\1c\\a\\A-large.in"))
            {
                using (var writer = new StreamWriter("C:\\CodeJam\\1c\\a\\out.txt"))
                {
                    var numCases = int.Parse(reader.ReadLine());
                    for(int i = 1; i <= numCases; i++)
                    {
                        Console.Write("Case #{0}: ", i);
                        writer.Write("Case #{0}: ", i);
                        Solve(reader, writer);
                    }
                }
            }
            Console.ReadKey();
        }

        static void Solve(StreamReader reader, StreamWriter writer)
        {
            var numParties = int.Parse(reader.ReadLine());
            var parties = reader.ReadLine().Split().Select(int.Parse).ToList();
            var totalSenators = parties.Sum();
            var first = true;
            while(totalSenators > 0)
            {
                var best = 0;
                for(int i = 0; i < parties.Count; i++)
                {
                    if (parties[i] > parties[best])
                        best = i;
                }
                
                if(!first)
                {
                    Console.Write(" ");
                    writer.Write(" ");
                }
                first = false;

                parties[best]--;
                Console.Write((char)('A' + best));
                writer.Write((char)('A' + best));
                totalSenators--;

                if (totalSenators == 1 || totalSenators > 2)
                {
                    best = 0;
                    for (int i = 0; i < parties.Count; i++)
                    {
                        if (parties[i] > parties[best])
                            best = i;
                    }
                    parties[best]--;
                    Console.Write((char)('A' + best));
                    writer.Write((char)('A' + best));
                    totalSenators--;
                }
            }
            Console.WriteLine();
            writer.WriteLine();
        }
    }
}
