using System;
using System.Linq;
using System.Collections.Generic;
using System.Text;

class Program
{
    static readonly char _one = '1';
    static readonly char _nine = '9';

    static void Main(string[] args)
    {
        // 1?9??9?1?????????1??????????????.

        char[] StrArray = Console.ReadLine()
                                .ToList()
                                .Select(x => x == _one ? _nine : (x == _nine ? _one : x))
                                .ToArray();

        Console.Write( string.Join( "", StrArray ) );

#if DEBUG
        Console.ReadLine();
#endif
    }
}