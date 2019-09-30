using System;

class Program
{
    static void Main(string[] args)
    {
        var n = int.Parse(Console.ReadLine());
        var ans = "";

        while (n != 0)
        {
            if (n % 2 != 0)
            {
                n--;
                ans = "1" + ans;
            }
            else
            {
                ans = "0" + ans;
            }
            n /= -2;
        }

        if (ans == "") ans = "0";

        Console.WriteLine(ans);
    }
}