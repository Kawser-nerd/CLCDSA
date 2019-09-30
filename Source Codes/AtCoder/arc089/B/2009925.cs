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
        int kibouCount = inpt[0];
        CheckLen = inpt[1];
        this.KibouList = new Kibou[kibouCount];
        this.KibouMap = new int[CheckLen * 2, CheckLen * 2];
        this.KibouCountMap = new int[CheckLen * 2, CheckLen * 2];
        for (int i = 0; i < kibouCount; i++) {
            Kibou newKibou = new Kibou(Reader.ReadLine());
            this.KibouList[i] = newKibou;
            this.KibouMap[newKibou.X, newKibou.Y]++;
        }
        for (int i = 0; i < KibouMap.GetLength(0); i++) {
            for (int j = 0; j < KibouMap.GetLength(0); j++) {
                int num = this.KibouMap[i, j];
                if(i>0) {
                    num += this.KibouCountMap[i - 1, j];
                }
                if(j>0) {
                    num += this.KibouCountMap[i, j - 1];
                }
                if(i>0&&j>0) {
                    num -= this.KibouCountMap[i - 1, j - 1];
                }
                this.KibouCountMap[i, j] = num;
            }
        }
        int ans = 0;
        int maxIndex = KibouCountMap.GetLength(0) - 1;
        for (int i = 0; i <=maxIndex; i++) {
            for (int j = 0; j <= maxIndex; j++) {
                int subAns = GetBlockCount(i, j);
                int subX = i + CheckLen;
                int subY = j + CheckLen;
                if(subX>maxIndex) {
                    subX -= this.KibouCountMap.GetLength(0);
                }
                if(subY>maxIndex) {
                    subY -= this.KibouCountMap.GetLength(0);
                }
                subAns += GetBlockCount(subX, subY);
                ans = Math.Max(subAns, ans);
            }
        }
        Console.WriteLine(ans);
    }

    private int GetBlockCount(int x, int y) {
        int maxIndex = KibouCountMap.GetLength(0) - 1;
        int toX = x + CheckLen - 1;
        int toY = y + CheckLen - 1;
        int tmp = GetItemCount(x, y, Math.Min(toX, maxIndex), Math.Min(toY, maxIndex));
        if (toX > maxIndex)
        {
            int subToX = toX - maxIndex - 1;
            int subToY = Math.Min(toY, maxIndex);
            tmp += GetItemCount(0, y, subToX, subToY);
        }
        if (toY > maxIndex)
        {
            tmp += GetItemCount(x, 0, Math.Min(toX, maxIndex), toY - maxIndex-1);
        }
        if (toX > maxIndex && toY > maxIndex)
        {
            tmp += GetItemCount(0, 0, toX - maxIndex-1, toY - maxIndex-1);
        }
        return tmp;
    }

    private int GetItemCount(int fromX, int fromY, int toX, int toY) {
        int ans = KibouCountMap[toX, toY];
        if(fromX>0) {
            ans -= KibouCountMap[fromX - 1, toY];
        }
        if(fromY>0) {
            ans -= KibouCountMap[toX, fromY - 1];
        }
        if(fromX>0&&fromY>0) {
            ans += KibouCountMap[fromX - 1, fromY - 1];
        }
        return ans;
    }


    private int[,] KibouMap;
    private int[,] KibouCountMap;
    private Kibou[] KibouList;
    private class Kibou {
        public long X;
        public long Y;
        public Kibou(string inpt) {
            string[] tmp = inpt.Split(' ');
            this.X = long.Parse(tmp[0]);
            this.Y = long.Parse(tmp[1]);
            if(tmp[2][0]=='W') {
                this.X += CheckLen;
            }
            this.X = this.X % (CheckLen * 2);
            this.Y = this.Y % (CheckLen * 2);
            if (this.X >= CheckLen && this.Y >= CheckLen) {
                this.X -= CheckLen;
                this.Y -= CheckLen;
            }
        }
    }

    public static int CheckLen;


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





6 2
1 2 B
2 1 W
2 2 B
1 0 B
0 6 W
4 5 W


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