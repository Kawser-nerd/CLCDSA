using System;
using System.Linq;
using System.Collections.Generic;

class Cmondai
{
    static void Main()
    {
        var S = Console.ReadLine().ToCharArray();
        var K = Int64.Parse(Console.ReadLine());
        var count = 0L;
        for (int i=0;i<S.Count();++i)
        {
            if (S[i] == '1') count++;
            else break;
        }
        Console.WriteLine(K<=count?'1':S[count]);
    }
}