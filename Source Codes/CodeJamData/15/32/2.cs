using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2015R1C
{
    class Program
    {
        static void Main(string[] args)
        {
            int tt = int.Parse(Console.ReadLine());
            for (int cc = 1; cc <= tt; cc++)
            {
                var argss = Console.ReadLine().Split(new char[] { ' ' });
                int k, l, s;
                k = int.Parse(argss[0]);
                l = int.Parse(argss[1]);
                s = int.Parse(argss[2]);

                int prepare=0;
                string keys = Console.ReadLine();
                string targets = Console.ReadLine();
                Dictionary<char, int> keys_ct =
                    new Dictionary<char, int>();

                foreach(char c in keys){
                    if (keys_ct.ContainsKey(c))
                        keys_ct[c]++;
                    else
                        keys_ct.Add(c, 1);
                }

                bool invalid = false;
                foreach (char c in targets)
                {
                    if (!keys_ct.ContainsKey(c))
                        invalid = true;
                }
                if (invalid) {
                    Console.WriteLine(
                        "Case #" + cc.ToString() + ": 0.0");
                    continue; 
                }

                double[,] trans_table = new double[101, 101];
                for(int i=0;i<=l;i++){
                    trans_table[i,0]=1;
                    for (int j = 1; j <= l; j++)
                    {
                        trans_table[i, j] = 0;
                    }
                }

                for (int i = 0; i <= l; i++)
                {
                    string ts = targets.Substring(0, i);
                    foreach (var key_ct in keys_ct)
                    {
                        string tts = ts + key_ct.Key;

                        bool not_found = true;
                        for (int j = 0; j < tts.Length && not_found==true; j++)
                            if (targets.StartsWith(tts.Substring(j)))
                            {
                                double precentage = ((double)key_ct.Value) / k;
                                trans_table[i, tts.Length - j] += precentage;
                                trans_table[i, 0] -= precentage;
                                not_found = false;
                            }
                    }
                }

                for (int i = l; i >= 0; i--)
                {
                    if (trans_table[l, i] != 0)
                    {
                        if (s < l) prepare = 0;
                        else {
                            prepare = 1 + (s - l) / (l - i + 1);
                        }
                        break;
                    }
                }

                double[,] ret = new double[101, 101];
                ret[0, 0] = 1;
                double ans = prepare;

                for (int i = 1; i <= s; i++)
                {
                    for (int p = 0; p <= l; p++)
                    {
                        for (int q = 0; q <= l; q++)
                        {
                            if (trans_table[p, q] != 0)
                            {
                                ret[i, q] += ret[i - 1, p] * trans_table[p, q];
                                if (q == l)
                                    ans -= ret[i - 1, p] * trans_table[p, q];
                            }
                        }
                    }
                }

                Console.WriteLine(
                    "Case #" + cc.ToString() + ": " + ans.ToString("N9"));
            }
        }
    }
}
