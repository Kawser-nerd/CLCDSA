using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

class Program
{
    public void Proc()
    {
        Reader.IsDebug = false;
        int count = int.Parse(Reader.ReadLine());
        int[] list = Reader.ReadLine().Split(' ').Select(a => int.Parse(a)).ToArray();
        Dictionary<int, int> dic = new Dictionary<int, int>();
        list.ToList().ForEach(a =>
        {
            if (dic.ContainsKey(a))
            {
                dic[a]++;
            }
            else
            {
                dic[a] = 1;
            }
        });

        bool isCorrect = true;
        if (count % 2 == 0)
        {
            if (dic.Keys.Any(a => a == 0 || a > count -1))
            {
                isCorrect = false;
            } else {
                for(int i=1; i<=count-1; i+=2) {
                    if(!dic.ContainsKey(i)) {
                        isCorrect = false;
                        break;
                    }
                    if(dic[i] != 2) {
                        isCorrect = false;
                        break;
                    }
                }
            }
        }
        else
        {
            if (dic.Keys.Any(a => a > count- 1))
            {
                isCorrect = false;
            }
            else
            {
                for (int i = 0; i <= count-1; i+=2)
                {
                    if (!dic.ContainsKey(i))
                    {
                        isCorrect = false;
                        break;
                    }
                    if (i == 0)
                    {
                        if (dic[i] != 1)
                        {
                            isCorrect = false;
                            break;
                        }
                    }
                    else
                    {
                        if (dic[i] != 2)
                        {
                            isCorrect = false;
                            break;
                        }
                    }
                }
            }
        }

        if (isCorrect)
        {
            long ans = 1;
            long mod = 1000000000 + 7;

            for (int i = 0; i < count / 2; i++)
            {
                ans *= 2;
                ans = ans % mod;

            }
            Console.WriteLine(ans);
        }
        else
        {
            Console.WriteLine(0);
        }

    }


    public class Reader
    {
        public static bool IsDebug = true;
        private static String PlainInput = @"

7
6 4 0 2 4 0 2


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