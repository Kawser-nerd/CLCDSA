using System;
using System.Collections.Generic;
using System.Linq;
using static Input;

public class Prog
{
    private const int INF = 1000000007;
    public static void Main()
    {
        int D = Cin<int>();
        int G = Cin<int>();
        int[] p = new int[D];
        int[] c = new int[D];
        for (int i = 0; i < D; i++) { p[i] = Cin<int>(); c[i] = Cin<int>(); }

        //bit???
        int M = (int)Math.Pow(2, D);
        int min = INF;
        for (int i = 0; i < M; i++)
        {
            int box = 0;
            int cou = 0;
            //2???bit?????
            for (int j = 0; j < D; j++)
            {
                if ((1 & i >> j) == 1)
                {
                    //1????????
                    box += 100 * (j + 1) * p[j] + c[j];
                    cou += p[j];
                }
            }
            if (box >= G) min = Math.Min(min, cou);
            else {
                //????
                for (int j = D-1; j != -1 ; j--) {
                    if ((1 & ~i >> j) == 1)
                    {
                        int count = 0;
                        //???????
                        while (true) {
                            box += 100 * (j + 1);
                            count++;
                            if (box >= G || count == p[j]) break;
                        }
                        cou += count;
                    }
                    if (box >= G) break;
                }
            }
            if (box >= G) min = Math.Min(min,cou);
        }
        Console.WriteLine(min);
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
        else return (T)(object)(-1);
    }
    public static T Line<T>()
    {
        if (typeof(T) == typeof(int[]))
        {
            return (T)(object)Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        }
        else if (typeof(T) == typeof(long[]))
        {
            return (T)(object)Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
        }
        else if (typeof(T) == typeof(string[]))
        {
            return (T)(object)Console.ReadLine().Split(' ').ToArray();
        }
        else if (typeof(T) == typeof(double[]))
        {
            return (T)(object)Console.ReadLine().Split(' ').Select(double.Parse).ToArray();
        }
        else return (T)(object)(-1);
    }
}