using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Text;

public class Program
{

    public void Proc()
    {
        for (int i = 0; i < 10; i++) {
            string inpt = Reader.ReadLine();
            for (int j = 0; j < inpt.Length; j++) {
                this.Map[i, j] = inpt[j] == 'o' ? 0 : -1;
            }
        }

        bool hasShima = true;
        while(hasShima) {
            hasShima = false;
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    if(Map[i, j] == 0) {
                        hasShima = true;
                        GroupCount++;
                        RewriteGroup(i, j, GroupCount, 0);
                    }
                }
            }
        }

        string ans = "NO";
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if(Map[i, j] < 0) {
                    if(JoinGroup(i, j)) {
                        ans = "YES";
                        break;
                    }
                }
            }
            if(ans.Equals("YES")) {
                break;
            }
        }

        Console.WriteLine(ans);
    }


    private bool JoinGroup(int row, int col) {
        List<int> rinsetu = new List<int>();
        for (int i = Math.Max(row - 1, 0); i <= Math.Min(row + 1, 9); i++) {
            for (int j = Math.Max(col - 1, 0); j <= Math.Min(col + 1, 9); j++) {
                if(i!=row && j!=col) {
                    continue;
                }
                if(Map[i, j]<=0) {
                    continue;
                }
                if(!rinsetu.Contains(Map[i, j])) {
                    rinsetu.Add(Map[i, j]);
                }
            }
        }
        rinsetu.Sort();
        if(rinsetu.Count == GroupCount) {
            return true;
        }
        return false;
    }


    private int[,] Map = new int[10, 10];

    private int GroupCount = 0;
    private void RewriteGroup(int row, int col, int grpIdx, int srcGroup)
    {
        Map[row, col] = grpIdx;
        for (int i = Math.Max(0, row - 1); i <= Math.Min(row + 1, 9); i++)
        {
            for (int j = Math.Max(0, col - 1); j <= Math.Min(col + 1, 9); j++)
            {
                if (i != row && col != j)
                {
                    continue;
                }
                if (Map[i, j] != srcGroup)
                {
                    continue;
                }
                RewriteGroup(i, j, grpIdx, srcGroup);
            }
        }
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




xxxxxxxxxx
xoooooooxx
xxoooooxxx
xxxoooxxxx
xxxxoxxxxx
xxxxxxxxxx
xxxxoxxxxx
xxxoooxxxx
xxoooooxxx
xxxxxxxxxx



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