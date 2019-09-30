using System;
using System.Collections.Generic;
using System.Linq;
class Scanner
{
    string[] s;
    int i;

    char[] cs = new char[] { ' ' };

    public Scanner() {
        s = new string[0];
        i = 0;
    }

    public string next() {
        if (i < s.Length) return s[i++];
        string st = Console.ReadLine();
        while (st == "") st = Console.ReadLine();
        s = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
        if (s.Length == 0) return next();
        i = 0;
        return s[i++];
    }

    public int Int() {
        return int.Parse(next());
    }
    public int[] ArrayInt(int N, int add = 0) {
        int[] Array = new int[N];
        for (int i = 0; i < N; i++) {
            Array[i] = Int() + add;
        }
        return Array;
    }

    public long Long() {
        return long.Parse(next());
    }

    public long[] ArrayLong(int N, long add = 0) {
        long[] Array = new long[N];
        for (int i = 0; i < N; i++) {
            Array[i] = Long() + add;
        }
        return Array;
    }
}
class Program {

    struct p {
        public int x, y;
        public p(int X, int Y) {
            x = X;
            y = Y;
        }
    }

    static Scanner cin = new Scanner();
    static void Main() {
        //int N = cin.Int();
        //int C = cin.Int();
        //var D = new long[35, 35];
        //for (int i = 1; i <= C; i++) {
        //    var tmp = cin.ArrayLong(C);
        //    for (int j = 0; j < C; j++) {
        //        D[i, j + 1] = tmp[j];
        //    }
        //}
        //var c = new int[510, 510];
        //for (int i = 1; i <= N; i++) {
        //    var tmp = cin.ArrayInt(N);
        //    for (int j = 0; j < N; j++) {
        //        c[i, j + 1] = tmp[j];
        //    }
        //}

        //var rest_0 = new List<p>(); //3???????0???
        //var rest_1 = new List<p>(); //???1
        //var rest_2 = new List<p>(); //???2

        //int I = 1;
        //while (I <= N) {
        //    for (int i = I; i >= 1; i--) {
        //        if (i % 3 == 0) rest_1.Add(new p(I + 1 - i, i));
        //        else if (i % 3 == 1) rest_2.Add(new p(I + 1 - i, i));
        //        else rest_0.Add(new p(I + 1 - i, i));
        //    }
        //    I++;
        //}

        //int J = 2;
        //while (J <= N) {
        //    for (int j = J; j >= N; j++) {
        //        if ((N + J) % 3 == 0) rest_0.Add(new p(j, N + J - j));
        //        else if ((N + J) % 3 == 1) rest_1.Add(new p(j, N + J - j));
        //        else rest_2.Add(new p(j, N + J - j));
        //    }
        //    J++;
        //}

        //var color0 = new long[C + 1]; //?????????
        //color0[0] = long.MaxValue;
        //foreach (var point in rest_0) {
        //    for (int i = 1; i <= C; i++) {
        //        if (c[point.y, point.x] != i) color0[i] += D[c[point.y, point.x], i];
        //    }
        //}

        //var color1 = new long[C + 1];
        //color1[0] = long.MaxValue;
        //foreach (var point in rest_1) {
        //    for (int i = 1; i <= C; i++) {
        //        if (c[point.y, point.x] != i) color1[i] += D[c[point.y, point.x], i];
        //    }
        //}

        //var color2 = new long[C + 1];
        //color2[0] = long.MaxValue;
        //foreach (var point in rest_2) {
        //    for (int i = 1; i <= C; i++) {
        //        if (c[point.y, point.x] != i) color2[i] += D[c[point.y, point.x], i];
        //    }
        //}

        //Console.WriteLine(color0.Min() + color1.Min() + color2.Min());


        //int N = cin.Int();
        //var A = cin.ArrayInt(N);

        //if (N == 1) Console.WriteLine(1);
        //else {
        //    int cnt = 1;
        //    bool increase = A[1] >= A[0];
        //    for (int i = 1; i < N; i++) {
        //        if(A[i] > A[i - 1]) {
        //            if (!increase) {
        //                cnt++;
        //                increase = true;
        //            }
        //        }else if(A[i] < A[i - 1]) {
        //            if (increase) {
        //                cnt++;
        //                increase = false;
        //            }
        //        }
        //    }
        //    Console.WriteLine(cnt);
        //}

        var name = Console.ReadLine().ToCharArray();
        var reverse = name.Reverse().ToArray();
        for (int i = 0; i < name.Length; i++) {
            if(name[i] != reverse[i]) {
                Console.WriteLine("NO");
                return;
            }
        }
        Console.WriteLine("YES");
        Console.ReadLine();
    }
}