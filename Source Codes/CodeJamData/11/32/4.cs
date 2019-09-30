using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace TaskB
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            var reader = new StreamReader("b.in");
            var writer = new StreamWriter("b.out");

            var countTest = Int32.Parse(reader.ReadLine());

            for (var iTest = 0; iTest < countTest; iTest++)
            {
                var line = reader.ReadLine().Split(' ').ToArray();
                var L = Int32.Parse(line[0]);
                var t = decimal.Parse(line[1]);
                var N = Int32.Parse(line[2]);
                var C = Int32.Parse(line[3]);
                var a = line.Skip(4).Select(i => Decimal.Parse(i)).ToArray();

                var a2 = new decimal[N];
                for (var i = 0; i < N; i++)
                {
                    a2[i] = a[i%C];
                }

                var time = 0m;
                for (var i = 0; (i < N) && (t != 0); i++)
                {
                    var t2 = a2[i]*2;
                    if (t2 > t)
                    {
                        t2 = t;
                    }
                    a2[i] -= t2/2;
                    t -= t2;
                    time += t2;
                }

                var speedLength = a2.OrderByDescending(i => i).Take(L).Sum();
                var allLength = a2.Sum();

                time += speedLength + (allLength - speedLength)*2;

                writer.WriteLine("Case #{0}: {1}", iTest + 1, time);
            }


            reader.Close();
            writer.Close();
        }
    }
}