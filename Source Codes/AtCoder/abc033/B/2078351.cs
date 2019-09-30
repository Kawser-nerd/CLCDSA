using System;
using System.Linq;
class Program
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        string[] s = new string[n];
        int[] p = new int[n];
        string[] import;
        int po = 0;
        for (int i = 0; i < n; i++)
        {
            import = Console.ReadLine().Split(' ');
            s[i] = import[0];
            p[i] = int.Parse(import[1]);
            po += p[i];
        }
        po = po / 2 + 1;
        bool f = true;
        for (int i = 0; i < n; i++)
        {
            if (p[i] >= po)
            {
                Console.WriteLine(s[i]);
                f = false;
                break;
            }
        }
        if (f) Console.WriteLine("atcoder");
    }
}