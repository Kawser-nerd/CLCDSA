using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;

class Problem2
{
    private const string FileName = @"B-large";
    private const string InputFileName = @"..\..\" + FileName + ".in";
    private const string OutputFileName = @"..\..\" + FileName + ".out";
    private const bool MultipleCases = true;

    public int N { get; private set; }
    public int Surprises { get; private set; }
    public int Threshold { get; private set; }
    public int[] Scores { get; private set; }

    private Problem2(InputParser input)
    {
        N = input.GetInt();
        Surprises = input.GetInt();
        Threshold = input.GetInt();
        Scores = input.GetIntArray(N);
    }

    private object SolveCase()
    {
        int remainingSurprises = Surprises;
        int count = 0;
        foreach (var score in Scores)
        {
            if (score >= 3 * Threshold - 2)
            {
                ++count;
            }
            else if (score >= 2 && score >= 3 * Threshold - 4 && remainingSurprises > 0)
            {
                ++count;
                --remainingSurprises;
            }
        }
        return count;
    }

    static void Main(string[] args)
    {
        bool useFile = File.Exists(InputFileName);
        var inputParser = useFile ? new InputParser(InputFileName) : new InputParser();

        TextWriter output;
        if (useFile)
        {
            File.Delete(OutputFileName);
            output = new StreamWriter(File.OpenWrite(OutputFileName));
        }
        else
        {
            output = Console.Out;
        }

        var sw = new Stopwatch();
        sw.Start();
        try
        {
            if (MultipleCases)
            {
                int caseCount = inputParser.GetInt();
                for (int c = 0; c < caseCount; ++c)
                {
                    output.WriteLine(string.Format("Case #{0}: {1}", c + 1, new Problem2(inputParser).SolveCase()));
                }
            }
            else
            {
                output.WriteLine(string.Format("{0}", new Problem2(inputParser).SolveCase()));
            }
        }
        finally
        {
            if (useFile)
            {
                output.Dispose();
            }
        }
        if (useFile)
        {
            Console.WriteLine("Output:");
            Console.Write(File.ReadAllText(OutputFileName));
            Console.WriteLine("Total time: {0} ms", sw.ElapsedMilliseconds);
            Console.ReadLine();
        }
    }
}

public class InputParser
{
    private IEnumerator<string> Elements { get; set; }

    private IEnumerable<string> GetElements(IEnumerable<string> lines)
    {
        // Insert a null element at the end of each line.
        return lines.SelectMany(l => Regex.Split(l, @"\s+").Concat(new string[] { null }));
    }

    private static IEnumerable<string> ReadConsoleLines()
    {
        string line;
        while ((line = Console.ReadLine()) != null)
        {
            yield return line;
        }
    }

    public InputParser()
        : this(ReadConsoleLines())
    {
    }

    public InputParser(string filename)
        : this(File.ReadLines(filename))
    {
    }

    public InputParser(IEnumerable<string> lines)
    {
        Elements = GetElements(lines).GetEnumerator();
    }

    public string GetString()
    {
        if (Elements.MoveNext())
        {
            return string.IsNullOrEmpty(Elements.Current) ? GetString() : Elements.Current;
        }
        else
        {
            throw new Exception("Tried to go past the end of the file");
        }
    }

    public IEnumerable<string> GetStrings(int count)
    {
        for (int i = 0; i < count; i++)
        {
            yield return GetString();
        }
    }

    public string[] GetStringArray(int length)
    {
        return GetStrings(length).ToArray();
    }

    public IEnumerable<string> GetNextLine()
    {
        yield return GetString();
        while (Elements.MoveNext() && Elements.Current != null)
        {
            yield return Elements.Current;
        }
    }

    public int GetInt()
    {
        return int.Parse(GetString());
    }

    public int[] GetIntArray()
    {
        return GetNextLine().Select(i => int.Parse(i)).ToArray();
    }

    public int[] GetIntArray(int length)
    {

        return GetStrings(length).Select(i => int.Parse(i)).ToArray();
    }

    public long GetLong()
    {
        return long.Parse(GetString());
    }

    public long[] GetLongArray()
    {
        return GetNextLine().Select(i => long.Parse(i)).ToArray();
    }

    public long[] GetLongArray(int length)
    {
        return GetStrings(length).Select(i => long.Parse(i)).ToArray();
    }

    public float GetFloat()
    {
        return float.Parse(GetString());
    }

    public float[] GetFloatArray()
    {
        return GetNextLine().Select(i => float.Parse(i)).ToArray();
    }

    public float[] GetFloatArray(int length)
    {
        return GetStrings(length).Select(i => float.Parse(i)).ToArray();
    }

    public double GetDouble()
    {
        return double.Parse(GetString());
    }

    public double[] GetDoubleArray()
    {
        return GetNextLine().Select(i => double.Parse(i)).ToArray();
    }

    public double[] GetDoubleArray(int length)
    {
        return GetStrings(length).Select(i => double.Parse(i)).ToArray();
    }

    public char GetChar()
    {
        return GetString().ToCharArray().Single();
    }

    public char[] GetChars()
    {
        return GetString().ToCharArray();
    }
}

public static class Utils
{
    public static string Join(this IEnumerable<string> strings)
    {
        return strings.Join(string.Empty);
    }

    public static string Join(this IEnumerable<string> strings, char separator)
    {
        return strings.Join(separator.ToString());
    }

    public static string Join(this IEnumerable<string> strings, string separator)
    {
        return string.Join(separator, strings.ToArray());
    }

    public static string Join<T>(this IEnumerable<T> elems)
    {
        return elems.Join(string.Empty);
    }

    public static string Join<T>(this IEnumerable<T> elems, char separator)
    {
        return elems.Join(separator.ToString());
    }

    public static string Join<T>(this IEnumerable<T> elems, string separator)
    {
        return elems.Select(elem => elem.ToString()).Join(separator);
    }
}
