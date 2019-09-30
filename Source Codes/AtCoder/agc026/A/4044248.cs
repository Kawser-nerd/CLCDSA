using System;

    class AGC026A
    {
        static void Main(string[] args)
        {
            Method(args);
        }

        static void Method(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] a = new int[n];
            string[] input = Console.ReadLine().Split(' ');

            for(int i = 0; i < n; i++)
            {
                a[i] = int.Parse(input[i]);
            }

            int cnt = 0;

            for(int i = 0; i < n-1; i++)
            {
                if(a[i] == a[i + 1])
                {
                    cnt++;
                    i++; // ?????????????
                }
            }

            Console.WriteLine(cnt);
        }
    }