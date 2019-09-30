using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC122B
{
    class Program
    {
        public static string[] st;
        public static int counter = 0;
        static void Main(string[] args)
        {
            string s = Console.ReadLine();
            st = new string[s.Length];
            for (int i = 0; i < s.Length; i++)
            {
                st[i] = s.Substring(i, 1);
            }
            int max = 0;
            int tmp = 0;
            for (int i = 0; i <s.Length ; i++)
            {
                counter = 0;
                tmp=nextString(i);
                if (tmp > max) max = tmp;
            }
            Console.WriteLine(max);
        }
        public static int nextString(int n)
        {
            if ((st[n] == "A") || (st[n] == "C") || (st[n] == "G") || (st[n] == "T"))
            {
                counter++;
                if(n<st.Length-1)  nextString(n + 1);//??????????????
            }
            return counter;
        }
    }
}