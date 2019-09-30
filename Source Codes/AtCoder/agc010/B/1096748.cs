using System;
using System.Linq;
using System.Collections.Generic;
using System.Text.RegularExpressions;
using System.Text;
 
public class Program
{
    public void Proc() {
        Reader.IsDebug = false;
        long inputCount = int.Parse(Reader.ReadLine());
        this.Items = Reader.GetLongs();
        long sum = this.Items.Sum();
        long num = inputCount*(inputCount+1)/2;
 
        if(sum%num!=0) {
            Console.WriteLine("NO");
            return;
        }

        bool ans = true;
        for(int i=1; i<Items.Length; i++) {
            if(!IsCorrect(Items[i-1], Items[i], (int)(sum/num))) {
                ans = false;
                break;
            }
        }

        Console.WriteLine(ans?"YES":"NO");
    }

    private long[] Items;
 
    private bool IsCorrect(long num1, long num2, int remain) {
        if(remain == 0) {
            return (num1 ==0 && num2 == 0);
        }
        if(num1+remain == num2) {
            return true;
        }
        if(num1+remain > num2) {
            int cnt = this.Adjust(0, remain, num1, num2, remain);
            if(cnt < 0) {
                return false;
            }
            return IsCorrect(num1-(this.Items.Length*cnt), num2-cnt, remain-cnt);
        }
        return false;
    }

    private int Adjust (int min, int max, long num1, long num2, int remain) {
        if(max-min <= 1) {
            if(CanAdjust(min, num1, num2, remain)==0) {
                return min;
            } else if(CanAdjust(max, num1, num2, remain)==0) {
                return max;
            }
            return -1;
        }
        int mid = (max+min)/2;
        long ret = CanAdjust(mid, num1, num2, remain);
        if(ret == 0) {
            return mid;
        }
        if(ret > 0) {
            return Adjust(mid, max, num1, num2, remain);
        } else{
            return Adjust(min, mid, num1, num2, remain);
        }
    }

    private long CanAdjust(int count, long num1, long num2, int remain) {
        long tmp1 = num1 - (count*this.Items.Length);
        long tmp2 = num2 - (count);
        if(tmp1 < 0 || tmp2 < 0) {
            return -1;
        }
        return (tmp1 + (remain-count))-tmp2;
    }
 
    public class Reader {
        public static bool IsDebug = true;
 
        public static long[] GetLongs(char delimiter) {
            string inpt = Reader.ReadLine();
            return inpt.Split(delimiter).Select(a=>long.Parse(a)).ToArray();
        }
 
        public static long[] GetLongs() {
            return GetLongs(' ');
        }
        private static System.IO.StringReader SReader;
        private static string InitText = @"


4
1 2 3 1

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