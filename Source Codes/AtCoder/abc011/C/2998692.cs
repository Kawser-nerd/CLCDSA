//using System;
//using System.Collections.Generic;
//using System.Linq;
//using System.Text;
//using System.Threading.Tasks;


//class Program
//{
//    static void Main(string[] args)
//    {
//        //double m = int.Parse(Console.ReadLine());
//        //double dbm = m / 1000;

//        //if (dbm < 0.1)
//        //{
//        //    Console.WriteLine("00");
//        //}
//        //else if (0.1 <= dbm && dbm <= 5)
//        //{
//        //    Console.WriteLine((dbm * 10).ToString("00"));
//        //}
//        //else if (6 <= dbm && dbm <= 30)
//        //{
//        //    Console.WriteLine(dbm + 50);
//        //}
//        //else if (35 <= dbm && dbm <= 70)
//        //{
//        //    Console.WriteLine(((dbm - 30) / 5) + 80);
//        //}
//        //else
//        //{
//        //    Console.WriteLine(89);
//        //}
//        //var line = Array.ConvertAll(Console.ReadLine().Split(' '),double.Parse);
//        //double dir = line[0] / 10;
//        //double w = Math.Round(line[1]/60,1, MidpointRounding.AwayFromZero);

//        //string d;
//        //int ww = 0;

//        //if (11.25 + (22.5*0) <= dir && dir < 11.25 + (22.5 * 1))
//        //{
//        //    d = "NNE";
//        //}
//        //else if (11.25 + (22.5 * 1) <= dir && dir < 11.25 + (22.5 * 2))
//        //{
//        //    d = "NE";
//        //}
//        //else if (11.25 + (22.5 * 2) <= dir && dir < 11.25 + (22.5 * 3))
//        //{
//        //    d = "ENE";
//        //}
//        //else if (11.25 + (22.5 * 3) <= dir && dir < 11.25 + (22.5 * 4))
//        //{
//        //    d = "E";
//        //}
//        //else if (11.25 + (22.5 * 4) <= dir && dir < 11.25 + (22.5 * 5))
//        //{
//        //    d = "ESE";
//        //}
//        //else if (11.25 + (22.5 * 5) <= dir && dir < 11.25 + (22.5 * 6))
//        //{
//        //    d = "SE";
//        //}
//        //else if (11.25 + (22.5 * 6) <= dir && dir < 11.25 + (22.5 * 7))
//        //{
//        //    d = "SSE";
//        //}
//        //else if (11.25 + (22.5 * 7) <= dir && dir < 11.25 + (22.5 * 8))
//        //{
//        //    d = "S";
//        //}
//        //else if (11.25 + (22.5 * 8) <= dir && dir < 11.25 + (22.5 * 9))
//        //{
//        //    d = "SSW";
//        //}
//        //else if (11.25 + (22.5 * 9) <= dir && dir < 11.25 + (22.5 * 10))
//        //{
//        //    d = "SW";
//        //}
//        //else if (11.25 + (22.5 * 10) <= dir && dir < 11.25 + (22.5 * 11))
//        //{
//        //    d = "WSW";
//        //}
//        //else if (11.25 + (22.5 * 11) <= dir && dir < 11.25 + (22.5 * 12))
//        //{
//        //    d = "W";
//        //}
//        //else if (11.25 + (22.5 * 12) <= dir && dir < 11.25 + (22.5 * 13))
//        //{
//        //    d = "WNW";
//        //}
//        //else if (11.25 + (22.5 * 13) <= dir && dir < 11.25 + (22.5 * 14))
//        //{
//        //    d = "NW";
//        //}
//        //else if (11.25 + (22.5 * 14) <= dir && dir < 11.25 + (22.5 * 15))
//        //{
//        //    d = "NNW";
//        //}
//        //else
//        //{
//        //    d = "N";
//        //}

