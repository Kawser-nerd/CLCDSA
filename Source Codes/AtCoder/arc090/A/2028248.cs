using System;

class MainClass
{
    public static void Main(string[] args)
    {
        
        //string[] s1 = Console.ReadLine().Split(' ');

        //long N = long.Parse(s1[0]);
        //long K = long.Parse(s1[1]);

        long N = long.Parse(Console.ReadLine());
        string[] s1 = Console.ReadLine().Split(' ');
        string[] s2 = Console.ReadLine().Split(' ');


        //long K = long.Parse(Console.ReadLine());
        long[,] a = new long[2,N];
        //long[] b = new long[N];

        for (int i = 0; i < N;i++)
        {
            //string[] s2 = Console.ReadLine().Split(' ');
            a[0,i] = long.Parse(s1[i]);
            a[1, i] = long.Parse(s2[i]);
            //b[i] = long.Parse(s1[1]);
        }

        long[] sum = new long[N];

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j <= i;j++)
            {
                sum[i] += a[0, j];
            }

            for (int j = i; j < N; j++)
            {
                sum[i] += a[1, j];
            }
                
        }

        Array.Sort(sum);
        Array.Reverse(sum);

        Console.WriteLine(sum[0]);

    }
}