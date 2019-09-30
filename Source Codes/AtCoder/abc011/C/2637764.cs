using System;

public class Hello
{
    public static void Main()
    {
        var n = int.Parse(Console.ReadLine().Trim());
        var ng = new int[3];
        for (int i = 0; i < 3; i++) ng[i] = int.Parse(Console.ReadLine().Trim());
        if (!checkOK(ng, n)) { Console.WriteLine("NO"); goto end; }
        for (int i = 0; i < 100; i++)
        {
            if (n -3 == 0 | n -2 == 0 | n -1 == 0) { Console.WriteLine("YES"); goto end; }
            if (checkOK(ng, n - 3)) n -= 3;
            else if (checkOK(ng, n - 2)) n -= 2;
            else if (checkOK(ng, n - 1)) n -= 1;
            else { Console.WriteLine("NO"); goto end; }
        }
        Console.WriteLine("NO");
        end:;
    }
    public static bool checkOK (int[] ng, int n)
    {
        foreach (var x in ng) if (x == n) return false;
        return true;
    }
}