//#define TEST
using System;
using System.Collections.Generic;
using System.Linq;
class P{
    private static int[] ps = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97}; //??25
    static void Main(){
        int[] pc = new int[25];
        int n = int.Parse(Console.ReadLine()); //???????
        for (int i = 2;i <= n;i++){ //n!??????
            foreach (var p in ps){
                int ic = i;
                while (ic % p == 0){
                    ic /= p;
                    pc[invP(p)]++;
                }
            }
        }
#if TEST
        foreach (var i in pc)
            Console.WriteLine(i);
#endif
        //3,5,15,25,75?????????
        var q5 = from x in pc
                where x + 1 >= 5
                select x;
        int c5 = q5.Count();
        var q3 = from x in pc
                where x + 1 >= 3
                select x;
        int c3 = q3.Count();
        var q15 = from x in pc
                where x + 1 >= 15
                select x;
        int c15 = q15.Count();
        var q25 = from x in pc
                where x + 1 >= 25
                select x;
        int c25 = q25.Count();
        var q75 = from x in pc
                where x + 1 >= 75
                select x;
        int c75 = q75.Count();
        //?????
        int ans = 0;
        { //5 * 5 * 3
            if (c5 > 1)
                ans += (c5 * (c5 - 1) / 2) * (c3 - 2);
        }
        { // 5 * 15
            ans += c15 * (c5 - 1);
        }
        { // 3 * 25
            ans += c25 * (c3 - 1);
        }
        { //75
            ans += c75;
        }
        Console.WriteLine(ans);
    }
    static int invP(int p){
        for (int i = 0;i < 25;i++)
            if (ps[i] == p)
                return i;
        return -1;
    }
}