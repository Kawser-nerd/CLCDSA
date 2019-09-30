using System;
using System.Linq;
using System.Diagnostics;
using System.Collections.Generic;
using static System.Math;

class P
{
    static void Main()
    {
        //???????????????1????
        //???n ?????????1 ?????<=30000
        //n <= 20000
        //0 2 3 4 (mod 6)
        //Sum = 9 : 3????
        //     2 3 4 6 8 9 10 12....
        //mod2 0 1 0 0 0 1  0  0
        //mod3 2 0 1 0 2 0  1  0
        //mod6 2 3 4 0 2 3  4  0
        //---------sum----------
        //mod2 0 1 1 1 1 0  0  0 
        //mod3 2 2 0 0 2 2  0  0
        //---------add----------
        //mod6 4 1 3 3 1 4  0  0
        //-----difffromlast------
        //

        //????????????????????

        //???
        /*for (int i = 3; i <= 20000; i++)
        {
            List<int> r = solve(i);
            int rsum = r.Sum();
            if (r.Count != i)
            {
                Console.WriteLine($"Ultra Yabai {i}");
            }
            if (rsum % 6 != 0)
            {
                Console.WriteLine($"Very Yabai {i}");
            }
            if(r.All(x => x % 2 == 0) || r.All(x => x % 3 == 0))
            {
                Console.WriteLine($"Warito Yabai {i}");
            }
        }*/
        //???????
        int n = int.Parse(Console.ReadLine());
        List<int> res = solve(n);
        if (n == 3)
        {
            res = new List<int> { 2, 5, 63 };
        }
        Console.WriteLine(string.Join(" ", res));
    }
    static List<int> solve(int n)
    {
        int[] mod = { 2, 3, 4, 6 };
        List<int> res = new List<int>();
        for (int i = 0; i < n - 1; i++)
        {
            res.Add((i / 4) * 6 + mod[i % 4]);
        }
        int last = res.Last();
        switch (n % 8)
        {
            case 0:
                //10 -> 12
                res.Add(last + 2);
                break;
            case 1:
                //12 -> 6
                res.Add(last + 6);
                break;
            case 2:
                //2 -> 4 
                res.Add(last + 2);
                break;
            case 3:
                //?????????4,6
                //3 -> 4,6
                res.RemoveAt(res.Count - 1);
                res.Add(last + 1);
                res.Add(last + 3);
                break;
            case 4:
                //4 -> 9
                res.Add(last + 5);
                break;
            case 5:
                //6 -> 9
                res.Add(last + 3);
                break;
            case 6:
                //?????????9,12
                res.RemoveAt(res.Count - 1);
                //8 -> 9,12
                res.Add(last + 1);
                res.Add(last + 4);
                break;
            case 7:
                //9
                //9 -> 10
                res.Add(last + 1);
                break;
        }
        return res;
    }
}