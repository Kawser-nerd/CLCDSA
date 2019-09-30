using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
namespace ABC020
{
    class MainClass
    {
        public static void Main(string[] args){
            new MainClass().solve();
        }
        long INF = long.MaxValue;
        Scanner cin;

        int H, W, T;
        string[] s;

        int[] dir = { 0, 1, 0, -1, 0 };
        int sx = 0, sy = 0, gx = 0, gy = 0;
      
        void solve(){
            cin = new Scanner();

            H = cin.nextInt();
            W = cin.nextInt();
            T = cin.nextInt();

            s = new string[H];

            for (int i = 0; i < H; i++)
                s[i] = cin.next();
            

            for (int i = 0; i < H; i++)
                for (int j = 0; j < W; j++){
                    if (s[i][j] == 'S'){
                        sy = i; sx = j;
                    }else if (s[i][j] == 'G'){
                        gy = i; gx = j;
                    }
                }

            int l = 1, h = T;

            while(h-l!=1){
                int m = (h + l) / 2;
                if (isReachable(m))
                    l = m;
                else
                    h = m;
            }

            Console.WriteLine(l);
        }

        bool isReachable(int x){
            long[,] time = new long[H, W];
            for (int i = 0; i < H; i++)
                for (int j = 0; j < W; j++)
                    time[i, j] = INF;

            time[sy, sx] = 0;

            Queue<Tuple<int, int>> que = new Queue<Tuple<int, int>>();
            que.Enqueue(Tuple.Create(sy, sx));

            while (que.Count() > 0){
                Tuple<int, int> now = que.Dequeue();
                int cy = now.Item1;
                int cx = now.Item2;

                for (int i = 0; i < 4; i++){
                    int ny = cy + dir[i];
                    int nx = cx + dir[i + 1];
                    if (0 <= ny && ny < H && 0 <= nx && nx < W){
                        if (s[ny][nx] == '.' || s[ny][nx] == 'G'){
                            if (time[ny, nx] > time[cy, cx] + 1){
                                time[ny, nx] = time[cy, cx] + 1;
                                que.Enqueue(Tuple.Create(ny, nx));
                            }
                        }else{
                            if (time[ny, nx] > time[cy, cx] + 1){
                                time[ny, nx] = time[cy, cx] + x;
                                que.Enqueue(Tuple.Create(ny, nx));
                            }
                        }
                    }
                }
            }
			return time[gy, gx] <= T;
        }

        class Scanner
        {
            string[] nextBuffer;
            int BufferCnt;
            char[] cs = new char[] { ' ' };
            public Scanner()
            {
                nextBuffer = new string[0];
                BufferCnt = 0;
            }
            public string next()
            {
                if (BufferCnt < nextBuffer.Length)
                    return nextBuffer[BufferCnt++];
                string st = Console.ReadLine();
                while (st == "")
                    st = Console.ReadLine();
                nextBuffer = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
                BufferCnt = 0;
                return nextBuffer[BufferCnt++];
            }
            public int nextInt()
            {
                return int.Parse(next());
            }
            public long nextLong()
            {
                return long.Parse(next());
            }
            public double nextDouble()
            {
                return double.Parse(next());
            }
        }
    }
}