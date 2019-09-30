using System;

public class Program
{
    static void Main()
    {
        var s = Console.ReadLine();
        var t = Console.ReadLine();
        for (int i = 0; i < s.Length; i++)
        {
            if (t == s)
            {
                Console.WriteLine("Yes");
                return;
            }

            var buf = t[t.Length - 1];
            t = t.Remove(t.Length - 1);
            t = t.Insert(0, buf.ToString());
        }

        Console.WriteLine("No");
    }
}