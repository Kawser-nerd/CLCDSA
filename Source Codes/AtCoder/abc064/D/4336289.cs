// ABC 064 D Insertion

using System;

class Program
{
    static int N;
    static string S;

    static void Main()
    {
        /* ??????? */
        N = int.Parse(Console.ReadLine());
        S = Console.ReadLine();

        /* '('?+1,')'??? */
        int c = 0;
        int c_min = 0;
        for (int i = 0; i < N; i++)
        {
            c += S[i] == '(' ? 1 : -1;
            c_min = Math.Min(c, c_min);
        }

        /* -c_min???'('?????c - c_min??')'???? */
        for (int i = 0; i < -c_min; i++)
            Console.Write('(');
        Console.Write(S);
        for (int i = 0; i < c - c_min; i++)
            Console.Write(')');
        Console.WriteLine();
    }
}