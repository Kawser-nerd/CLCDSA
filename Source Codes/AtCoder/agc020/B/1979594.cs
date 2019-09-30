using System;

class MainClass
{
    public static void Main(string[] args)
    {
        long K = long.Parse(Console.ReadLine());
        string[] s = Console.ReadLine().Split(' ');
        long[] a = new long[K];

        for (long i = 0; i < K;i++)
        {
            a[i] = long.Parse(s[i]);
        }

        long max = a[K - 1] * 2 - 1;
        long min = a[K - 1];

        if(min != 2)
        {
            Console.WriteLine("-1");
            return;
        }
        if(K==1)
        {
            Console.WriteLine("{0} {1}", min, max);
            return;
        }

        for(long i = K-2; i >= 0; i--)
        {
            long j = (min / a[i]) * a[i];


            bool mi = true;

            while(true)
            {
                if (j >= min && mi)
                {
                    min = j;
                    mi = false;
                    j = (max / a[i]) * a[i];
                }

                if (j > max)
                {
                    max = j - 1;

                    if (max <= min)
                    {
                        Console.WriteLine("-1");
                        return;
                    }

                    break;
                }

                j += a[i];


            }

        }

        Console.WriteLine("{0} {1}", min, max);
        return;

    }
}