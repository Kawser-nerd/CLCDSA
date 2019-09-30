using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Text;

public class Program
{

    public void Proc()
    {
        int itemCOunt = int.Parse(Reader.ReadLine());
        long[] items = Reader.ReadLine().Split(' ').Select(a => long.Parse(a)).OrderBy(a=>a). ToArray();
        Dictionary<long, int> cnt = new Dictionary<long, int>();
        for (int i = 0; i < items.Length;i++) {
            if(cnt.ContainsKey(items[i])) {
                cnt[items[i]]++;
            } else {
                cnt[items[i]] = 1;
            }
        }

        long ans = 0;
        foreach(long key in cnt.Keys) {
            if(cnt[key]>key) {
                ans += cnt[key] - key;
            } else if(cnt[key]<key) {
                ans += cnt[key];
            }
        }

        Console.WriteLine(ans);
    }


    public class Reader
    {
        private static StringReader sr;
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


8
2 7 1 8 2 8 1 8



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