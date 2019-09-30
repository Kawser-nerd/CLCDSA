using System;
using System.Text;
using System.Collections.Generic;
class Program
{
    //static List<string> str = new List<string>();
    static void Main(string[] args)
    {
        // ????t?F?[?Y
        string S = Console.ReadLine();
        string T = Console.ReadLine();

        // S?????u?????????
        int len = S.Length;
        Dictionary<char, char> dicS = new Dictionary<char, char>();
        Dictionary<char, char> dicT = new Dictionary<char, char>();
        bool canSwap = true;
        for (int i = 0; i < len; i++)
        {
            // S[i]??T[i]
            if(!dicS.ContainsKey(S[i]))
            {
                dicS.Add(S[i], T[i]);
            }
            else
            {
                if(dicS[S[i]].CompareTo(T[i]) != 0)
                {
                    canSwap = false;
                    break;
                }
            }

            if (!dicT.ContainsKey(T[i]))
            {
                dicT.Add(T[i], S[i]);
            }
            else
            {
                if (dicT[T[i]].CompareTo(S[i]) != 0)
                {
                    canSwap = false;
                    break;
                }
            }
        }
        //Console.WriteLine(sb.ToString());
        //Console.WriteLine(T);
        if (canSwap)
        {
            // ?u???????????
            Console.WriteLine("Yes");
        }
        else
        {
            Console.WriteLine("No");
        }
    }

    //static void swap(ref StringBuilder S, char a, char b)
    //{
    //    S.Replace(a, '*');
    //    S.Replace(b, a);
    //    S.Replace('*', b);
    //}

}