using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Text;

public class Program
{

    public void Proc()
    {
        string inpt = Reader.ReadLine();
        List<int> numlist = new List<int>();
        int pos = 0; 
        for (int i = 1; i < inpt.Length; i++) {
            if(inpt[i-1] != inpt[i]) {
                numlist.Add(i - 1 - pos + 1);
                pos = i;
            }
        }
        numlist.Add(inpt.Length-pos);
        int ans = GetAns(numlist, numlist.OrderBy(a => a).ToList(), inpt.Length);
        if(ans < 0) {
            ans = GetAns2(numlist, inpt.Length);
        }
        Console.WriteLine(ans);
    }

    private int GetAns2(List<int> inpt, int total) {
        int min = inpt.Min();
        int max = inpt.Max();
        int ans = total/2;
        if(total%2>0) {
            ans++;
        }
        int cnt = inpt.First();
        for (int i = 1; i < inpt.Count-1; i++) {
            if(cnt>=ans) {
                ans = total - cnt;
                break;
            } else if(cnt+inpt[i]>=ans) {
                ans = Math.Min(cnt + inpt[i], total - cnt);
                break;
            }
            cnt += inpt[i];
        }
        return ans;

    }
    private int GetAns(List<int> inpt, List<int> ord, int total) {
        if(inpt.Count == 1) {
            return inpt[0];
        }
        if(inpt.Count == 2) {
            return ord.Last();
        }
        return -1;
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




101



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