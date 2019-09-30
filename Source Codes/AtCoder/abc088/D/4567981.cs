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
    static Scanner cin = new Scanner();
    struct p {
        public int x, y;
        public p(int X, int Y) {
            x = X;
            y = Y;
        }
    }
    static void Main() {
        int H = cin.Int();
        int W = cin.Int();
        var S = Enumerable.Repeat(0, H).Select(_ => Console.ReadLine()).ToArray();

        var dx = new int[] { -1, 1, 0, 0 };
        var dy = new int[] { 0, 0, -1, 1 };
        var que = new Queue<p>();

        var cnt = new int[H, W];
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cnt[i, j] = -1;
            }
        }
        cnt[0, 0] = 1;
        que.Enqueue(new p(0, 0));

        while(que.Count > 0) {
            p tmp = que.Dequeue();
            int nx = tmp.x;
            int ny = tmp.y;
            if (ny == H - 1 && nx == W - 1) break;
            for (int i = 0; i < 4; i++) {
                if(0 <= ny + dy[i] && ny + dy[i]< H && 0 <= nx + dx[i]&& nx + dx[i] < W){
                    if (S[ny + dy[i]][nx + dx[i]] != '#' && cnt[ny + dy[i], nx + dx[i]] == -1) {
                        que.Enqueue(new p(nx + dx[i], ny + dy[i]));
                        cnt[ny + dy[i], nx + dx[i]] = cnt[ny, nx] + 1;
                    }
                }
            }
        }

        if (cnt[H - 1, W - 1] == -1) Console.WriteLine(-1);
        else {
            int black = 0;
            for (int i = 0; i < H; i++) {
                for (int j = 0; j < W; j++) {
                    if (S[i][j] == '#') black++;
                }
            }

            Console.WriteLine(H * W - black - cnt[H - 1, W - 1]);
        }
        Console.ReadLine();
    }
}