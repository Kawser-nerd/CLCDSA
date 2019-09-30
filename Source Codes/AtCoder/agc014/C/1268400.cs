using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

class Program
{
    public void Proc()
    {
        Reader.IsDebug = false;
        int[] inpt = Reader.ReadLine().Split(' ').Select(a => int.Parse(a)).ToArray();
        int h = inpt[0];
        int w = inpt[1];
        this.MoveRange = inpt[2];

        this.Map = new char[h, w];

        int startR = 0;
        int startC = 0;

        for (int i = 0; i < h; i++)
        {
            string tmp = Reader.ReadLine();
            for (int j = 0; j < w; j++)
            {
                this.Map[i, j] = tmp[j];
                if (tmp[j] == 'S')
                {
                    startR = i;
                    startC = j;
                }
            }
        }

        Queue<int[]> que = new Queue<int[]>();
        Nullable<int>[,] cnt = new Nullable<int>[h, w];
        que.Enqueue(new int[] { startR, startC });
        cnt[startR, startC] = 0;
        while (que.Count > 0)
        {
            int[] pos = que.Dequeue();
            int curR = pos[0];
            int curC = pos[1];

            if (curR <= 0 || curR >= h - 1 || curC <= 0 || curC >= w - 1)
            {
                continue;
            }

            int nextStep = cnt[curR, curC].Value + 1;
            if (nextStep > MoveRange)
            {
                continue;
            }

            if (curR > 0 && Map[curR - 1, curC] != '#')
            {
                if (cnt[curR - 1, curC] == null || cnt[curR - 1, curC].Value > nextStep)
                {
                    cnt[curR - 1, curC] = nextStep;
                    que.Enqueue(new int[] { curR - 1, curC });
                }
            }
            if (curR < h-1 && Map[curR + 1, curC] != '#')
            {
                if (cnt[curR + 1, curC] == null || cnt[curR + 1, curC].Value > nextStep)
                {
                    cnt[curR + 1, curC] = nextStep;
                    que.Enqueue(new int[] { curR + 1, curC });
                }
            }
            if (curC > 0 && Map[curR, curC-1] != '#')
            {
                if (cnt[curR, curC-1] == null || cnt[curR, curC-1].Value > nextStep)
                {
                    cnt[curR, curC-1] = nextStep;
                    que.Enqueue(new int[] { curR, curC - 1 });
                }
            }
            if (curC < w - 1 && Map[curR, curC+1] != '#')
            {
                if (cnt[curR, curC + 1] == null || cnt[curR, curC + 1].Value > nextStep)
                {
                    cnt[curR, curC + 1] = nextStep;
                    que.Enqueue(new int[] { curR, curC + 1 });
                }
            }

        }

        int remainRange = Math.Max(h, w);
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (cnt[i, j] == null)
                {
                    continue;
                }
                remainRange = Math.Min(remainRange, i);
                remainRange = Math.Min(remainRange, h - 1 - i);
                remainRange = Math.Min(remainRange, j);
                remainRange = Math.Min(remainRange, w - 1 - j);
            }
        }
        int ans = remainRange / MoveRange;
        if (remainRange % MoveRange > 0)
        {
            ans++;
        }
        ans++;
        Console.WriteLine(ans);
    
    }

    private int MoveRange = 0;

    private char[,] Map;




    public class Reader
    {
        public static bool IsDebug = true;
        private static String PlainInput = @"

7 7 2
#######
#######
##...##
###S###
##.#.##
###.###
#######



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