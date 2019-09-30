using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace cl1
{
    class Program
    {
        StreamReader fin;
        StreamWriter fout;
        public static string Reverse(string s)
        {
            char[] charArray = s.ToCharArray();
            Array.Reverse(charArray);
            return new string(charArray);
        }
        bool Palindrome(string s)
        {
            return Reverse(s).Equals(s);
        }
        bool Palindrome(long s)
        {
            return Palindrome(s.ToString());
        }
        void run()
        {
            fin = new StreamReader("C-large-1.in");
            fout = new StreamWriter("C-large-1.out");
            //
            List<long> aw = new List<long>();
            for(int i=1;i<=10000000;i++)
                if (Palindrome(i)&&Palindrome((long)i*i))
                {
                    aw.Add((long)i*i);
                }
            long[] a = aw.ToArray();
            int T = Convert.ToInt32(fin.ReadLine());
            for (int t = 1; t <= T; t++)
            {
                string[] b = fin.ReadLine().Split();
                long l = long.Parse(b[0]), r = long.Parse(b[1]);
                int S=0;
                for(int i=0;i<a.Length;i++)
                    if(l<=a[i]&&a[i]<=r)
                    {
                        S++;
                    }
                fout.WriteLine("Case #"+t.ToString()+": "+S.ToString());
            }
            fin.Close();
            fout.Close();
        }
        static void Main(string[] args)
        {
            new Program().run();
        }
    }
}
