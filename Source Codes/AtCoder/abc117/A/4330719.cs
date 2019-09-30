using System;
class Program
{
    static void Main()
    {
        string[] s = Console.ReadLine().Split(' ');
        int t,x;
        t = int.Parse(s[0]);
        x = int.Parse(s[1]);
        double ans;
        ans = t*1.0/x;
        Console.WriteLine(ans);
    }
}