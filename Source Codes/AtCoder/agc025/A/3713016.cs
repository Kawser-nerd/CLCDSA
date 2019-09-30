using System;
class c
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int ans = int.MaxValue;
        for (int i = 1; i < n; i++)
        {
            string a = i.ToString();
            string b = (n - i).ToString();
            int x = 0;
            for (int j = 0; j < a.Length; j++) x += int.Parse(a[j].ToString());
            for (int j = 0; j < b.Length; j++) x += int.Parse(b[j].ToString());
            ans = Math.Min(ans, x);
        }
        Console.WriteLine(ans);
    }
}