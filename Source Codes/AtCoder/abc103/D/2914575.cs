using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;



namespace ConsoleApplication1
{
    public class Hello
    {
        #region
        //static char[,] maze;
        //static int H;
        //static int W;

        //static int[] wd = new int[] { 0, 0, 1, -1 };
        //static int[] hd = new int[] { 1, -1, 0, 0 };
        #endregion
        //static int[,] maze;
        //static int H;
        //static int W;
        //static int[] wd = new int[] { -1, 0, 1 ,-1 , 1, -1 , 0 , 1};
        //static int[] hd = new int[] { -1, -1, -1, 0 , 0 , 1 , 1 , 1 };

        public static void Main()
        {
            #region
            //int a = 0, b = 0, c = 0, d = 0;
            //int[] x = new int[6];
            //int e = 0;
            //var line = System.Console.ReadLine().Split(' ');
            //a = int.Parse(line[0]);
            //b = int.Parse(line[1]);
            //c = int.Parse(line[2]);
            //d = int.Parse(line[3]);
            //x[0] = a * 10 + b + c * 10 + d;
            //x[1] = a * 10 + b + d * 10 + c;
            //x[2] = a + b * 10 + c * 10 + d;
            //x[3] = a + b * 10 + d * 10 + c;
            //x[4] = a * 10 + b * 10 + c + d;
            //x[5] = a + b + c * 10 + d * 10;
            //for (int i = 0; i < 6; i++)
            //{
            //    if (i == 0)
            //    {
            //        e = x[i];
            //    }
            //    if (e < x[i])
            //    {
            //        e = x[i];
            //    }
            //}
            //System.Console.WriteLine(e);
            //int z = 0;
            //do
            //{
            //    if (z == 10000)
            //    {
            //        break;
            //    }
            //    z++;
            //} while (true);
            //System.Console.WriteLine("??");

            //var line = System.Console.ReadLine().Split(' ');
            //int S = int.Parse(line[0]);
            //int a = int.Parse(line[1]);
            //int b = int.Parse(line[2]);
            //int C = 0;
            //int flg = 0;

            //C = S + 10;
            //do
            //{

            //    if (C > b - 1000)
            //    {
            //        break;
            //    }
            //    else
            //    {
            //        C = C + 1000;
            //        flg = 1;
            //    }

            //    if (C  > a - 10)
            //    {
            //        break;
            //    }
            //    else
            //    {
            //        C = C + 10;
            //        flg = 0;
            //    }
            //} while (true);

            //if (flg == 0)
            //{
            //    System.Console.WriteLine("A " + C);
            //}
            //else
            //{
            //    System.Console.WriteLine("B " + C);
            //}
            //int a = 0, b = 0;
            //var line = System.Console.ReadLine().Split(' ');
            //a = int.Parse(line[0]);
            //b = int.Parse(line[1]);
            //int hogisho = 0,hogiamari =1000,sho = 0,amari = 0,hogirow = 0;
            //for (int i = 0; i < a; i++)
            //{
            //    var machine = int.Parse(System.Console.ReadLine());
            //    //sho = b / machine;
            //    amari = b % machine;

            //    if (hogiamari > amari)
            //    {
            //        hogirow = i + 1;
            //        hogiamari = amari;
            //        hogisho = machine;
            //    }
            //    else if (hogiamari == amari)
            //    {
            //        if (hogisho < machine)
            //        {
            //            hogirow = i + 1;
            //            hogisho = machine;
            //        }
            //    }
            //if (hogisho < sho)
            //{
            //    hogirow = i + 2;
            //    hogisho = sho;
            //}
            //else if (hogisho == sho)
            //{
            //    if (hogiamari < amari)
            //    {
            //        hogirow = i + 2;
            //        hogiamari = amari;
            //    }
            //}

            //    }
            //    System.Console.WriteLine(hogirow);

            //int a = 0;
            //var line = System.Console.ReadLine();
            //a = int.Parse(line);
            //int idouhogi = 0,zenkaikai = 0;
            //for (int i = 0; i < a; i++)
            //{
            //    var kai = int.Parse(System.Console.ReadLine());
            //    if (i ==0)
            //    {
            //        idouhogi = kai -  1;
            //        zenkaikai = kai;
            //    }
            //    idouhogi = idouhogi + System.Math.Abs(kai - zenkaikai);
            //    zenkaikai = kai;
            //}
            //System.Console.WriteLine(idouhogi);
            //double a = 0,cpri = 0, hogicpri = 0;
            //double b = 0;
            //var line = System.Console.ReadLine().Split(' ');
            //a = int.Parse(line[0]);
            //b = 1 - (double.Parse(line[1])/100);
            //hogicpri = a;
            //cpri = a;
            //do
            //{
            //    cpri = System.Math.Floor(cpri * b);
            //    if (cpri < 1)
            //    {
            //        break;
            //    }
            //    hogicpri = hogicpri + cpri;
            //} while (true);
            //System.Console.WriteLine(hogicpri);

            //    int a = 0, b = 0;
            //    string output = "";

            //    var line = System.Console.ReadLine().Split(' ');
            //    a = int.Parse(line[0]);
            //    b = int.Parse(line[1]);

            //    for (int i = 0; i < a; i++)
            //    {
            //        var input = System.Console.ReadLine().Split(' ');

            //        for (int j  = 0; j < b; j++)
            //        {
            //            if (int.Parse(input[j]) > 127)
            //            {
            //                if (j == b -1)
            //                {
            //                    output = output + "1";
            //                }
            //                else
            //                {
            //                    output = output + "1 ";
            //                }
            //            }
            //            else
            //            {
            //                if (j == b - 1)
            //                {
            //                    output = output + "0";
            //                }
            //                else
            //                {
            //                    output = output + "0 ";
            //                }
            //            }

            //        }
            //        System.Console.WriteLine(output);
            //        output = "";
            //    }
            //// ?????
            //int a = int.Parse(System.Console.ReadLine());
            // ?????????????
            //string[] input = System.Console.ReadLine().Split(' ');
            //double b = double.Parse(input[0]);
            //double c = double.Parse(input[1]);
            //double d = b * c;

            //if (d % 2 == 0)
            //{
            //    //??
            //    System.Console.WriteLine("Even");
            //}
            //else
            //{
            //    //??
            //    System.Console.WriteLine("Odd");
            //}
            //int a = 0;
            //// ?????????????
            //char[] input = System.Console.ReadLine().ToCharArray();
            //for (int i = 0; i < 3; i++)
            //{
            //    if (input[i] == '1')
            //    {
            //        a++;
            //    }
            //}

            //??
            //System.Console.WriteLine(a);
            //int cnt = 0;
            //bool flg = false;
            //// ?????
            //int N = int.Parse(Console.ReadLine());
            //// ?????????????
            //string[] input = Console.ReadLine().Split(' ');
            //do
            //{
            //    for (int i = 0; i < N; i++)
            //    {
            //        int tmp = int.Parse(input[i]);
            //        if (tmp % 2 == 0)
            //        {
            //            input[i] = (tmp / 2).ToString();
            //        }
            //        else
            //        {
            //            flg = true;
            //            break;
            //        }
            //    }
            //    if (flg)
            //    {
            //        break;
            //    }
            //    else
            //    {
            //        cnt++;
            //    }
            //} while (true);

            //System.Console.WriteLine(cnt);
            //// ?????
            //int A = int.Parse(Console.ReadLine());
            //int B = int.Parse(Console.ReadLine());
            //int C = int.Parse(Console.ReadLine());
            //int X = int.Parse(Console.ReadLine());

            //int combination = 0;

            //for (int i = 0; i < A+1; i++)
            //{
            //    if(500 * i > X)
            //    {
            //        break;
            //    }
            //    for (int j = 0; j < B+1; j++)
            //    {
            //        for (int r = 0; r < C+1; r++)
            //        {
            //            if ((500 * i + 100 * j + 50 * r) == X)
            //            {
            //                combination++;
            //            }
            //        }

            //    }
            //}
            //Console.WriteLine(combination);


            // ?????????????
            //string[] input = Console.ReadLine().Split(' ');
            //int tmp = 0;
            //int sum = 0;
            //for (int i = 0; i < int.Parse(input[0]) + 1; i++)
            //{
            //    char[] intdata = i.ToString().ToCharArray();
            //    for (int j = 0; j < intdata.Length; j++)
            //    {
            //        tmp = tmp + int.Parse(intdata[j].ToString());
            //    }
            //    if (tmp >= int.Parse(input[1]) && tmp <= int.Parse(input[2]))
            //    {
            //        sum = sum + i;
            //    }
            //    tmp = 0;
            //}
            //Console.WriteLine(sum);

            //// ?????
            //int N = int.Parse(Console.ReadLine());
            //double tmp = 0;
            //double max = 0;

            //int[] x = new int[N];
            //int[] y = new int[N];

            //for (int i = 0; i < N; i++)
            //{
            //    // ?????????????
            //    string[] input = Console.ReadLine().Split(' ');

            //    x[i] = int.Parse(input[0]);
            //    y[i] = int.Parse(input[1]);
            //}

            //for (int a = 0; a < N; a++)
            //{
            //    for (int b = 0; b < N; b++)
            //    {
            //        tmp = Math.Sqrt(Math.Pow((x[a] - x[b]), 2) + Math.Pow((y[a] - y[b]), 2));
            //        if (max < tmp)
            //        {
            //            max = tmp;

            //        }
            //    }
            //}

            //Console.WriteLine(max);

            //// ?????
            //int L = int.Parse(Console.ReadLine());
            //// ?????
            //int N = int.Parse(Console.ReadLine());

            //int tmpmin = 0;

            //int tmpmax = 0;

            //int min = 0;

            //int max = 0;

            //string minhoukou = "";
            //string maxhoukou = "";

            //// ?????????????
            //string[] input = Console.ReadLine().Split(' ');

            //for (int i = 0; i < N; i++)
            //{
            //    if (Math.Abs(int.Parse(input[i])-L) < Math.Abs(int.Parse(input[i])))
            //    {
            //        tmpmax = Math.Abs(int.Parse(input[i]));
            //        tmpmin = Math.Abs(int.Parse(input[i]) - L);

            //        if (i == N -1)
            //        {
            //            minhoukou = minhoukou + "?";
            //            maxhoukou = maxhoukou + "?";
            //        }
            //        else
            //        {
            //            minhoukou = minhoukou + "??";
            //            maxhoukou = maxhoukou + "?
            //                ?";
            //        }

            //    }
            //    else
            //    {
            //        tmpmax = Math.Abs(int.Parse(input[i]) - L);
            //        tmpmin = Math.Abs(int.Parse(input[i]));

            //        if (i == N - 1)
            //        {
            //            minhoukou = minhoukou + "?";
            //            maxhoukou = maxhoukou + "?";
            //        }
            //        else
            //        {
            //            minhoukou = minhoukou + "??";
            //            maxhoukou = maxhoukou + "??";
            //        }
            //    }

            //    if (tmpmax > max)
            //    {
            //        max = tmpmax;
            //    }
            //    if (tmpmin > min)
            //    {
            //        min = tmpmin;
            //    }

            //}

            //Console.WriteLine(min + " {" + minhoukou + "}");
            //Console.WriteLine(max + " {" + maxhoukou + "}");
            //Queue<string> que = new Queue<string>() { };
            //Stack<string> sta = new Stack<string>() { };

            //// ?????????????
            //    string[] input = Console.ReadLine().Split(' ');
            //    H = int.Parse(input[0]);
            //    W = int.Parse(input[1]);
            //    //int sx = 0, sy = 0, gx = 0, gy = 0;
            //    maze = new char[H, W];

            //    for (int i = 0; i <H; i++)
            //    {
            //        var line = Console.ReadLine().ToCharArray();
            //        for (int j = 0; j < W; j++)
            //        {
            //            maze[i,j]= line[j];
            //        }
            //    }
            //    for (int i = 0; i < H; i++)
            //    {
            //        for (int j = 0; j < W; j++)
            //        {
            //            if (maze[i,j] == 's')
            //            {
            //                if (DFS(i, j))
            //                {
            //                    Console.WriteLine("YES");
            //                }
            //                else
            //                {
            //                    Console.WriteLine("NO");
            //                }
            //            }
            //        }
            //    }
            #endregion
            #region 1
            //    int cnt= 0;
            //    do
            //    {
            //        var line = Console.ReadLine().Split(' ');
            //        W = int.Parse(line[0]);
            //        H = int.Parse(line[1]);
            //        maze = new int[H, W];

            //        if (H == 0)
            //        {
            //            break;
            //        }

            //        for (int i = 0; i < H; i++)
            //        {
            //            var dataline = Console.ReadLine().Split(' ');
            //            for (int j = 0; j < W; j++)
            //            {
            //                maze[i, j] = int.Parse(dataline[j]);
            //            }
            //        }

            //        for (int i = 0; i < H; i++)
            //        {
            //            for (int j = 0; j < W; j++)
            //            {
            //                if (maze[i, j] == 1)
            //                {
            //                    DFS(i, j);
            //                    cnt++;
            //                }
            //            }
            //        }
            //        Console.WriteLine(cnt);
            //        cnt = 0;

            //    } while (true);
            //var line = Console.ReadLine().Split(' ');
            //int a = int.Parse(line[0]);
            //int b = int.Parse(line[1]);
            //int cnt = 0;

            //Hashtable ht = new Hashtable();

            //for (int i = 1; i < 1000; i++)
            //{
            //    cnt = cnt + i;
            //    ht.Add(i, cnt);
            //}

            //int value = (int)ht[(b - a)];
            //Console.WriteLine(value - b); 


            //int a = int.Parse(line);
            //if (a < 1000)
            //{
            //    Console.WriteLine("ABC");

            //}
            //else
            //{
            //    Console.WriteLine("ABD");
            //}


            //double[] roku = new double[7];
            //double[] kyuu = new double[6];
            //double max= 0;
            //int cnt = 0;

            //for (int i = 0; i < 7; i++)
            //{
            //    roku[i] = Math.Pow(6, i +1);
            //}

            //for (int j = 0; j < 6; j++)
            //{
            //    kyuu[j] = Math.Pow(9, j +1);
            //}
            //var line = Console.ReadLine();
            //double value = int.Parse(line);

            //do
            //{
            //    for (int j = 0; j < 6; j++)
            //    {
            //        if (value > kyuu[j] && max < kyuu[j])
            //        {
            //            max = kyuu[j];
            //        }
            //    }
            //    for (int j = 0; j < 7; j++)
            //    {
            //        if (value > roku[j] && max < roku[j])
            //        {
            //            max = roku[j];
            //        }
            //    }

            //    if(max == 0)
            //    {
            //        max = 1;
            //    }
            //    value = value - max;
            //    max = 0;
            //    cnt++;

            //    if (value == 0)
            //    {
            //        Console.WriteLine(cnt);
            //        break;
            //    }

            //} while (true);


            ////var line = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
            ////int N = 0,W=0;
            ////N = line[0];
            ////W = line[1];
            ////int[] w = new int[N];
            ////int[] v = new int[N];

            ////for (int i = 0; i < N; i++)
            ////{
            ////    var tmpline = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);

            ////    v[i] = tmpline[0];
            ////    w[i] = tmpline[1];
            ////}

            ////int[,] dp = new int[N+1, W+1];

            ////dp[0, 0] = 0;

            ////for (int i = 0; i < N; i++)
            ////{
            ////    for (int j = 1;  j < W + 1;  j++)
            ////    {
            ////        if (j - w[i] <0)
            ////        {
            ////            dp[i + 1, j] = dp[i, j];
            ////        }
            ////        else
            ////        {
            ////            dp[i + 1, j] = Math.Max(dp[i, j], dp[i, j - w[i]] + v[i]);
            ////        }

            ////    }
            ////}
            ////Console.WriteLine(dp[N,W]);
            //var fsline = Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
            //int W = fsline[0];
            //var sdline = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            //int N = sdline[0];
            //int K = sdline[1];

            //int[] a = new int[N];
            //int[] b = new int[N];

            //for (int i = 0; i < N; i++)
            //{
            //    var tmpline = Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
            //    a[i] = tmpline[0];
            //    b[i] = tmpline[1];
            //}

            //int[,,] dp = new int[N+1, W+1,K+1];
            //int outmax = 0;
            //dp[0, 0, 0] = 0;

            //for (int i = 0; i < N; i++)
            //{
            //    for (int j = 0; j <= W; j++)
            //    {
            //        for (int r = 0; r < K; r++)
            //        {
            //            if (j - a[i] < 0)
            //            {
            //                dp[i + 1, j, r + 1] = dp[i, j, r + 1];
            //            }
            //            else
            //            {
            //                dp[i + 1, j, r + 1] = Math.Max(dp[i, j, r + 1], dp[i, j - a[i], r] + b[i]);

            //            }
            //        }

            //    }
            //}


            //for (int i = 0; i <= K; i++)
            //{
            //    outmax = Math.Max(outmax, dp[N, W, i]);
            //}
            //Console.WriteLine(outmax);

            #endregion 1

            int ans = 0;
            var sl = new List<int[]>();
            var line = Array.ConvertAll(Console.ReadLine().Split(),int.Parse);


            for (int i = 0; i < line[1]; i++)
            {
                var line2 = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
                sl.Add(line2);
            }

            var sl2 = sl.OrderBy(n => n[1]);

            var t = 0;

            foreach (var item in sl2)
            {
                if (t <= item[0])
                {
                    ans++;
                    t = item[1];
                }
            }

            Console.WriteLine(ans);
        }

