using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.IO;
using System.Linq;
using System.Linq.Expressions;
using static System.Console;
using static System.Math;
class Simple
{
    int H, W, T;
    string[] s;
    void Solve() {
        //input
        H = io.Int;
        W = io.Int;
        T = io.Int;
        s = new string[H];
        for (int i = 0; i < H; ++i) s[i] = io.String;
        
        //cal
        int sy=0, sx=0, gy=0, gx=0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (s[i][j] == 'S')      { sy = i; sx = j; } 
                else if (s[i][j] == 'G') { gy = i; gx = j; }
            }
        }
        Func<int, int, bool> inRange = (x, y) => 0 <= x && x < W && 0 <= y && y < H;
        var sPoint = new Point(sx, sy);
        Func<int, bool> f = (t) => {
            var time = new long[H, W];
            for (int i = 0; i < H; ++i) for (int j = 0; j < W; ++j) 
                time[i, j] = long.MaxValue / 2;
            time[sy, sx] = 0;
            var q = new Queue<Point>();
            q.Enqueue(sPoint);
            while (q.Count > 0) {
                var qur = q.Dequeue();
                var cx = qur.X;
                var cy = qur.Y;
                for (int i = 0; i < 4; ++i) {
                    var nx = cx + dx[i];
                    var ny = cy + dy[i];
                    if (inRange(nx, ny)) {
                        var nextTime = time[cy, cx] + (s[ny][nx] == '#' ? t : 1);
                        if (nextTime < time[ny, nx]) {
                            time[ny, nx] = nextTime;
                            q.Enqueue(new Point(nx, ny));
                        }
                    }
                }
            }
            return time[gy, gx] <= T;
        };
        var ans = binarySearch((int)1e9 + 5,1, f);
        //ret
        WriteLine(ans);
    }
    struct Point{
        public int X, Y;
        public Point(int x, int y) {
            X = x; Y = y;
        }
    }
    int[] dx = new int[] { 1, 0, -1, 0 };
    int[] dy = new int[] { 0, 1, 0, -1 };
    int binarySearch(int ng, int ok, Func<int, bool> f) {
        while (Abs(ok - ng) > 1) {
            var mid = (ok + ng) / 2;
            if (f(mid)) ok = mid;
            else ng = mid;
        }
        return ok;
    }
    SimpleIO io = new SimpleIO();
    public static void Main(string[] args) => new Simple().Stream();
    private void Stream() {
        //var exStdIn = new System.IO.StreamReader("stdin.txt");
        //SetIn(exStdIn);
        Solve();
        io.Flush();
    }
}
class SimpleIO
{
    string[] _nextBuffer;
    int _bufferCnt;
    char[] cs = new char[] { ' ', '"', ',' };
    StreamWriter sw = new StreamWriter(OpenStandardOutput()) {
        AutoFlush = false
    };
    public SimpleIO() {
        _nextBuffer = new string[0];
        _bufferCnt = 0;
        SetOut(sw);
    }
    string Next() {
        if (_bufferCnt < _nextBuffer.Length)
            return _nextBuffer[_bufferCnt++];
        var st = ReadLine();
        while (st == "")
            st = ReadLine();
        if (st != null)
            _nextBuffer = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
        else
            st = "";
        _bufferCnt = 0;
        return _nextBuffer[_bufferCnt++];
    }
    public string String => Next();
    public char Char => char.Parse(String);
    public int Int => int.Parse(String);
    public long Long => long.Parse(String);
    public double Double => double.Parse(String);
    public void Flush() => Out.Flush();
}