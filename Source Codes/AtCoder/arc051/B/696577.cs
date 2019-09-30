using System;
using System.IO;
using System.Linq;
using System.Text;
using System.Collections.Generic;
using System.Diagnostics;
using System.Numerics;
using Enu = System.Linq.Enumerable;

public class Program
{
    public void Solve()
    {
        int K = Reader.Int();
        int[] A = new int[41];
        int[] B = new int[41];
        A[1] = 1;
        B[1] = 1;
        A[2] = 1;
        B[2] = 2;

        for (int k = 3; k <= K; k++)
        {
            A[k] = A[k - 1] + A[k - 2];
            B[k] = B[k - 1] + B[k - 2];
        }

        Console.WriteLine(A[K] + " " + B[K]);
    }
}

class Entry { static void Main() { new Program().Solve(); } }
class Reader
{
    private static TextReader reader = Console.In;
    private static readonly char[] separator = { ' ' };
    private static readonly StringSplitOptions op = StringSplitOptions.RemoveEmptyEntries;
    private static string[] A = new string[0];
    private static int i;
    private static void Init() { A = new string[0]; }
    public static void Set(TextReader r) { reader = r; Init(); }
    public static void Set(string file) { reader = new StreamReader(file); Init(); }
    public static bool HasNext() { return CheckNext(); }
    public static string String() { return Next(); }
    public static int Int() { return int.Parse(Next()); }
    public static long Long() { return long.Parse(Next()); }
    public static double Double() { return double.Parse(Next()); }
    public static int[] IntLine() { return Array.ConvertAll(Split(Line()), int.Parse); }
    public static int[] IntArray(int N) { return Enu.Range(0, N).Select(i => Int()).ToArray(); }
    public static int[][] IntTable(int H) { return Enu.Range(0, H).Select(i => IntLine()).ToArray(); }
    public static string[] StringArray(int N) { return Enu.Range(0, N).Select(i => Next()).ToArray(); }
    public static string Line() { return reader.ReadLine().Trim(); }
    private static string[] Split(string s) { return s.Split(separator, op); }
    private static string Next() { CheckNext(); return A[i++]; }
    private static bool CheckNext()
    {
        if (i < A.Length) return true;
        string line = reader.ReadLine();
        if (line == null) return false;
        if (line == "") return CheckNext();
        A = Split(line);
        i = 0;
        return true;
    }
}