//        //if (0 <= w && w <= 0.2)
//        //{
//        //    d = "C";
//        //    ww = 0;
//        //}
//        //else if (0.3 <= w && w <= 1.5)
//        //{
//        //    ww = 1;
//        //}
//        //else if (1.6 <= w && w <= 3.3)
//        //{
//        //    ww = 2;
//        //}
//        //else if (3.4 <= w && w <= 5.4)
//        //{
//        //    ww = 3;
//        //}
//        //else if (5.5 <= w && w <= 7.9)
//        //{
//        //    ww = 4;
//        //}
//        //else if (8.0 <= w && w <= 10.7)
//        //{
//        //    ww = 5;
//        //}
//        //else if (10.8 <= w && w <= 13.8)
//        //{
//        //    ww = 6;
//        //}
//        //else if (13.9 <= w && w <= 17.1)
//        //{
//        //    ww = 7;
//        //}
//        //else if (17.2 <= w && w <= 20.7)
//        //{
//        //    ww = 8;
//        //}
//        //else if (20.8 <= w && w <= 24.4)
//        //{
//        //    ww = 9;
//        //}
//        //else if (24.5 <= w && w <= 28.4)
//        //{
//        //    ww = 10;
//        //}
//        //else if (28.5 <= w && w <= 32.6)
//        //{
//        //    ww = 11;
//        //}
//        //else if (32.7 <= w)
//        //{
//        //    ww = 12;
//        //}
//        //Console.WriteLine(d + " " + ww.ToString());
//        //    var mozi = Console.ReadLine().ToCharArray();
//        //    string outstr = "";

//        //    for (int i = 0; i <= mozi.Length -1; i++)
//        //    {
//        //        if (mozi[i] == 'a')
//        //        {
//        //            mozi[i] = '@';
//        //        }
//        //        else if (mozi[i] == 'i')
//        //        {
//        //            mozi[i] = '@';
//        //        }
//        //        else if (mozi[i] == 'u')
//        //        {
//        //            mozi[i] = '@';
//        //        }
//        //        else if (mozi[i] == 'e')
//        //        {
//        //            mozi[i] = '@';
//        //        }
//        //        else if (mozi[i] == 'o')
//        //        {
//        //            mozi[i] = '@';
//        //        }
//        //        else
//        //        {
//        //            outstr = outstr + mozi[i].ToString();
//        //        }
//        //    }

//        //Console.WriteLine(outstr);

//        //var line = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
//        //double area = 0;

//        //double x1 = line[0];
//        //double x2 = line[2];
//        //double x3 = line[4];

//        //double y1 = line[1];
//        //double y2 = line[3];
//        //double y3 = line[5];

//        //x2 = x2 - x1;
//        //y2 = y2 - y1;

//        //x3 = x3 - x1;
//        //y3 = y3 - y1;

//        //area = Math.Abs(x2 * y3 - x3 * y2)/2;
//        //Console.WriteLine(area);
//    }
//}

using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

class Program
{

