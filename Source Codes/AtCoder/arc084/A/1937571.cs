using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Text;

public class Program
{

    public void Proc()
    {
        int itemCount = int.Parse(Reader.ReadLine());

        this.PartsTop = Reader.ReadLine().Split(' ').Select(a => long.Parse(a)).OrderBy(a=>a).ToArray();
        this.PartsMiddle = Reader.ReadLine().Split(' ').Select(a => long.Parse(a)).OrderBy(a=>a).ToArray();
        this.PartsBottom = Reader.ReadLine().Split(' ').Select(a => long.Parse(a)).OrderBy(a=>a).ToArray();

        long ans = 0;
        for (int i = 0; i < PartsMiddle.Length; i++) {
            long topIdx = GetTopIdx(0, itemCount - 1, PartsMiddle[i]);
            long bottomIdx = GetBottomIdx(0, itemCount - 1, PartsMiddle[i]);
            long topCount = topIdx + 1;
            long bottomCount = itemCount - bottomIdx;
            ans += topCount * bottomCount;
        }
        Console.WriteLine(ans);
    }

    private long GetTopIdx(int min, int max, long val) {
        if(max-min<=1) {
            if(val > PartsTop[max]) {
                return max;
            } else if(val > PartsTop[min]) {
                return min;
            } else {
                return min - 1;
            }
        }
        int mid = (max + min) / 2;
        if(PartsTop[mid]<val) {
            return GetTopIdx(mid, max, val);
        } else {
            return GetTopIdx(min, mid, val);
        }

    }

    private long GetBottomIdx(int min, int max, long val) {
        if (max - min <= 1)
        {
            if(val >= PartsBottom[max]) {
                return max + 1;
            } else if(val >= PartsBottom[min]) {
                return max;
            } else {
                return min;
            }
        }
        int mid = (max + min) / 2;
        if(PartsBottom[mid]<=val) {
            return GetBottomIdx(mid, max, val);
        } else {
            return GetBottomIdx(min, mid, val);
        }
    }

    private long[] PartsTop;
    private long[] PartsMiddle;
    private long[] PartsBottom;

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



4
2 2 1 2
2 2 2 2
2 2 2 3


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