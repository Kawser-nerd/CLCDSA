using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

class Program
{
    public void Proc()
    {
        Reader.IsDebug = false;
        int cardCount = int.Parse(Reader.ReadLine());
        int[] cards = Reader.ReadLine().Split(' ').Select(a => int.Parse(a)).OrderBy(a => a).ToArray();
        Dictionary<int, int> dic = new Dictionary<int,int>();
       
        for (int i = 1; i < cards.Length; i++)
        {
            if (cards[i - 1] == cards[i])
            {
                if(!dic.ContainsKey(cards[i])) {
                    dic.Add(cards[i], 1);
                } else {
                   dic[cards[i]]++;
                }
            }
        }

        int ans = cards.Length;
        if (dic.Count > 0)
        {
            while (dic.Count > 1)
            {
                int key = dic.Keys.First();
                int nex = dic.Keys.Skip(1).First();
                if (key == nex)
                {
                    break;
                }
                if (dic[key] > dic[nex])
                {
                    ans -= dic[nex]*2;
                    dic[key] -= dic[nex];
                    dic[nex] = 0;
                }
                else
                {
                    ans -= dic[key]*2;
                    dic[nex] -= dic[key];
                    dic[key] = 0;
                }
                if (dic[key] == 0)
                {
                    dic.Remove(key);
                }
                if (dic[nex] == 0)
                {
                    dic.Remove(nex);
                }
            }
            int nokori = dic.Select(a=>a.Value).Sum();
            while (nokori >= 2)
            {
                ans -= 2;
                nokori -= 2;
            }
            ans -= nokori * 2;
        }
        Console.WriteLine(ans);


    }



    public class Reader
    {
        public static bool IsDebug = true;
        private static String PlainInput = @"



15
1 3 5 2 1 3 2 8 8 6 2 6 11 1 1


";
        private static System.IO.StringReader Sr = null;
        public static string ReadLine()
        {
            if (IsDebug)
            {
                if (Sr == null)
                {
                    Sr = new System.IO.StringReader(PlainInput.Trim());
                }
                return Sr.ReadLine();
            }
            else
            {
                return Console.ReadLine();
            }
        }
    }
    static void Main()
    {
        Program prg = new Program();
        prg.Proc();
    }
}