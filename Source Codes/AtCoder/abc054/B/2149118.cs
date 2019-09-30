using System;
class Program
{
    public static void Main()
    {
        string[] imp = Console.ReadLine().Split(' ');
        int n, m;
        n = int.Parse(imp[0]);
        m = int.Parse(imp[1]);
        char[][] a = new char[n][];
        char[][] b = new char[m][];
        for (int i = 0; i < n; i++)
            a[i] = Console.ReadLine().ToCharArray();
        for (int i = 0; i < m; i++)
            b[i] = Console.ReadLine().ToCharArray();
        bool f = true;
        for (int p = 0; p <= n - m; p++)
        {
            for (int q = 0; q <= n - m; q++)
            {
                f = true;
                for (int i = 0; i < m; i++)
                    for (int j = 0; j < m; j++)
                        f = f && a[p + i][q + j] == b[i][j];
                if (f)
                    break;
            }
            if (f)
                break;
        }
        Console.WriteLine(f ? "Yes" : "No");
    }
}