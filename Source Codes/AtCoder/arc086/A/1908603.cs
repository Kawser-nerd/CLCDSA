using System;
using System.Linq;

class MainClass
{
    public static void Main(string[] args)
    {
        string[] s = Console.ReadLine().Split(' ');
        int N = int.Parse(s[0]);
        int K = int.Parse(s[1]);
        int[] b = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).OrderBy(x => x).ToArray();
        int[] a = new int[N+1];

        for (int i = 0; i < N;i++)
        {
            
            a[b[i]]++;
        }

        Array.Sort(a);
        Array.Reverse(a);
        int cnt = 0;
        int now = 0;
        int ans = 0;


        for (int i = K; i < N;i++)
        {
            ans += a[i];
        }
        //for (int i = 0; i < N;i++)
        //{
        //    if(now!=a[i])
        //    {
        //        cnt++;
        //        now = a[i];
        //    }

        //    if (cnt <= K) continue;

        //    ans++;

        //}

        Console.WriteLine(ans);
    }
}