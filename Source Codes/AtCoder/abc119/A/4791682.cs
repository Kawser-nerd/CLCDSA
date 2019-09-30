using System;

class Problem
{
    static void Main()
    {
        string s = Console.ReadLine();
        int n = int.Parse(s[6].ToString());
        int m = int.Parse(s[5].ToString());
        //Console.WriteLine("{0}{1}", n, m);
        if (m==1 || n > 4) Console.WriteLine("TBD");
        else Console.WriteLine("Heisei");
    }
}