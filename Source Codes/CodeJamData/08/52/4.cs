using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;

public class Program
{
    public static void Main()
    {
        using (var reader = new StreamReader("input.txt"))
        using (var writer = new StreamWriter("output.txt"))
        {
            var N = int.Parse(reader.ReadLine());
            for (var i = 0; i < N; i++)
            {
                var s = reader.ReadLine().Split();
                var R = int.Parse(s[0]);
                var C = int.Parse(s[1]);
                var lines = new string[R];
                for (int j = 0; j < R; j++)
                {
                    lines[j] = reader.ReadLine();
                }
                var res = f(R, C, lines);
                writer.Write(
                    "Case #{0}: {1}", i + 1, res == -1 ? "THE CAKE IS A LIE" : res.ToString());
                writer.WriteLine();
            }
        }
    }

    struct MyStruct: IEquatable<MyStruct>
    {
        public int X, Y, XD, YD;

        public MyStruct(int x, int y, int xd, int yd)
        {
            X = x;
            Y = y;
            XD = xd;
            YD = yd;
        }

        public bool Equals(MyStruct obj)
        {
            return obj.X == X && obj.Y == Y && obj.XD == XD && obj.YD == YD;
        }

        public override bool Equals(object obj)
        {
            if (obj.GetType() != typeof (MyStruct)) return false;
            return Equals((MyStruct) obj);
        }

        public override int GetHashCode()
        {
            unchecked
            {
                int result = X;
                result = (result * 397) ^ Y;
                result = (result * 397) ^ XD;
                result = (result * 397) ^ YD;
                return result;
            }
        }

        public static bool operator ==(MyStruct left, MyStruct right)
        {
            return left.Equals(right);
        }

        public static bool operator !=(MyStruct left, MyStruct right)
        {
            return !left.Equals(right);
        }
    }

    static bool[,] map;
    static int xCake, yCake;
    static int r, c;

