using System;
using System.Linq;
using System.Text;

class Program
{
    static void Main(string[] args)
    {
        new Solver().Solve();
#if DEBUG
        Console.ReadLine();
#endif
    }
}

class Solver
{
    string A;
    string B;
    string S;

    public void Solve()
    {
        // ??????????????
        StringBuilder sb = new StringBuilder();
        sb.Append(@"\A\d{");
        sb.Append(A);
        sb.Append(@"}-\d{");
        sb.Append(B);
        sb.Append(@"}\z");
        string pattern = sb.ToString();

        bool is_match = System.Text.RegularExpressions.Regex.IsMatch(S, pattern);

        if (is_match)
        {
            Console.WriteLine("Yes");
        }
        else
        {
            Console.WriteLine("No");
        }
    }

    public Solver()
    {
        string[] AB = ReadStringArray();
        A = AB[0];
        B = AB[1];
        S = ReadString();
    }

    static String ReadString() { return Console.ReadLine(); }
    static int ReadInt() { return int.Parse(Console.ReadLine()); }
    static long ReadLong() { return long.Parse(Console.ReadLine()); }
    static double ReadDouble() { return double.Parse(Console.ReadLine()); }
    static String[] ReadStringArray() { return Console.ReadLine().Split(' '); }
    static int[] ReadIntArray() { return Console.ReadLine().Split(' ').Select(e => int.Parse(e)).ToArray(); }
    static long[] ReadLongArray() { return Console.ReadLine().Split(' ').Select(e => long.Parse(e)).ToArray(); }
    static double[] ReadDoubleArray() { return Console.ReadLine().Split(' ').Select(e => double.Parse(e)).ToArray(); }
}