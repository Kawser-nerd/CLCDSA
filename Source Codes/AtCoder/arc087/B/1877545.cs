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
        int[] goalPos = Reader.ReadLine().Split(' ').Select(a => int.Parse(a)).ToArray();


        int xMoveRemain = 0;
        int yMoveRemain = 0;

        string[] tmp = inpt.Split('T');
        List<int> xMoveList = new List<int>();
        List<int> yMoveList = new List<int>();
        for (int i = 0; i < tmp.Length; i++) {
            if(i%2==0) {
                xMoveRemain += tmp[i].Length;
                xMoveList.Add(tmp[i].Length);
            } else {
                yMoveRemain += tmp[i].Length;
                yMoveList.Add(tmp[i].Length);
            }
        }

        bool xReach = CanReach(1, xMoveList[0], goalPos[0], xMoveList);
        dic = new Dictionary<int, Dictionary<int, bool>>();
        bool yReach = CanReach(0, 0, goalPos[1], yMoveList);
        Console.WriteLine((xReach&&yReach)?"Yes":"No");
    }

    private Dictionary<int, Dictionary<int, bool>> dic = new Dictionary<int, Dictionary<int, bool>>();
    private bool CanReach(int idx, int pos, int goal, List<int> mv) {
        if(idx>=mv.Count) {
            if(pos == goal) {
                return true;
            }
            return false;
        }
        if(!dic.ContainsKey(idx)) {
            dic.Add(idx, new Dictionary<int, bool>());
        }
        if(dic[idx].ContainsKey(pos)) {
            return dic[idx][pos];
        }
        bool ans = false;
        ans = ans || CanReach(idx + 1, pos + mv[idx], goal, mv);
        ans = ans || CanReach(idx + 1, pos - mv[idx], goal, mv);
        dic[idx][pos] = ans;
        return ans;
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


TTTT
1 0


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