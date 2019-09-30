using System;
class c
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        var a = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
        int ans = 0;
        int cont = 0;
        for (int i = 1; i < a.Length; i++)
        {
            if (a[i - 1] == a[i]) cont++;
            else
            {
                ans += (cont + 1) / 2;
                cont = 0;
            }
            if (i == a.Length - 1) ans += (cont + 1) / 2;
        }
        Console.WriteLine(ans);
    }
}