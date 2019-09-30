using System;

class Program
{
    public static void Main(string[] args)
    {
        int N, Q;
        string S;
        int[] ls;
        int[] rs;
        {
            {
                var nq = Console.ReadLine().Split(' ');
                N = int.Parse(nq[0]);
                Q = int.Parse(nq[1]);
            }
            S = Console.ReadLine();
            ls = new int[Q];
            rs = new int[Q];
            for (int i = 0; i < Q; i++)
            {
                {
                    var lr = Console.ReadLine().Split(' ');
                    ls[i] = int.Parse(lr[0]);
                    rs[i] = int.Parse(lr[1]);
                }
            }
        }

        int[] r = new int[S.Length + 1];
        {
            for (int i = 0; i < S.Length - "AC".Length + 1; i++)
            {
                r[i + 1] = r[i] + (S.Substring(i, 2) == "AC" ? 1 : 0);
            }
            for (int i = S.Length - "AC".Length + 1; i < S.Length; i++)
                r[i + 1] = r[i];
        }

        for (int i = 0; i < Q; i++)
        {
            Console.WriteLine(r[rs[i] - 1] - r[ls[i] - 1]);
        }
    }
}