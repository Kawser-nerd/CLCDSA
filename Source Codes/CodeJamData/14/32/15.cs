using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;

class BReordering
{
    public const long modulo = 1000000007;
    public const int alphaSize = 'z' - 'a' + 1;

    static void Main()
    {
        var T = int.Parse(Console.ReadLine(), CultureInfo.InvariantCulture);
        for (int t = 1; t <= T; t++)
        {
            long result = 0;

            var N = int.Parse(Console.ReadLine(), CultureInfo.InvariantCulture);
            var cars = Console.ReadLine().Split(new[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries).Select(p => new Link(p)).ToArray();
            if (cars.Length != N)
                throw new InvalidOperationException("Expected " + N + " items in line, actual count " + cars.Length);

            // unique between
            var isEnd = new bool[alphaSize];
            foreach (var car in cars)
            {
                isEnd[car.First - 'a'] = true;
                isEnd[car.Last - 'a'] = true;
            }
            var wasBetween = new bool[alphaSize];
            foreach (var car in cars)
            {
                if (car.Ways == 0)
                    goto NEXT;
                foreach (var b in car.Between)
                {
                    if (wasBetween[b - 'a'] || isEnd[b - 'a'])
                        goto NEXT;
                    wasBetween[b - 'a'] = true;
                }
            }

            // merging mono
            var monos = cars.Where(c => c.First == c.Last).GroupBy(c => c.First);
            var polys = cars.Where(c => c.First != c.Last);
            cars = monos.Select(m => new Link(m.Key, new char[0], m.Key, Factorial(m.Count()))).Concat(polys).ToArray();

            // merging ends
            Dictionary<char, Link> monos2, polysByFirst;
            try
            {
                monos2 = cars.Where(c => c.First == c.Last).ToDictionary(c => c.First);
                polysByFirst = cars.Where(c => c.First != c.Last).ToDictionary(c => c.First);
            }
            catch (ArgumentException)
            {
                goto NEXT;
            }
            var cars2 = new List<Link>();
            for (char c = 'a'; c <= 'z'; c++)
            {
                if (polysByFirst.Any(p => p.Value.Last == c))
                    continue;

                Link link, monoLink;
                if (polysByFirst.TryGetValue(c, out link))
                {
                    var chain = new List<Link>();
                    if (monos2.TryGetValue(c, out monoLink))
                    {
                        monos2.Remove(c);
                        chain.Add(monoLink);
                    }
                    polysByFirst.Remove(c);
                    chain.Add(link);

                    while (polysByFirst.TryGetValue(chain.Last().Last, out link))
                    {
                        if (monos2.TryGetValue(chain.Last().Last, out monoLink))
                        {
                            monos2.Remove(chain.Last().Last);
                            chain.Add(monoLink);
                        }
                        polysByFirst.Remove(chain.Last().Last);
                        chain.Add(link);
                    }

                    if (monos2.TryGetValue(chain.Last().Last, out monoLink))
                    {
                        monos2.Remove(chain.Last().Last);
                        chain.Add(monoLink);
                    }

                    long chainWays = 1;
                    foreach (var l in chain)
                        chainWays = (chainWays * l.Ways) % modulo;
                    cars2.Add(new Link(
                        chain.First().First, 
                        chain.SelectMany(cc => cc.Between)
                            .Concat(chain.Skip(1).Select(cc => cc.First))
                            .Concat(chain.Take(chain.Count - 1).Select(cc => cc.Last))
                            .Distinct().Except(new[] { chain.First().First, chain.Last().Last }).ToArray(), 
                        chain.Last().Last, 
                        chainWays));
                }
            }
            cars2.AddRange(monos2.Values);
            if (polysByFirst.Any())
                goto NEXT;

            result = Factorial(cars2.Count);
            foreach (var link in cars2)
                result = (result * link.Ways) % modulo;

        NEXT:
            Console.WriteLine("Case #{0}: {1}", t, result);
        }
    }

    static long Factorial(int arg)
    {
        long result = 1;
        for (int i = 2; i <= arg; i++)
            result = (result * i) % modulo;
        return result;
    }
}

struct Link
{
    public readonly char First;
    public readonly char Last;
    public readonly char[] Between;
    public readonly long Ways;

    public Link(char first, char[] between, char last, long ways)
    {
        First = first;
        Between = between;
        Last = last;
        Ways = ways;
    }

    public Link(string text)
    {
        Ways = 1;
        var wasBefore = new bool[BReordering.alphaSize];
        for (int i = 0; i < text.Length; i++)
        {
            if (i > 0 && wasBefore[text[i] - 'a'] && text[i - 1] != text[i])
                Ways = 0;
            wasBefore[text[i] - 'a'] = true;
        }

        First = text.First();
        Last = text.Last();
        Between = text.SkipWhile(c => c == text[0]).Reverse().SkipWhile(c => c == text[text.Length - 1]).Distinct().OrderBy(c => c).ToArray();
    }

    public override string ToString()
    {
        return First + "{" + string.Concat(Between) + "}" + Last + " @ " + Ways;
    }
}
