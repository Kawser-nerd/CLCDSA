using System;

public class Hello
{
    public static void Main()
    {
        var n = int.Parse(Console.ReadLine().Trim());
        var a = new int[n];
        for (int i = 0; i < n; i++) a[i] = int.Parse(Console.ReadLine().Trim());
        Array.Sort(a);
        var sign = 1;  var suma = 0;
        for (int i = n-1; i >= 0; i--)
        {
            suma += sign * a[i] * a[i];
            sign *= -1;
        }
        var res = suma * Math.PI;
        Console.WriteLine(res);
    }
}