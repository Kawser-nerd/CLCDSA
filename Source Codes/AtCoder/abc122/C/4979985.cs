using System;

class Program
{
   static int Main()
    {
        string[] in1 = Console.ReadLine().Split(' '),in2;
        int n = int.Parse(in1[0]), q = int.Parse(in1[1]),l,r;
        int[] ac = new int[n];
        string s = Console.ReadLine();
        for (var i = 1; i < n; i++)
        {
            if (s[i - 1] == 'A' && s[i] == 'C')
            {
                ac[i] = ac[i - 1] + 1;
            }
            else {
                ac[i] = ac[i - 1];
            }
        }
        for (var i = 0; i < q; i++)
        {
            in2 = Console.ReadLine().Split(' ');
            l = int.Parse(in2[0])-1;
            r = int.Parse(in2[1])-1;
            Console.WriteLine((ac[r] - ac[l]).ToString("d"));
        }
        return 0;
    }
}