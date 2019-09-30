using System;
class Program
{
    static int func(string s)
    {
        int l = 0,j;
        for(var i=0; i<s.Length; i++)
        {
            if (s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T')
            {
                for (j = i + 1; j < s.Length && (s[j] == 'A' || s[j] == 'C' || s[j] == 'G' || s[j] == 'T'); j++);
                if (j - i > l)
                {
                    l = j - i;
                }
                i = j;
            }
        }
        return l;
    }
    static int Main(string[] args)
    {
        Console.WriteLine(func(Console.ReadLine()).ToString("d"));
        return 0;
    }
}