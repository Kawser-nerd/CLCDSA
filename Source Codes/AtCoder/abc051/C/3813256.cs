using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Atcoder
{
    class Program
    {

        static List<int[]> list = new List<int[]>();
        static int[] yMove = new int[] {-1,1,0,0};
        static int[] xMove = new int[] {0,0,-1,1};
        static bool[,] miz;

        static void Main(string[] args)
        {

            //var line1 = Array.ConvertAll(Console.ReadLine().Split(), long.Parse);
            //var N = line1[0];
            //var M = line1[1];
            //var a = new long[M];
            //var b = new long[M];

            //int bridge = 0;

            //int[,] dag = new int[N,N];

            //for (int i = 0; i < M; i++)
            //{
            //    var line2 = Array.ConvertAll(Console.ReadLine().Split(), long.Parse);
            //    a[i] = line2[0]-1;
            //    b[i] = line2[1]-1;
            //    dag[a[i], b[i]] = 1;
            //    dag[b[i], a[i]] = 1;
            //}

            //for (int i = 0; i < M; i++)
            //{
            //    bool[] visited = new bool[N];
            //    dag[a[i], b[i]] = 0;
            //    dag[b[i], a[i]] = 0;
            //    DFS(0,visited,dag);

            //    if (visited.Where(n => n == true).Count() != N)
            //    {
            //        bridge++;
            //    }

            //    dag[a[i], b[i]] = 1;
            //    dag[b[i], a[i]] = 1;
            //}
            //Console.WriteLine(bridge);
            //var line1 = Array.ConvertAll(Console.ReadLine().Split(), long.Parse);

            //var A = line1[0];
            //var B = line1[1];
            //var C = line1[2];
            //var D = line1[3];
            //var E = line1[4];
            //var F = line1[5];

            //var N = int.Parse(Console.ReadLine());
            //char[] mozi = new char[N];
            //long[] MARCH = new long[5];
            //long cnt = 0;


            //for (int i = 0; i < N; i++)
            //{
            //    mozi[i] = Console.ReadLine().ToCharArray()[0];
            //}

            //MARCH[0] = mozi.Where(n => n == 'M').Count();
            //MARCH[1] = mozi.Where(n => n == 'A').Count();
            //MARCH[2] = mozi.Where(n => n == 'R').Count();
            //MARCH[3] = mozi.Where(n => n == 'C').Count();
            //MARCH[4] = mozi.Where(n => n == 'H').Count();

            //for (int i = 0; i < 3; i++)
            //{
            //    for (int j = i + 1; j < 4; j++)
            //    {
            //        for (int k = j + 1; k < 5; k++)
            //        {
            //            cnt += MARCH[i] * MARCH[j] * MARCH[k];
            //        }
            //    }
            //}

            //Console.WriteLine(cnt);

            //var N = int.Parse(Console.ReadLine());

            //var line1 = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            //var line2 = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            //int candy = 0;
            //int MAX = 0;

            //for (int i = 0; i < N; i++)
            //{
            //    for (int k = 0; k <= i; k++)
            //    {
            //        candy += line1[k];
            //    }

            //    for (int j = N - 1; j >= i; j--)
            //    {
            //        candy += line2[j];
            //    }

            //    MAX = Math.Max(candy,MAX);
            //    candy = 0;
            //}

            //Console.WriteLine(MAX);

            //var N = int.Parse(Console.ReadLine());
            //List<int[]> list = new List<int[]>();
            //int t = 0;
            //int x = 0;
            //int y = 0;

            //for (int i = 0; i < N; i++)
            //{
            //    var txy = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            //    list.Add(txy);
            //}

            //foreach (var item in list)
            //{
            //    if (item[0] - t >= Math.Abs(item[1] + item[2] - x - y))
            //    {

            //        if (((item[0] - t) % 2 == 1 && Math.Abs(x + y - item[1] - item[2]) % 2 == 1) ||
            //            ((item[0] - t) % 2 == 0 && Math.Abs(x + y - item[1] - item[2]) % 2 == 0))
            //        {
            //            t = item[0];
            //            x = item[1];
            //            y = item[2];
            //        }
            //        else
            //        {
            //            Console.WriteLine("No");
            //            return;
            //        }
            //    }
            //    else
            //    {
            //        Console.WriteLine("No");
            //        return;
            //    }
            //}

            //Console.WriteLine("Yes");

            //var line1 = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);

            //if (line1[1] >= 10000)
            //{
            //    for (int i = 0; i <= line1[1]/10000; i++)
            //    {
            //        for (int j = 0; j <= line1[1] / 5000; j++)
            //        {
            //            if (10000 * i + 5000 * j + (line1[0] - i - j) * 1000 == line1[1] && line1[0] - i - j >= 0)
            //            {
            //                Console.WriteLine("{0} {1} {2}",i,j,line1[0] - i - j);
            //                return;
            //            }
            //        }
            //    }
            //}
            //else
            //{
            //    for (int i = 0; i < 2; i++)
            //    {
            //        for (int j = 0; j <= 9; j++)
            //        {
            //            if (5000 * i + 1000 * j == line1[1] && i + j == line1[0])
            //            {
            //                Console.WriteLine("{0} {1} {2}", 0, i, j);
            //                return;
            //            }
            //        }
            //    }
            //}

            //Console.WriteLine("{0} {1} {2}", -1, -1, -1);


            //var N = int.Parse(Console.ReadLine());
            //int[,] station = new int[N,3];
            //long sum = 0;


            //for (int i = 0; i < N - 1; i++)
            //{
            //    var line = Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
            //    station[i, 0] = line[0];
            //    station[i, 1] = line[1];
            //    station[i, 2] = line[2];
            //}

            //for (int j = 0; j < N -1; j++)
            //{
            //    for (int i = j; i < N - 1; i++)
            //    {
            //        var F = station[i, 2];
            //        var S = station[i, 1];
            //        if (i == j)
            //        {
            //            sum += station[i, 0] + station[i, 1];
            //        }
            //        else
            //        {
            //            if (sum < S)
            //            {
            //                sum = S + station[i, 0];
            //            }
            //            else if (sum % F == 0)
            //            {
            //                sum += station[i, 0];
            //            }
            //            else
            //            {
            //                sum += F - (sum % F) + station[i, 0];
            //            }
            //        }
            //    }

            //    Console.WriteLine(sum);
            //    sum = 0;
            //}
            //Console.WriteLine(sum);

            //var line = Array.ConvertAll(Console.ReadLine().Split(), long.Parse);
            //long A = line[0];
            //int i = 0;

            //while (A <= line[1])
            //{
            //    A *=2;
            //    i++;
            //}

            //Console.WriteLine(i);
            //var N = long.Parse(Console.ReadLine());
            //var line = Array.ConvertAll(Console.ReadLine().Split(),long.Parse);
            //Dictionary<long, long> dic = new Dictionary<long, long>();
            //long sum = 0;

            //for (int i = 0; i < N; i++)
            //{
            //    if (dic.ContainsKey(line[i]))
            //    {
            //        dic[line[i]]++;
            //    }
            //    else
            //    {
            //        dic.Add(line[i], 1);
            //    }
            //}

            //foreach (var item in dic)
            //{
            //    if (item.Key == item.Value)
            //    {

            //    }
            //    else if (item.Key < item.Value)
            //    {
            //        sum += item.Value - item.Key;
            //    }
            //    else
            //    {
            //        sum += item.Value;
            //    }
            //}

            //Console.WriteLine(sum);

            //var line = Array.ConvertAll(Console.ReadLine().Split(),long.Parse);
            //var N = line[0];
            //var K = line[1];

            //var line2 = Array.ConvertAll(Console.ReadLine().Split(), long.Parse);
            //long cnt = 0;
            //long sum = 0;

            //long[] lngarray = new long[N];

            //for (int i = 0; i < N; i++)
            //{
            //    lngarray[line2[i]-1]++;
            //}

            //if (lngarray.Where(n => n !=0).Count() <= K)
            //{
            //    Console.WriteLine(0);
            //    return;
            //}

            //var orderlng = lngarray.Where(n => n != 0).OrderBy(n => n).ToArray();

            //for (int i = 0; i < orderlng.Length; i++)
            //{
            //    if (cnt == orderlng.Length - K)
            //    {
            //        Console.WriteLine(sum);
            //        return;
            //    }
            //    else
            //    {
            //        sum += orderlng[i];
            //        cnt++;
            //    }
            //}
            //int soe = 0;
            //saiki(soe, new int[10]);

            //var N = int.Parse(Console.ReadLine());
            //var F = new List<int[]>();
            //var P = new List<int[]>();

            //for (int i = 0; i < N; i++)
            //{
            //    var line = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            //    F.Add(line);
            //}

            //for (int i = 0; i < N; i++)
            //{
            //    var line = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            //    P.Add(line);
            //}

            //int sum = int.MinValue;
            //list.RemoveAt(0);
            //foreach (var item in list)
            //{
            //    int tmpsum = 0;
            //    for (int i = 0; i < N; i++)
            //    {
            //        int c = 0;
            //        for (int j = 0; j < 10; j++)
            //        {
            //            if (item[j] == 1 && F[i][j] == 1)
            //            {
            //                c++;
            //            }
            //        }

            //        tmpsum += P[i][c];
            //    }
            //    sum = Math.Max(sum, tmpsum);
            //}

            //Console.WriteLine(sum);


            //var line = Console.ReadLine().ToCharArray();
            //int[] hai = new int[7];

            //hai[0] = int.Parse(line[0].ToString());
            //hai[2] = int.Parse(line[1].ToString());
            //hai[4] = int.Parse(line[2].ToString());
            //hai[6] = int.Parse(line[3].ToString());

            //saikiseven(1,0, hai);

            //string ope1 = list[0][1] == 0 ? "+" : "-";
            //string ope2 = list[0][3] == 0 ? "+" : "-";
            //string ope3 = list[0][5] == 0 ? "+" : "-";

            //Console.WriteLine("{0}{1}{2}{3}{4}{5}{6}=7", list[0][0],ope1, list[0][2], ope2,list[0][4], ope3,list[0][6]);

            //var N = long.Parse(Console.ReadLine());
            //var line = Array.ConvertAll(Console.ReadLine().Split(), long.Parse);
            //long[] A = new long[N];

            //for (int i = 0; i < N; i++)
            //{
            //    A[i] = Math.Abs(i - (N - i -1));
            //}

            //var tmp1 = line.OrderBy(n => n).ToArray();
            //var tmp2 = A.OrderBy(n => n).ToArray();

            //for (int i = 0; i < N; i++)
            //{
            //    if (tmp1[i] != tmp2[i])
            //    {
            //        Console.WriteLine(0);
            //        return;
            //    }
            //}

            //long X = 1;

            //for (int i = 0; i < N/2; i++)
            //{
            //    X *= 2;
            //    X %= 1000000007;
            //}
            //Console.WriteLine(X);

            var line =Array.ConvertAll(Console.ReadLine().Split(),int.Parse);

            var sx = line[0];
            var sy = line[1];
            var tx = line[2];
            var ty = line[3];

            var path1 = new string('U', ty - sy) + new string('R',tx - sx);
            var path2 = new string('D', ty - sy) + new string('L', tx - sx);
            var path3 = new string('L', 1) + new string('U', ty - sy + 1) + new string('R', tx - sx + 1) + new string('D', 1);
            var path4 = new string('R', 1) + new string('D', ty - sy + 1) + new string('L', tx - sx + 1) + new string('U', 1);
            Console.WriteLine(path1 + path2 + path3 + path4);
        }

        public static void DFSzahyo(int x, int y,int[] s,int[] g)
        {

            if (x == g[0] && y == g[1])
            {
                return;
            }
            miz[x, y] = true;
            for (int i = 0; i < 4; i++)
            {
                if (miz[x + xMove[i], y + yMove[i]] != true)
                {
                    DFSzahyo(x + xMove[i], y + yMove[i],s,g);
                }
            }
        }

        public static void saikiseven(int ope, int sum ,int[] hairetui)
        {
            if (ope == 1)
            {
                sum = hairetui[ope - 1];
            }

            if (ope == 7 && sum == 7)
            {
                int[] dummy = new int[ope];
                hairetui.CopyTo(dummy, 0);
                list.Add(dummy);
                return;
            }
            else if (ope == 7 && sum != 7)
            {
                return;
            }

            for (int i = 0; i < 2; i++)
            {
                if (i == 0)
                {
                    sum += hairetui[ope + 1];
                    hairetui[ope] = i;
                    saikiseven(ope + 2, sum, hairetui);
                    sum -= hairetui[ope + 1];
                }
                else
                {
                    sum -= hairetui[ope + 1];
                    hairetui[ope] = i;
                    saikiseven(ope + 2, sum, hairetui);
                }
            }

            return;
        }

        public static void saiki(int soezi,int[] hairetui)
        {
            if (soezi == 10)
            {
                int[] dummy = new int[soezi];
                 hairetui.CopyTo(dummy,0);
                list.Add(dummy);
                return;
            }

            for (int j = 0; j < 2; j++)
            {
                hairetui[soezi] = j;
                saiki(soezi+1, hairetui);
            }

            return;
        }

        public static void DFS(int v,bool[] visited,int[,] dag)
        {
            visited[v] = true;

            for (int i = 0; i < visited.Length; i++)
            {
                if (dag[v, i] == 0) continue;
                if (visited[i]) continue;
                DFS(i,visited,dag);
            }

        }

        public static long LowerBound<T>(T[] arr, long start, long end, T value, IComparer<T> comparer)
        {
            long low = start;
            long high = end;
            long mid;
            while (low < high)
            {
                mid = ((high - low) >> 1) + low;
                if (comparer.Compare(arr[mid], value) < 0)
                    low = mid + 1;
                else
                    high = mid;
            }
            return low;
        }

        //????????????
        public static long LowerBound<T>(T[] arr, T value) where T : IComparable
        {
            return LowerBound(arr, 0, arr.Length, value, Comparer<T>.Default);
        }
        public static long UpperBound<T>(T[] arr, long start, long end, T value, IComparer<T> comparer)
        {
            long low = start;
            long high = end;
            long mid;
            while (low < high)
            {
                mid = ((high - low) >> 1) + low;
                if (comparer.Compare(arr[mid], value) <= 0)
                    low = mid + 1;
                else
                    high = mid;
            }
            return low;
        }

        //????????????
        public static long UpperBound<T>(T[] arr, T value)
        {
            return UpperBound(arr, 0, arr.Length, value, Comparer<T>.Default);
        }
    }



}