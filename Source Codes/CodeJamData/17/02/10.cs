using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ
{
    class B : GCJBase
    {
        public override void Solve()
        {
            string sLines = Console.ReadLine();
            int iCases = int.Parse(sLines);

            System.Threading.Tasks.Task<string>[] tasks = new System.Threading.Tasks.Task<string>[iCases];

            for (int iCase = 1; iCase <= iCases; iCase++)
            {
                string s = Console.ReadLine();
                tasks[iCase - 1] = System.Threading.Tasks.Task.Run<string>
                    (
                        () => DoWork(s)
                    );
                //tasks[iCase - 1].Wait();
            }

            for (int iCase = 1; iCase <= iCases; iCase++)
            {
                string ret = tasks[iCase - 1].Result;
                Console.WriteLine("Case #{0}: {1}", iCase, ret);
                System.Diagnostics.Debug.WriteLine("Case #{0}: {1}", iCase, ret);
            }
        }

        public string DoWork(string s)
        {
            for (int i = 0; i < s.Length-1; i++)
            {
                if (s[i]>s[i+1])
                {
                    char[] c = s.ToCharArray();
                    c[i]--;
                    for (int j = i+1; j < s.Length; j++)
                    {
                        c[j] = '9';
                    }
                    string ret = new string(c);
                    if (i == 0 && c[i] == '0') ret = ret.Substring(1);
                    //return ret;
                    return DoWork(ret);
                }
            }
            return s;
        }

        public bool IsNeat(string s)
        {
            for (int i = 0; i < s.Length-1; i++)
            {
                if (s[i] > s[i + 1]) return false;
            }
            return true;
        }

        public int RealNeat(int i)
        {
            for (int j = i; j >=0 ; j--)
            {
                if (IsNeat(j.ToString())) return j;
            }
            return -1;
        }
    }
}
