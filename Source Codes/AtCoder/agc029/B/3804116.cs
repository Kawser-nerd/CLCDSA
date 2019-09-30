using System;

public class AtCoder
{
    public static void Main()
    {
        int n;
        n = int.Parse(Console.ReadLine().Trim());
        string[] s;
        s = Console.ReadLine().Trim().Split(' ');
        int[] a = new int[n];
        for (int i = 0; i < n; i++)
        {
            a[i] = int.Parse(s[i]);
        }
        Array.Sort(a);
        int[] b = new int[n];
        int x = 1;
        int ans = 0;
        bool fsuc = true;
        int y = (int)Math.Pow(2, 30);
        BinarySearch f = new BinarySearch(a);
        for (int i = n - 1; i > -1; i--)
        {
            if (b[i] == 1) continue;
            while (y / 2 > a[i])
            {
                y /= 2;
            }
            x = y - a[i];
            for (int j = f.UpperBound(x, i) - 1; j > -1; j--)
            {
                if (a[j] == x)
                {
                    if (b[j] == 0)
                    {
                        if (i != j)
                        {
                            b[i] = 1;
                            b[j] = 1;
                            ans++;
                            while (false)
                            {
                                if (i > 0 && j > 0)
                                {
                                    if ((a[i - 1] == a[i]) && (a[j - 1] == x)
                                        && (b[i - 1] == 0) && (b[j - 1] == 0))
                                    {
                                        i--;
                                        j--;
                                        b[i] = 1;
                                        b[j] = 1;
                                        ans++;
                                    }
                                    else fsuc = false;
                                }
                                else fsuc = false;
                            }
                            fsuc = true;
                            break;
                        }
                    }
                }
                if (a[j] < x) j = -1;
            }
        }
        Console.WriteLine(ans);
    }
}

public class BinarySearch
{

    int[] a;
    public BinarySearch(int[] arr)
    {
        a = arr;
    }

    public int LowerBound(int x, int i)
    {
        int l = -1;
        int r = i;
        while (r - l > 1)
        {
            int m = l + (r - l) / 2;
            if (a[m] >= x) r = m;
            else l = m;
        }
        return r;
    }

    public int UpperBound(int x, int i)
    {
        int l = -1;
        int r = i;
        while (r - l > 1)
        {
            int m = l + (r - l) / 2;
            if (a[m] > x) r = m;
            else l = m;
        }
        return r;
    }
}