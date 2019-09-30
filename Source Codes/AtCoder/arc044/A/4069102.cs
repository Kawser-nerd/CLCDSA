using System;
using System.Collections.Generic;
using System.Linq;
using static Input;

public class Hello
{
    private const int INF = 1000000007;
    public static void Main()
    {
        int N = Cin<int>();
        bool prime = false;
        if (IsPrime(N)) prime = true;
        if (N == 1) ;
        else
        {
            if (int.Parse(N.ToString()[(int)Math.Log10(N)].ToString()) % 2 == 0 ||
                int.Parse(N.ToString()[(int)Math.Log10(N)].ToString()) % 5 == 0) ;
            else if (N.ToString().ToCharArray().Select(v => int.Parse(v.ToString())).Sum() % 3 == 0) ;
            else prime = true;
        }
        Console.WriteLine(prime ? "Prime" : "Not Prime");
    }
    public static bool IsPrime(long n)
    {
        if (n < 2) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;

        double root = Math.Sqrt(n);
        for (int i = 3; i <= root; i += 2)
        {
            if (n % i == 0) return false;
        }
        return true;
    }
}

public class Input
{
    private static Queue<string> queue = new Queue<string>();
    public static T Cin<T>()
    {
        if (queue.Count == 0) foreach (var s in Console.ReadLine().Split(' ')) queue.Enqueue(s);
        if (typeof(T) == typeof(int)) return (T)(object)int.Parse(queue.Dequeue());
        else if (typeof(T) == typeof(long)) return (T)(object)long.Parse(queue.Dequeue());
        else if (typeof(T) == typeof(string)) return (T)(object)(queue.Dequeue());
        else if (typeof(T) == typeof(double)) return (T)(object)double.Parse(queue.Dequeue());
        else return (T)(object)(0);
    }
    public static T Line<T>()
    {
        foreach (var s in Console.ReadLine().Split(' ')) queue.Enqueue(s);
        int c = queue.Count();
        if (typeof(T) == typeof(int[]))
        {
            int[] ret = new int[c];
            for (int i = 0; i < c; i++) ret[i] = Cin<int>();
            return (T)(object)ret;
        }
        else if (typeof(T) == typeof(long[]))
        {
            long[] ret = new long[c];
            for (int i = 0; i < c; i++) ret[i] = Cin<long>();
            return (T)(object)ret;
        }
        else if (typeof(T) == typeof(string[]))
        {
            string[] ret = new string[c];
            for (int i = 0; i < c; i++) ret[i] = Cin<string>();
            return (T)(object)ret;
        }
        else if (typeof(T) == typeof(double[]))
        {
            double[] ret = new double[c];
            for (int i = 0; i < c; i++) ret[i] = Cin<double>();
            return (T)(object)ret;
        }
        else return (T)(object)(0);
    }
}