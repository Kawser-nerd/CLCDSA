using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using System.Globalization;

public class A
{
    public static void Main(string[] args)
    {
        Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
        int CASES = int.Parse(Console.ReadLine());
        for (int CASE = 1; CASE <= CASES; CASE++)
        {
            int N = int.Parse(Console.ReadLine());
            string[] matrix = new string[N];
            for (int i = 0; i < N; i++)
                matrix[i] = Console.ReadLine();

            int K = 0;
            for (int i = 0; i < N; i++)
            {
                int j = i;
                while (!can(matrix, j, i, N)) j++;

                for (int k = j; k > i; k--)
                {
                    string tmp = matrix[k];
                    matrix[k] = matrix[k - 1];
                    matrix[k - 1] = tmp;
                    K++;
                }
            }

            Console.WriteLine("Case #" + CASE + ": " + K);
        }
    }

    static bool can(string[] matrix, int i, int j, int N)
    {
        for (int k = j + 1; k < N; k++)
        {
            if (matrix[i][k] == '1') return false;
        }
        return true;
    }
}
