using System;
using System.Linq;
using static System.Console;

class AtCoder
{
    public static void Main()
    {
        var t = ReadIntArray();
        int n = t[0];
        int q = t[1];
        var s = ReadLine();

        var a = new int[n]; a[0] = 0;
        int ct = 0;
        for (int i = 0; i < n - 1; i++){
            if (s[i] == 'A' && s[i+1] == 'C'){
                ct++;    
            }
            a[i+1] = ct;
        }

        for (int i = 0; i < q; i++){
            var x = ReadIntArray();
            int l = x[0];
            int r = x[1];
            WriteLine(a[r-1] - a[l-1]);
        }        
    }

    static int[] ReadIntArray()
    {
        return ReadLine().Split().Select(x => int.Parse(x)).ToArray();
    }
}