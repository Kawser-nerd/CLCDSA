using System;

class Program
{
    static void Main(string[] args)
    {
        //??
        string S = Console.ReadLine();

        Console.WriteLine( ManyFormulas(S, 0) );

    }

    static ulong ManyFormulas(string s, int begin)
    {
        ulong ret = 0;
        for(int i = begin; i < s.Length; i++)
        {
            ret += (ulong.Parse(s.Substring(begin, i - begin + 1)) << Math.Max(0, s.Length - i - 2));
            ret += ManyFormulas(s, i + 1);
        }
        return ret;
    }
}