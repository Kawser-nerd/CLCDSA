//#define TEST
using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;
using System.Diagnostics;
class p{
    static void Main(){
        int[] nx = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int n = nx[0], x = nx[1];
        long[] a = Console.ReadLine().Split().Select(long.Parse).ToArray();
        Array.Sort(a);
#if TEST
        foreach (var i in a) Console.Write("{0} ",i);
        Console.WriteLine();
#endif
        int ans = 0;
        int sum = 0;
        for (int i = 0;;i++){
            try{
                sum += (int)a[i];
                if (sum > x){
                    ans = i;
                    break;
                }
            }
            catch{
                ans = n;
                break;
            }
        }
        if (a.Sum() < x) ans = n - 1;
        Console.WriteLine(ans);
    }
}