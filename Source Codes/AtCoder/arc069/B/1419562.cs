using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public static class Quiz
{
    static IEnumerable<X[]> Iterator<X>(int i, X[] buffer, X[] all)
    {
        if (i == buffer.Length)
        {
            yield return buffer;
        }
        else
        {
            foreach (var x in all)
            {
                buffer[i] = x;

                foreach (var xs in Iterator(i + 1, buffer, all))
                {
                    yield return xs;
                }
            }
        }
    }

    public static IEnumerable<char[]> AllPropositions(int n)
    {
        return Iterator(0, new char[n], new char[] { 'o', 'x' });
    }

    public static IEnumerable<char[]> AllAnimals(int n)
    {
        return Iterator(0, new char[n], new char[] { 'S', 'W' });
    }
}

public sealed class BruteForceSolver
{
    public bool IsConsistent(int n, string s, char[] animals)
    {
        for (var i = 0; i < n; i++)
        {
            var isSame = animals[i] == 'S' ? (s[i] == 'o') : (s[i] == 'x');
            var previous = animals[(i - 1 + n) % n];
            var next = animals[(i + 1) % n];

            if (isSame && previous == next) continue;
            if (!isSame && previous != next) continue;

            return false;
        }

        return true;
    }

    public string Solve(int n, string s)
    {
        foreach (var animals in Quiz.AllAnimals(n))
        {
            if (IsConsistent(n, s, animals)) return new string(animals);
        }

        return null;
    }
}

public sealed class FastSolver
{
    char Inverse(char animal)
    {
        return animal == 'S' ? 'W' : 'S';
    }

    bool TryBuild(char first, char second, int n, string s, char[] animals)
    {
        animals[0] = first;
        animals[1] = second;

        for (var i = 1; i + 1 < n + 2; i++)
        {
            animals[(i + 1) % n] =
                ((s[i % n] == 'o') ^ (animals[i % n] == 'W'))
                    ? animals[(i - 1) % n]
                    : Inverse(animals[(i - 1) % n]);
        }

        return animals[0] == first && animals[1] == second;
    }

    public string Solve(int n, string s)
    {
        var pairs =
            new[]
            {
                Tuple.Create('S', 'S'),
                Tuple.Create('S', 'W'),
                Tuple.Create('W', 'S'),
                Tuple.Create('W', 'W'),
            };

        var animals = new char[n];

        foreach (var pair in pairs)
        {
            if (TryBuild(pair.Item1, pair.Item2, n, s, animals))
            {
                return new string(animals);
            }
        }

        return null;
    }
}

public sealed class Checker
{
    public void Run()
    {
        var bruteForce = new BruteForceSolver();
        var fast = new FastSolver();

        for (var n = 3; n < 10; n++)
        {
            foreach (var ps in Quiz.AllPropositions(n))
            {
                var s = new string(ps);
                var expected = bruteForce.Solve(n, s);
                var actual = fast.Solve(n, s);
                if (expected != actual)
                {
                    System.Diagnostics.Debug.Assert(false);
                }
            }
        }
    }
}

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
    string s;

    public void Run()
    {
        n = ReadLine(int.Parse)[0];
        s = input.ReadLine();
        var solution = new FastSolver().Solve(n, s);
        WriteLineOne(solution == null ? "-1" : solution);
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