    static List<int[]> list = new List<int[]>();
    static int ArrayCnt;
    static void Main(string[] args)
    {
        #region 20180721
        //    //var line = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);

        //    //int N = line[0];
        //    //int[] pre = new int[]{ 1,2,3,4,5,6};
        //    ////int K = line[1];


        //    ////double[] db = new double[] { };
        //    ////db = Array.ConvertAll(Console.ReadLine().Split(), double.Parse);
        //    ////Array.Sort(db);

        //    ////double cur = 0;
        //    ////double tmp = 0;

        //    ////for (int i = N-K; i < N; i++)
        //    ////{
        //    ////    cur = (db[i] + cur) / 2;
        //    ////}
        //    ////Console.WriteLine(cur);

        //    //if (true)
        //    //{
        //    //    N = N % 30;
        //    //}

        //    //int index1 = 0;
        //    //int index2 = 0;
        //    //int tmp = 0;


        //    //for (int i = 0; i < N; i++)
        //    //{
        //    //    index1 = (i % 5);
        //    //    index2 = (i % 5) + 1;

        //    //    tmp = pre[index1];
        //    //    pre[index1] = pre[index2];
        //    //    pre[index2] = tmp;
        //    //}

        //    //for (int i = 0; i < 6; i++)
        //    //{
        //    //    if (i != 5)
        //    //    {
        //    //        Console.Write(pre[i]);
        //    //    }
        //    //    else
        //    //    {
        //    //        Console.WriteLine(pre[i]);
        //    //    }

        //    //}

        //    //int time = int.Parse(Console.ReadLine());
        //    //int digit = int.Parse(Console.ReadLine());
        //    //var dline = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
        //    //int customer = int.Parse(Console.ReadLine());
        //    //var cline = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);

        //    //int tmp = 0;
        //    //int cnt = 0;

        //    //for (int i = 0; i < customer; i++)
        //    //{
        //    //    for (int j = tmp; j < digit; j++)
        //    //    {
        //    //         if (dline[j] <= cline[i] && Math.Abs(cline[i]- dline[j]) <= time )
        //    //        {
        //    //            tmp = j + 1;
        //    //            cnt++;
        //    //            break;
        //    //        }
        //    //    }
        //    //}
        //    //if (cnt == customer)
        //    //{
        //    //    Console.WriteLine("yes");
        //    //}
        //    //else
        //    //{
        //    //    Console.WriteLine("no");
        //    //}

        //    var line = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
        //    int N = line[0];
        //    int M = line[1];
        //    //if (line[0] * 4 < line[1])
        //    //{
        //    //    Console.WriteLine("-1 -1 -1");
        //    //    return;
        //    //}
        //    //if (line[1]%4 == 0)
        //    //{
        //    //    Console.WriteLine("0 0 " + line[1] / 4);
        //    //}
        //    //else if (line[1] % 4 == 1)
        //    //{
        //    //    Console.WriteLine("1 1 " + (line[1] / 4 - 1));
        //    //}
        //    //else if (line[1] % 4 == 2)
        //    //{
        //    //    Console.WriteLine("1 0 " + line[1] / 4);
        //    //}
        //    //else
        //    //{
        //    //    Console.WriteLine("0 1 " + line[1] / 4);
        //    //}
        //    //int[,] dp = new int[N + 1,M + 1];

        //    //for (int i = 0; i <= N; i++)
        //    //{
        //    //    for (int j = 0; j <= M; j++)
        //    //    {
        //    //        dp[i, j] = 0;
        //    //    }
        //    //}

        //    //dp[1,2] = 1;
        //    //dp[1,3] = 1;
        //    //dp[1,4] = 1;

        //    //int cnt2 = 1;
        //    //int cnt3 = 1;
        //    //int cnt4 = 1;

        //    //for (int i = 1; i <= N; i++)
        //    //{
        //    //    for (int j = 2; j <= M; j++)
        //    //    {
        //    //        if (dp[i,j] == N)
        //    //        {
        //    //            break;
        //    //        }

        //    //        if (j -2 >=0 && dp[i-1,j-2] != 0)
        //    //        {
        //    //            dp[i, j] = dp[i - 1, j - 2] + 1;
        //    //        }

        //    //        else if (j - 3 >= 0 && dp[i - 1, j - 3] != 0)
        //    //        {
        //    //            dp[i, j] = dp[i - 1, j - 3] + 1;
        //    //        }
        //    //        else if (j - 4 >= 0 && dp[i - 1, j - 4] != 0)
        //    //        {
        //    //            dp[i, j] = dp[i - 1, j - 4] + 1;
        //    //        }
        //    //    }
        //    //}

        //    //if (dp[N,M] == N)
        //    //{
        //    //    Console.WriteLine(cnt2 + " " + cnt3 + "" + cnt4);
        //    //}
        //    //if (M > N * 4)
        //    //{
        //    //    Console.WriteLine("-1 -1 -1");
        //    //    return;
        //    //}


        //    for (int i = 0; i <= N; i++)
        //    {
        //        for (int j = 0; j <= N -i; j++)
        //        {
        //            if (i * 2 + j * 3 + (N - i -j) * 4 == M)
        //            {
        //                Console.WriteLine(i + " " + j + " " + (N - i - j));
        //                return;
        //            }
        //        }
        //    }

        //    Console.WriteLine("-1 -1 -1");
        #endregion

        #region 20180812

        //Queue<int[]> que = new Queue<int[]>();
        //int[] wd = new int[] { 1,-1,0,0};
        //int[] hd = new int[] { 0,0,1,-1};

        //var mazeFormat = Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
        //var s = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
        //var g = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
        //string[,] mazeData = new string[mazeFormat[0], mazeFormat[1]];
        //int[,] minkeiro = new int[mazeFormat[0], mazeFormat[1]];

        //for (int i = 0; i < mazeFormat[0]; i++)
        //{
        //    for (int j = 0; j < mazeFormat[1]; j++)
        //    {
        //        minkeiro[i, j] = 0;
        //    }
        //}

        //for (int i = 0; i < mazeFormat[0]; i++)
        //{
        //    var tmp = Console.ReadLine().ToCharArray();
        //    for (int j = 0; j < mazeFormat[1]; j++)
        //    {
        //        mazeData[i, j] = tmp[j].ToString();
        //    }
        //}

        //s[0] = s[0] - 1;
        //s[1] = s[1] - 1;

        //que.Enqueue(s);

        //while (que.Count > 0)
        //{
        //    var tmp = que.Dequeue();
        //    int curRow = tmp[0];
        //    int curCol = tmp[1];

        //    int nowmin = minkeiro[curRow, curCol];

        //    for (int i = 0; i < 4; i++)
        //    {
        //        if (mazeData[curRow + wd[i], curCol + hd[i]] == ".")
        //        {
        //            que.Enqueue(new int[] { curRow + wd[i], curCol + hd[i] });
        //            mazeData[curRow + wd[i], curCol + hd[i]] = "#";
        //            minkeiro[curRow + wd[i], curCol + hd[i]] = nowmin + 1;
        //        }
        //    }
        //}

        //Console.WriteLine(minkeiro[g[0]-1,g[1]-1]);

        //var cnt = int.Parse(Console.ReadLine());
        //int[] intArrayData = new int[cnt];
        //double omoteCnt = 0;
        //double expectation = 0;

        //for (int i = 0; i < cnt; i++)
        //{
        //    intArrayData[i] = int.Parse(Console.ReadLine());
        //}

        //for (int i = 0; i < intArrayData.Count(); i++)
        //{
        //    for (int j = 0; j < intArrayData.Count(); j++)
        //    {
        //        if (j != i && intArrayData[i]%intArrayData[j] == 0)
        //        {
        //            omoteCnt++;
        //        }

        //    }

        //    if (omoteCnt % 2 == 0)
        //    {
        //        expectation = expectation + (omoteCnt + 2) / (omoteCnt * 2 + 2);
        //    }
        //    else
        //    {
        //        expectation = expectation + 0.5;
        //    }

        //    omoteCnt = 0;
        //}

        //var zyunretsu = AllPermutation(intArrayData);
        //double sousuu = zyunretsu.Count();
        //double omote = 0;

        //foreach (var items in zyunretsu)
        //{
        //    bool[] omoteuraKBN = new bool[cnt];
        //    for (int i = 0; i < items.Count - 1; i++)
        //    {
        //        for (int j = i + 1; j < items.Count; j++)
        //        {
        //            if (items[j]%items[i] == 0)
        //            {
        //                omoteuraKBN[j] = omoteuraKBN[j] == false ? true : false;  
        //            }
        //        }
        //    }
        //    omote = omote + omoteuraKBN.Where(n => n == false).Count();
        //}

        //Console.WriteLine(expectation);


        //var line = Array.ConvertAll(Console.ReadLine().Split(), double.Parse);
        //var N = int.Parse(Console.ReadLine());
        //double sokudo = line[4] * line[5];

        //for (int i = 0; i < N; i++)
        //{
        //    var house = Array.ConvertAll(Console.ReadLine().Split(), double.Parse);
        //    var goukei = Math.Sqrt(Math.Pow((house[0] -line[0]),2) + Math.Pow((house[1] - line[1]), 2)) 
        //               + Math.Sqrt(Math.Pow((line[2] - house[0]), 2) + Math.Pow((line[3] - house[1]), 2));

        //    if (goukei <= sokudo)
        //    {
        //        Console.WriteLine("YES");
        //        return;
        //    }
        //}

        //Console.WriteLine("NO");

        //var line = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
        //int N = line[0];
        //int M = line[1];

        //for (int i = 0; i < N; i++)
        //{
        //    if (M == (i * 2) + (N - i -1) * 4 + 3)
        //    {
        //        Console.WriteLine(i + " " + 1 + " " + (N - i - 1));
        //        return;
        //    }
        //}

        //for (int i = 0; i <= N; i++)
        //{
        //    if (M == (i * 2) + (N - i) * 4)
        //    {
        //        Console.WriteLine(i + " " + 0 + " " + (N - i));
        //        return;
        //    }
        //}

        //Console.WriteLine("-1 -1 -1");

        #endregion

        int N, NG1, NG2, NG3;

        N = int.Parse(Console.ReadLine());
        NG1 = int.Parse(Console.ReadLine());
        NG2 = int.Parse(Console.ReadLine());
        NG3 = int.Parse(Console.ReadLine());

        if (N == NG1 || N == NG2 || N == NG3)
        {
            Console.WriteLine("NO");
            return;
        }

        for (int i = 1; i <= 100; i++)
        {
            if (N - 3 == NG1 || N - 3 == NG2 || N - 3 == NG3 || N -3 < 0)
            {

            }
            else
            {
                N = N - 3;

                if (N == 0)
                {
                    Console.WriteLine("YES");
                    return;
                }
                continue;
            }

            if (N - 2 == NG1 || N - 2 == NG2 || N - 2 == NG3 || N - 2 < 0)
            {

            }
            else
            {
                N = N - 2;

                if (N == 0)
                {
                    Console.WriteLine("YES");
                    return;
                }
                continue;
            }

            if (N - 1 == NG1 || N - 1 == NG2 || N - 1 == NG3)
            {

            }
            else
            {
                N = N - 1;

                if (N == 0)
                {
                    Console.WriteLine("YES");
                    return;
                }
                continue;
            }

            Console.WriteLine("NO");
            return;

        }

        Console.WriteLine("NO");

    }
    public static List<int[]> zyunretu(List<int> argList)
    {
        if (argList.Count() == 1)
        {
            return new List<int[]> { argList.ToArray() };
        }

        for (int i = 0; i < argList.Count(); i++)
        {
            int[] leftSide = new int[] { argList[i] };
            argList.RemoveAt(i);

            foreach (var restitem in zyunretu(argList))
            {
                int[] forConcat = restitem;

                if (forConcat.Count() < ArrayCnt - 1)
                {
                    return new List<int[]> { leftSide.Concat(forConcat).ToArray() };
                }
                else
                {
                    list.Add(leftSide.Concat(forConcat).ToArray());
                }
            }
        }
        return list;
    }

