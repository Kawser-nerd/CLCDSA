using System;

class Program
{
    static void Main(string[] args)
    {
        var a = Console.ReadLine();
        var s = int.Parse(Console.ReadLine());
        var U = 0; var R = 0; var WWW = 0;
        for (int i = 0; i < a.Length; i++)
        {
            var d = a[i];
            if (d == 'U') { U++; }
            else if (d == 'D') { U--; }
            else if (d == 'R') { R++; }
            else if (d == 'L') { R--; }
            else if (d == '?') { WWW++; }
        }
        if (U < 0) { U *= -1; }
        if (R < 0) { R *= -1; }
        if (s == 1) { Console.WriteLine(Math.Abs(R + U + WWW)); }
        else { int ans = U+R-WWW; Console.WriteLine(ans>0?ans:Math.Abs(ans%2)); }

    }
}