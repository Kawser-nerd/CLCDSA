using System;
using System.Linq;
using System.Text;
using System.Collections.Generic;

public class Program
{
    public void Proc() {
        Reader.IsDebug = false;
        int[] inpt = Reader.ReadLine().Split(' ').Select(a=>int.Parse(a)).ToArray();
        int cnt = inpt[1];

        long[] list = Reader.ReadLine().Split(' ').Select(a=>long.Parse(a)).ToArray();

        long totalMinus = 0;
        long totalPlus = 0;

        long totalMinusMin = 0;
        long totalPlusMin = 0;

        long totalAll = 0;

        for(int i=0; i<list.Length; i++) {
            if(list[i]>0) {
                totalPlus+=list[i];
                totalAll+=list[i];
            }
            if(list[i]<0) {
                totalMinus+=list[i];
            }
            if(i>=cnt) {
                if(list[i-cnt]>0) {
                    totalPlus-=list[i-cnt];
                }
                if(list[i-cnt]<0) {
                    totalMinus-=list[i-cnt];
                }
            }
            if(i==cnt-1) {
                totalMinusMin = totalMinus;
                totalPlusMin = totalPlus;
            }
            if(i>=cnt-1) {
                if(Math.Abs(totalMinusMin) > Math.Abs(totalMinus)) {
                    totalMinusMin = totalMinus;
                }
                if(totalPlusMin > totalPlus) {
                    totalPlusMin = totalPlus;
                }
            }
        }
        totalAll = Math.Max(totalAll + totalMinusMin, totalAll - totalPlusMin);
        Console.WriteLine(totalAll);
    }

    public class Reader {
        public static bool IsDebug = true;
        private static System.IO.StringReader SReader;
        private static string InitText = @"


10 5
5 -4 -5 -8 -4 7 2 -4 0 7




";
        public static string ReadLine() {
            if(IsDebug) {
                if(SReader == null) {
                    SReader = new System.IO.StringReader(InitText.Trim());
                }
                return SReader.ReadLine();
            } else {
                return Console.ReadLine();
            }
        }

    }
    public static void Main(string[] args)
    {
        Program prg = new Program();
        prg.Proc();
    }
}