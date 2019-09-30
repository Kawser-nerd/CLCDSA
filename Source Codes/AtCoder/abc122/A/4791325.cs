using System;

class Problem
{
    public static void Main()
    {
        char[] a = { 'A', 'T', 'C', 'G' };
        char[] b = { 'T', 'A', 'G', 'C' };
        string s = Console.ReadLine();
        for(int i=0; i < 4; i++)
        {
            if (s[0] == a[i])
            {
                Console.Write(b[i]);
            }
        }
    }
    
}