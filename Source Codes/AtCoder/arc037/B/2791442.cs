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
        this.Group = new int[inpt[0]];

        int roadCount = inpt[1];

        for (int i = 0; i < roadCount; i++) {
            inpt = Reader.ReadLine().Split(' ').Select(a => int.Parse(a) - 1).ToArray();

            if(!Road.ContainsKey(inpt[0])) {
                this.Road.Add(inpt[0], new Dictionary<int, bool>());
            }
            Road[inpt[0]][inpt[1]] = true;

            if (!Road.ContainsKey(inpt[1]))
            {
                this.Road.Add(inpt[1], new Dictionary<int, bool>());
            }
            Road[inpt[1]][inpt[0]] = true;
        }

        int ans = 0;
        for (int i = 0; i < Group.Length; i++) {
            if(Group[i] != 0) {
                continue;
            }
            if(CanSet(-1, i, i+1)) {
                ans++;
            }    
        }
        Console.WriteLine(ans);
    }

    private bool CanSet(int prev, int target, int groupIdx) {
        if(Group[target] != 0) {
            return false;
        }

        Group[target] = groupIdx;
        if(!Road.ContainsKey(target)) {
            return true;
        }

        bool ans = true;
        foreach(int next in Road[target].Keys) {
            if(next == prev) {
                continue;
            }
            if(!CanSet(target, next, groupIdx)) {
                ans = false;
            }
        }
        return ans;
    }

    private Dictionary<int, Dictionary<int, bool>> Road = new Dictionary<int, Dictionary<int, bool>>();

    private int[] Group;

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


11 11
1 2
1 3
2 4
3 5
4 6
5 7
6 8
7 9
8 10
9 11
10 11

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