using System;


class MainClass
{
    public static void Main(string[] args)
    {

        int N = int.Parse(Console.ReadLine());
        string[] s = Console.ReadLine().Split(' ');
        int[] a = new int[N];
        int ans = 0;

        for (int j = 0; j < N;j++)
        {

            a[j] = int.Parse(s[j]);

        }

        Array.Sort(a);
        int i = 0;
        int nowCnt = 0;
        int nowNum =0;

        while(true)
        {

            ans += 1;


            if(a[i]==nowNum)
            {
                nowCnt += 1;
            }
            else
            {
                nowNum = a[i];
                nowCnt = 1;
            }


            if(nowCnt==a[i])
            {
                ans -= a[i];
            }

            i = i + 1;

            if (i >= N) break;

        }

        Console.WriteLine(ans);

    }
}