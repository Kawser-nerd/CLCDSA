using System;
using System.Collections.Generic;
using System.Linq;

namespace Round1CProblemA
{
    class Program
    {
        static void Main(string[] args)
        {
            var t = int.Parse(Console.ReadLine());
            for (var ti = 1; ti <= t; ti++)
            {
                var n = int.Parse(Console.ReadLine());
                var parties = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();

                var steps = new List<string>();

                while (parties.Any(k => k > 0))
                {
                    //Console.WriteLine(string.Join(" ", Enumerable.Range(0, n).Select(i => (char)('A' + i) + parties[i].ToString())));

                    var sum = parties.Sum();
                    if (parties.Any(k => k*2 > sum))
                    {
                        steps = null;
                        break;
                    }

                    var max = parties.Max();
                    var count = parties.Count(k => k == max);

                    if (count > 2)
                    {
                        count = 1;
                    }

                    var partiesToLeave = Enumerable.Range(0, n).Where(i => parties[i] == max).Take(count).ToArray();
                    foreach (var party in partiesToLeave)
                    {
                        parties[party]--;
                    }

                    //Console.WriteLine("<" + new string(partiesToLeave.Select(i => (char)('A' + i)).ToArray()) + ">");
                    //Console.WriteLine("[" + string.Join(",", partiesToLeave.Select(i => i.ToString())) + "]");

                    steps.Add(new string(partiesToLeave.Select(i => (char)('A' + i)).ToArray()));
                }

                Console.WriteLine($"Case #{ti}: {string.Join(" ", steps)}");
            }
        }
    }
}
