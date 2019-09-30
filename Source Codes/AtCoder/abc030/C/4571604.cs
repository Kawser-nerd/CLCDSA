using System;
using System.Linq;
using System.Collections;
using System.Collections.Generic;

class Program
{
    public static void Main()
    {
        int N, M, X, Y;
        var str = Console.ReadLine().Split(' ');
        N = int.Parse(str[0]);
        M = int.Parse(str[1]);
        str = Console.ReadLine().Split(' ');
        X = int.Parse(str[0]);
        Y = int.Parse(str[1]);
        LinkedList<int> A = new LinkedList<int>();
        LinkedList<int> B = new LinkedList<int>();
        str = Console.ReadLine().Split(' ');
        for (int i = 0; i < N; i++)
            A.AddLast(int.Parse(str[i]));
        str = Console.ReadLine().Split(' ');
        for (int i = 0; i < M; i++)
            B.AddLast(int.Parse(str[i]));

        int ctr = -1;
        bool inA = true;
        int time = 0;
        while (true)
        {
            if (inA)
                ctr++;

            if (inA)
            {
                while (A.Count > 0 && time > A.First.Value)
                    A.RemoveFirst();
                if (A.Count == 0)
                    break;
                time = A.First.Value;
                A.RemoveFirst();
                time += X;
            }
            else
            {
                while (B.Count > 0 && time > B.First.Value)
                    B.RemoveFirst();
                if (B.Count == 0)
                    break;
                time = B.First.Value;
                B.RemoveFirst();
                time += Y;
            }
            inA = !inA;
        }
        Console.WriteLine(ctr);
    }
}