    //public static IEnumerable<T[]> AllPermutation<T>(IEnumerable<T> nums)
    //{
    //    if (nums.Count() == 1)
    //    {
    //        yield return new T[1] { nums.First() };
    //    }
    //    else
    //    {
    //        IEnumerable<T> subNum = nums.Skip(1);
    //        var sub = AllPermutation<T>(subNum);
    //        foreach (var x in sub)
    //        {
    //            for (int i = 0; i <= x.Count(); i++)
    //            {
    //                var temp = x.ToList();
    //                temp.Insert(i, nums.First());
    //                yield return temp.ToArray();
    //            }
    //        }
    //    }
    //}

    public static List<List<T>> AllPermutation<T>(T[] nums)
    {
        if (nums.Length == 1)
        {
            List<List<T>> list = new List<List<T>>();
            list.Add(new List<T> { nums[0] });
            return list;
        }
        else
        {
            List<T> subNum = nums.ToList();
            subNum.RemoveAt(0);
            List<List<T>> sub = AllPermutation<T>(subNum.ToArray());
            List<List<T>> result = new List<List<T>>();
            foreach (var x in sub)
            {
                for (int i = 0; i < x.Count() + 1; i++)
                {
                    var temp = x.ToList();
                    temp.Insert(i, nums[0]);
                    result.Add(temp);
                }
            }
            return result;
        }
    }
}