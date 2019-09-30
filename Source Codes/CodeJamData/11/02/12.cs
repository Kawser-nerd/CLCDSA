using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJamMagicka
{
    class Program
    {
        static void Main(string[] args)
        {
            var s = Console.ReadLine();
            int testCount = int.Parse(s);
            for (int i = 0; i < testCount; i++)
            {
                var inputElements = new Queue<string>(Console.ReadLine().Split());

                var combinesCount = int.Parse(inputElements.Dequeue());
                var combines = new Dictionary<Tuple<char, char>, char>();
                for (int j = 0; j < combinesCount; j++)
                {
                    var c = inputElements.Dequeue();
                    combines[c[0] > c[1] ? Tuple.Create(c[1], c[0]) : Tuple.Create(c[0], c[1])] = c[2];
                }

                var oppositeCount = int.Parse(inputElements.Dequeue());
                var opposite = new Dictionary<char, List<char>>();
                for (int j = 0; j < oppositeCount; j++)
                {
                    var c = inputElements.Dequeue();
                    if (!opposite.ContainsKey(c[0]))
                        opposite[c[0]] = new List<char>();
                    opposite[c[0]].Add(c[1]);
                    if (!opposite.ContainsKey(c[1]))
                        opposite[c[1]] = new List<char>();
                    opposite[c[1]].Add(c[0]);
                }

                var res = new List<Char>();
                inputElements.Dequeue();
                var input = inputElements.Dequeue();
                foreach (Char item in input)
                {
                    if (res.Count > 0)
                    {
                        var prev = res[res.Count - 1];
                        var key = prev > item ? Tuple.Create(item, prev) : Tuple.Create(prev, item);
                        if (combines.ContainsKey(key))
                        {
                            res[res.Count - 1] = combines[key];
                            continue;
                        }
                        if (res.Any(c => opposite.ContainsKey(c) && opposite[c].Contains(item)))
                        {
                            res.Clear();
                            continue;
                        }
                    }
                    res.Add(item);
                }

                Console.Write("Case #{0}: [", i + 1);
                Console.Write(string.Join(", ", res));
                Console.WriteLine("]");
            }
        }
    }
}
