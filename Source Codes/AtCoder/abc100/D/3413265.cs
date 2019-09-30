using System;
using System.Linq;
using System.Collections.Generic;
using static System.Console;
using static System.Math;
 
public class Hello{
    public static void Main(){
        string[] input = ReadLine().Split(' ');
        int n = int.Parse(input[0]);
        int m = int.Parse(input[1]);

        long[] ppp = new long[n];
        long[] ppm = new long[n];
        long[] pmp = new long[n];
        long[] pmm = new long[n];
        long[] mpp = new long[n];
        long[] mpm = new long[n];
        long[] mmp = new long[n];
        long[] mmm = new long[n];
        
        for(int i=0;i<n;i++){
            string[] temp = ReadLine().Split(' ');
            long a = long.Parse(temp[0]);
            long b = long.Parse(temp[1]);
            long c = long.Parse(temp[2]);
            ppp[i] = a+b+c;
            ppm[i] = a+b-c;
            pmp[i] = a-b+c;
            pmm[i] = a-b-c;
            mpp[i] = -a+b+c;
            mpm[i] = -a+b-c;
            mmp[i] = -a-b+c;
            mmm[i] = -a-b-c;
        }
        Array.Sort(ppp);
        Array.Sort(ppm);
        Array.Sort(pmp);
        Array.Sort(pmm);
        Array.Sort(mpp);
        Array.Sort(mpm);
        Array.Sort(mmp);
        Array.Sort(mmm);
        long tppp = 0;
        long tppm = 0;
        long tpmp = 0;
        long tpmm = 0;
        long tmpp = 0;
        long tmpm = 0;
        long tmmp = 0;
        long tmmm = 0;
        for(int i=n-1;i>=n-m;i--){
            tppp+=ppp[i];
            tppm+=ppm[i];
            tpmp+=pmp[i];
            tpmm+=pmm[i];
            tmpp+=mpp[i];
            tmpm+=mpm[i];
            tmmp+=mmp[i];
            tmmm+=mmm[i];
        }
        long max = tppp;
        max = Max(max,tppm);
        max = Max(max,tpmp);
        max = Max(max,tpmm);
        max = Max(max,tmpp);
        max = Max(max,tmpm);
        max = Max(max,tmmp);
        max = Max(max,tmmm);
        
        WriteLine(max);

    }
}