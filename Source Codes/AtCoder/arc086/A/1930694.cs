using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Text;

public class Program
{

    public void Proc()
    {
        int[] inpt = Reader.ReadLine().Split(' ').Select(a => int.Parse(a)).ToArray();
        int ballCount = inpt[0];
        int kindMax = inpt[1];

        inpt = Reader.ReadLine().Split(' ').Select(a => int.Parse(a)).ToArray();

        Dictionary<int, int> cnt = new Dictionary<int, int>();
        inpt.ToList().ForEach(a=>{
            if(cnt.ContainsKey(a)) {
                cnt[a]++;
            } else {
                cnt.Add(a, 1);
            }
        });
        List<KeyValuePair<int, int>> list = cnt.OrderBy(a => a.Value).ToList();
        int ans = 0;
        for (int i = 0; i < list.Count - kindMax; i++) {
            ans += list[i].Value;
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




5 2
1 1 2 2 5




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