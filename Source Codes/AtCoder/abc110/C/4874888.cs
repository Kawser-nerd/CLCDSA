using System;
using System.Linq;
using System.Collections.Generic;

class Cmondai
{
    static void Main()
    {
        var S = Console.ReadLine();
        var T = Console.ReadLine();
        //???
        var dicST = new Dictionary<char, char>();
        var dicTS = new Dictionary<char, char>();
        var ans = "Yes";
        for (int i=0; i<S.Length;++i)
        {
            if (!dicST.ContainsKey(S[i])) dicST.Add(S[i], T[i]);
            else
            {
                if (T[i] != dicST[S[i]])
                {
                    ans = "No";
                    break;
                }
            }
            if (!dicTS.ContainsKey(T[i])) dicTS.Add(T[i], S[i]);
            else
            {
                if (S[i] != dicTS[T[i]])
                {
                    ans = "No";
                    break;
                }
            }
        }
        Console.WriteLine(ans);
    }
}