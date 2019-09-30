using System.Linq;
using System;

public class Hello
{
    public static void Main()
    {
        var n = int.Parse(Console.ReadLine().Trim());
        string[] line = Console.ReadLine().Trim().Split(' ');
        var a = Array.ConvertAll(line, int.Parse);
        var psum = a.Sum();
        var pave = 0;
        if (psum % n != 0) { Console.WriteLine(-1); goto end; }
        else pave = psum / n;
        var pc = 0; var ic = 0;  var bc = 0;
        for (int i = 0; i < n; i++)
        {
            pc += a[i];
            ic++;
            if (pc % ic == 0 && pc  == pave * ic) { pc = 0; ic = 0; }
            else bc++;
        }
        Console.WriteLine(bc);
        end:;
    }
}