using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Text;

public class Program
{

    public void Proc()
    {
        this.BaseNum = Reader.ReadLine();

        long ans = GetAns(0, BaseNum[0].ToString());
        Console.WriteLine(ans);
    }


    string BaseNum;
    private long GetAns(int idx, string subNum) {
        if(idx>=BaseNum.Length - 1) {
            return subNum.Split('+').Select(a => long.Parse(a)).Sum();
        }
        long ans = 0;

        ans += GetAns(idx + 1, subNum + "+" + BaseNum[idx + 1]);
        ans += GetAns(idx + 1, subNum + BaseNum[idx + 1]);
        return ans;
    }

    public class Reader
    {
        static StringReader sr;
        public static bool IsDebug = false;
        public static string ReadLine()
        {
            if (IsDebug)
            {
                if (sr == null)
                {
                    sr = new StringReader(InputText.Trim());
                }
                return sr.ReadLine();
            }
            else
            {
                return Console.ReadLine();
            }
        }
        private static string InputText = @"


125


";
    }

    public static void Main(string[] args)
    {
#if DEBUG
        Reader.IsDebug = true;
#endif
        Program prg = new Program();
        prg.Proc();
    }
}