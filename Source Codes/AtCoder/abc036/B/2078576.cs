using System;
class Program
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        if (n > 1)
        {
            string str;
            char[,] s = new char[n, n];
            for (int i = 0; i < n; i++)
            {
                str = Console.ReadLine();
                for (int j = 0; j < n; j++)
                    s[i, j] = str[j];
            }
            char[,] ans = new char[n, n];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    ans[j, n - 1 - i] = s[i, j];
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                    Console.Write(ans[i, j]);
                Console.WriteLine();
            }
        }
        else
        {
            string s = Console.ReadLine();
            Console.WriteLine(s);
        }
    }
}