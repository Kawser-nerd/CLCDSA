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
        long[] items = Reader.ReadLine().Split(' ').Select(a => long.Parse(a)).OrderBy(a => a).ToArray();

        long num1 = items.Last();
        long num2 = items[GetAns(0, itemCount - 2, items)];

        Console.WriteLine(num1 + " " + num2);
         
    }

    private int GetAns(int min, int max, long[] arr) {
        if(max-min<=2) {
            int mid = (max + min) / 2;
            decimal diff1 = Math.Abs(arr.Last() / 2m - arr[min]);
            decimal diff2 = Math.Abs(arr.Last() / 2m - arr[mid]);
            decimal diff3 = Math.Abs(arr.Last() / 2m - arr[max]);

            decimal diffTemp = Math.Min(diff1, Math.Min(diff2, diff3));
            if(diffTemp == diff1) {
                return min;
            } else if(diffTemp == diff2) {
                return mid;
            } else {
                return max;
            }
        }

        int mid1 = min + (max - min) / 3;
        int mid2 = min + (max - min) * 2 / 3;

        decimal diffMin = Math.Abs(arr.Last() / 2m - arr[min]);
        decimal diffMid1 = Math.Abs(arr.Last() / 2m - arr[mid1]);
        decimal diffMid2 = Math.Abs(arr.Last() / 2m - arr[mid2]);
        decimal diffMax = Math.Abs(arr.Last() / 2m - arr[max]);

        decimal target = new decimal[] { diffMin, diffMid1, diffMid2, diffMax }.Min();

        if(target == diffMin) {
            return GetAns(min, mid1, arr);
        } else if(target == diffMid1) {
            return GetAns(min, mid2, arr);
        } else if(target == diffMid2) {
            return GetAns(mid1, max, arr);
        } else {
            return GetAns(mid2, max, arr);
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


5
6 9 4 2 11



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