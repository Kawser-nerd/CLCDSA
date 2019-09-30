using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int a = int.Parse(Console.ReadLine());
        //nt[] NQ = Console.ReadLine().Split().Select(int.Parse).ToArray();
        string[] s = new string[a].Select(_ => Console.ReadLine()).ToArray();
        for (int i = 0; i < a; i++)
        {
            string res = "";
            for (int j = 0; j < a; j++)
            {
                res += s[a-j-1][i];
            }
            Console.WriteLine(res);
        }
    }
}