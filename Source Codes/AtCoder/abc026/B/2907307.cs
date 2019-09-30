using System;

class Program
{
    static void Main(string[] args)
    {
        int n = int.Parse(Console.ReadLine());
        int[] r = new int[n];
        for (int i = 0; i < n; i++)
            r[i] = int.Parse(Console.ReadLine());

        Sort(r, n);
        bool flag = false;
        double ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (flag == true)
            {
                ans -= Area(r[i]);
                flag = false;
            }
            else
            {
                ans += Area(r[i]);
                flag = true;
            }
        }

        Console.WriteLine(ans);
    }

    static double Area(int r)
    {
        double s = r * r * Math.PI;
        return s;
    }

    static void Sort(int[] r, int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < n; j++)
                if (r[j - 1] < r[j])
                {
                    int tmp = r[j - 1];
                    r[j - 1] = r[j];
                    r[j] = tmp;
                }
        }
    }
}