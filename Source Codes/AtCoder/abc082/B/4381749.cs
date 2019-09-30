using System;
using System.Linq;

public class Program
{
    public static void Main()
    {
        var s = Console.ReadLine();
        var t = Console.ReadLine();
        if ( s.CompareTo(t) < 0 )
        {
            Console.WriteLine("Yes");
            return;
        }
        var s2 = s.ToCharArray();
        Array.Sort(s2);
        var s_dash = new String(s2);
        var t2 = t.ToCharArray();
        t2 = t2.OrderByDescending( x => x ).ToArray();
        var t_dash = new String(t2);
        if ( s_dash.CompareTo(t_dash) < 0 )
        {
            Console.WriteLine("Yes");
        }
        else
        {
            Console.WriteLine("No");
        }
    }
}