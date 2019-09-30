using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ._2017.RQ
{
    public class P2 : CommonClass
    {
        string N;

        public P2(StreamReader fileIn) : base(fileIn)
        {
        }

        public void ReadData()
        {
            N = ReadString();
        }

        public string RemoveZero(string s)
        {
            int l = s.Length;
            for(int i=0; i<l; i++)
            {
                if (s[i] != '0')
                    return s.Substring(i);
            }
            return s;
        }

        public string Process()
        {
            int l = N.Length;
            string res = "";
            bool isFinish = true;
            for(int i=0; i<l-1; i++)
            {
                if(N[i] > N[i+1])
                {
                    res += (char)(N[i]-1);
                    for(i++; i<l; i++)
                    {
                        res += '9';
                    }
                    isFinish = false;
                }
                else
                {
                    res += N[i];
                }
            }
            if (isFinish)
            {
                res += N[l-1];
                return RemoveZero(res);
            }
            else
            {
                N = res;
                return Process();
            }
        }
    }
}
