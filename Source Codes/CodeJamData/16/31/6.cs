using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace _2016Round1C
{
    class Program
    {
        static void Main(string[] args)
        {
            A();
        }

        static void A()
        {
            StreamReader sr = new StreamReader("C:\\CodeJam\\2016\\Round1C\\A-large.in");
            StreamWriter sw = new StreamWriter("C:\\CodeJam\\2016\\Round1C\\A-large.out");

            int T, N;

            T = int.Parse(sr.ReadLine());
            for (int x = 1; x <= T; x++)
            {
                N = int.Parse(sr.ReadLine());
                string s = sr.ReadLine();
                Senate senate = new Senate(N, s);
                sw.Write("Case #");
                sw.Write(x.ToString());
                sw.Write(": ");
                while(senate.Total>0)
                {
                    sw.Write(senate.Evacuate());
                }
                sw.WriteLine();
            }
            sw.Close();
            sr.Close();
        }

    }

    class Senate
    {
        public int Total;
        public int[] Members;
        
        public Senate(int parties, string members)
        {
            Total = 0;

            string[] toks = members.Split(' ');
            Members = new int[parties];
            for (int i = 0; i < parties; i++)
            {
                Members[i] = int.Parse(toks[i]);
                Total += Members[i];
            }
        }

        public string Evacuate()
        {
            string s = "";
            //if Total is 3 - we may have to remove one only?
            int max = 0;
            for(int i = 0; i<Members.Length; i++)
            {
                if(Members[i]>max)
                {
                    max = Members[i];
                }
            }
            if(max > 1)//bring down till 1;
            {
                int c = 0;
                for (int i = 0; i < Members.Length; i++)
                {
                    if (Members[i] == max)
                    {
                        Members[i]--;
                        Total--;
                        s = s + new string(new char[] { (char)('A' + i) });
                        c++;
                        if(c==2)
                        {
                            break;
                        }
                    }
                }
            }
            else//we have all 1. first make is even
            {
                if(Total%2==1)
                {
                    //remove only one;
                    for (int i = 0; i < Members.Length; i++)
                    {
                        if (Members[i] == 1)
                        {
                            Members[i]--;
                            Total--;
                            s = s + new string(new char[] { (char)('A' + i) });
                            break;
                        }
                    }
                }
                else //remove 2;
                {
                    int c = 0;
                    for (int i = 0; i < Members.Length; i++)
                    {
                        if (Members[i] == 1)
                        {
                            Members[i]--;
                            Total--;
                            s = s + new string(new char[] { (char)('A' + i) });
                            c++;
                            if (c == 2)
                            {
                                break;
                            }
                        }
                    }
                }
            }
            if(Total > 0)
            {
                s = s + " ";
            }
            return s;
        }
    }
}
