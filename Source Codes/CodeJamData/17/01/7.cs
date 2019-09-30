using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ._2017.RQ
{
    public class P1 : CommonClass
    {

        public string S;
        public int K;

        public P1(StreamReader fileIn) : base(fileIn)
        {
        }

        public void ReadData()
        {
            string[] s = ReadStringArray(_fileIn);
            S = s[0];
            K = Convert.ToInt32(s[1]);
        }

        public string Process()
        {
            int N = S.Length;
            char[] SA = S.ToArray();
            int res = 0;
            for(int i = 0; i<N; i++)
            {
                if(SA[i] == '-')
                {
                    if(i + K - 1 >= N)
                    {
                        return "IMPOSSIBLE";
                    }
                    res++;
                    for(int j=0; j<K; j++)
                    {
                        if (SA[i + j] == '-')
                        {
                            SA[i + j] = '+';
                        }
                        else
                        {
                            SA[i + j] = '-';
                        }
                    }
                }

            }
            return res+"";
        }
    }
}
