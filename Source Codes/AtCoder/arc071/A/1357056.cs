using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public class Program
{
    #region Standard I/O
    readonly TextReader input;
    readonly TextWriter output;

    X[] ReadLine<X>(Func<string, X> func)
    {
        return input.ReadLine().Split(' ').Select(func).ToArray();
    }

    void WriteLineOne(object obj)
    {
        output.WriteLine("{0}", obj);
    }

    void WriteLineMany(params object[] objects)
    {
        output.WriteLine(string.Join(" ", objects.Select(obj => obj.ToString())));
    }
    #endregion

    int n;
    string[] ss;

    void Read()
    {
        n = ReadLine(int.Parse)[0];
        ss = Enumerable.Range(0, n).Select(_ => input.ReadLine()).ToArray();
    }

    static IEnumerable<char> Alphabets()
    {
        for (var c = 'a'; c <= 'z'; c++)
        {
            yield return c;
        }
    }

    string Solve()
    {
        var minCounts = Alphabets().ToDictionary(c => c, _ => int.MaxValue);

        foreach (var s in ss)
        {
            var counts = s.GroupBy(c => c).ToDictionary(g => g.Key, g => g.Count());

            foreach (var c in Alphabets())
            {
                var k = counts.ContainsKey(c) ? counts[c] : 0;
                minCounts[c] = Math.Min(minCounts[c], k);
            }
        }

        return new string(Alphabets().SelectMany(c => Enumerable.Repeat(c, minCounts[c])).ToArray());
    }

    public void Run()
    {
        Read();
        WriteLineOne(Solve());
    }

    public Program(TextReader input, TextWriter output)
    {
        this.input = input;
        this.output = output;
    }

    public static void Main(string[] args)
    {
        new Program(Console.In, Console.Out).Run();
    }
}