    static long f(int R, int C, string[] lines)
    {
        r = R;
        c = C;
        map = new bool[R, C];
        int x = -1, y = -1;
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                map[i, j] = lines[i][j] != '#';
                if (lines[i][j] == 'O')
                {
                    y = i;
                    x = j;
                }
                if (lines[i][j] == 'X')
                {
                    yCake = i;
                    xCake = j;
                }
            }
        }
        return f(x, y, -1, -1);
    }

    static bool Map(int j, int i)
    {
        return 0 <= i && i < r && 0 <= j && j < c ? map[i, j] : false;
    }

    static long f(int x, int y, int xd, int yd)
    {
        Queue<MyStruct> queue = new Queue<MyStruct>();
        HashSet<MyStruct> hashSet = new HashSet<MyStruct>();
        List<MyStruct> list = new List<MyStruct>();
        MyStruct my = new MyStruct
                      {
                          X = x,
                          Y = y,
                          XD = xd,
                          YD = yd
                      };
        queue.Enqueue(my);
        hashSet.Add(my);
        long res = 0;
        while(queue.Count > 0)
        {
            list.Clear();
            while (queue.Count > 0)
            {
                my = queue.Dequeue();
                x = my.X;
                y = my.Y;
                if (x == xCake && y == yCake) return res;
                xd = my.XD;
                yd = my.YD;
                if (Map(x - 1, y))
                {
                    list.Add(new MyStruct(x-1, y, xd, yd));
                }
                if (Map(x + 1, y))
                {
                    list.Add(new MyStruct(x +1, y, xd, yd));
                   
                }
                if (Map(x, y - 1))
                {
                    list.Add(new MyStruct(x, y - 1, xd, yd));
                   
                }
                if (Map(x, y + 1))
                {
                    list.Add(new MyStruct(x, y + 1, xd, yd));
                   
                }
                if (xd != -1 && yd != -1 && (!Map(x - 1, y) || !Map(x + 1, y) || !Map(x, y - 1) || !Map(x, y + 1)))
                {
                    list.Add(new MyStruct(xd, yd, -1, -1));
                }
                int k;
                k = x;
                while (Map(k + 1, y)) k++;
                {
                    var myStruct = new MyStruct(x, y, k, y);
                    if (!hashSet.Contains(myStruct))
                    {
                        queue.Enqueue(myStruct);
                        hashSet.Add(myStruct);
                    }
                }
                k = x;
                while (Map(k - 1, y)) k--;
                {
                    var myStruct = new MyStruct(x, y, k, y);
                    if (!hashSet.Contains(myStruct))
                    {
                        queue.Enqueue(myStruct);
                        hashSet.Add(myStruct);
                    }
                }
                k = y;
                while (Map(x, k + 1)) k++;
                {
                    var myStruct = new MyStruct(x, y, x, k);
                    if (!hashSet.Contains(myStruct))
                    {
                        queue.Enqueue(myStruct);
                        hashSet.Add(myStruct);
                    }
                }
                k = y;
                while (Map(x, k - 1)) k--;
                {
                    var myStruct = new MyStruct(x, y, x, k);
                    if (!hashSet.Contains(myStruct))
                    {
                        queue.Enqueue(myStruct);
                        hashSet.Add(myStruct);
                    }
                }
            }
            foreach (var myStruct in list)
            {
                if (!hashSet.Contains(myStruct))
                {
                    queue.Enqueue(myStruct);
                    hashSet.Add(myStruct); 
                }
            }
            res++;
        }
        return -1;
    }

    //static long f(int x, int y, int xd, int yd)
    //{
    //    if (x == xCake && y == yCake) return 0;
    //    var mystruct = new MyStruct
    //                   {
    //                       X = x,
    //                       Y = y,
    //                       XD = xd,
    //                       YD = yd,
    //                   };
    //    if (!cache.ContainsKey(mystruct))
    //    {
    //        cache[mystruct] = -2;
    //        var res = long.MaxValue;
    //        if (Map(x - 1, y))
    //        {
    //            var t = f(x - 1, y, xd, yd);
    //            if (t == -2)
    //            {
    //                cache.Remove(mystruct);
    //                return -2;
    //            }
    //            if (t != -1)
    //            {
    //                res = Math.Min(res, t + 1);
    //            }
    //        }
    //        if (Map(x + 1, y))
    //        {
    //            var t = f(x + 1, y, xd, yd);
    //            if (t != -1)
    //            {
    //                res = Math.Min(res, t + 1);
    //            }
    //        }
    //        if (Map(x, y - 1))
    //        {
    //            var t = f(x, y - 1, xd, yd);
    //            if (t != -1)
    //            {
    //                res = Math.Min(res, t + 1);
    //            }
    //        }
    //        if (Map(x, y + 1))
    //        {
    //            var t = f(x, y + 1, xd, yd);
    //            if (t != -1)
    //            {
    //                res = Math.Min(res, t + 1);
    //            }
    //        }
    //        if (xd != -1 && yd != -1 && (!Map(x - 1, y) || !Map(x + 1, y) || !Map(x, y - 1) || !Map(x, y + 1)))
    //        {
    //            var t = f(xd, yd, -1, -1);
    //            if (t != -1)
    //            {
    //                res = Math.Min(res, t + 1);
    //            }
    //        }
    //        int k;
    //        k = x;
    //        while (Map(k + 1, y)) k++;
    //        {
    //            var t = f(x, y, k, y);
    //            if (t != -1)
    //            {
    //                res = Math.Min(res, t);
    //            } 
    //        }
    //        k = x;
    //        while (Map(k - 1, y)) k--;
    //        {
    //            var t = f(x, y, k, y);
    //            if (t != -1)
    //            {
    //                res = Math.Min(res, t);
    //            }
    //        }
    //        k = y;
    //        while (Map(x, k + 1)) k++;
    //        {
    //            var t = f(x, y, x, k);
    //            if (t != -1)
    //            {
    //                res = Math.Min(res, t);
    //            }
    //        }
    //        k = y;
    //        while (Map(x, k - 1)) k--;
    //        {
    //            var t = f(x, y, x, k);
    //            if (t != -1)
    //            {
    //                res = Math.Min(res, t);
    //            }
    //        }
    //        if (res != long.MaxValue) cache[mystruct] = res;
    //        else cache[mystruct] = -1;
    //    }
    //    return cache[mystruct];
    //}
}