        //public static void Solve()
        //{
        //    var N = int.Parse(Console.ReadLine());
        //    var dp = new int[N + 1];
        //    for (var i = 0; i <= N; i++)
        //    {
        //        dp[i] = i;
        //    }
        //    var t = new int[] { 6, 9, 36, 81, 216, 729, 1296, 6561, 7776, 46656, 59049 };
        //    foreach (var x in t)
        //    {
        //        for (var i =i++)
        //        {

        //            dp[i] = Math.Min(dp[i], dp[i - x] + 1);
        //        }
        //    }
        //    Console.WriteLine(dp[N]);
        //}

        #region DFS
        //public static bool DFS(int x, int y)
        //{

        //    if (maze[x,y] == 'g') return true;

        //    maze[x,y] = '#';
        //    for (var i = 0; i < 4; i++)
        //    {
        //        var nh = hd[i] + x;
        //        var nw = wd[i] + y;
        //        if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue;

        //        if (maze[nh, nw] == '#') continue;

        //        if (DFS(nh, nw))
        //        {
        //            return true;
        //        }
        //    }
        //    return false;
        //}
        //public static bool DFS(int x,int y)
        //{
        //    maze[x, y] = 2;
        //    for (int i = 0; i < 8; i++)
        //    {
        //        var nh = hd[i] + x;
        //        var nw = wd[i] + y;

        //        if (nh < 0 || nw < 0 || nh >= H || nw >= W)
        //        {
        //            continue;
        //        }

        //        if (maze[nh, nw] == 0 || maze[nh, nw] == 2)
        //        {
        //            continue;
        //        }

        //        if (DFS(nh, nw))
        //        {
        //            return true;
        //        }
        //    }
        //    return false;
        //}
        #endregion DFS

    }
}