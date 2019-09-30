using System;
using System.Collections.Generic;

namespace AGC14
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            new MainClass().solve();
        }

        int INF = 123456789;

        Scanner cin;

        int h, w, k;
        int ans = 0;
        string[] r;//room
        int[,] log;
        List<Tuple<int,int>> can;
        int[] dir = { 0, 1, 0, -1, 0 };
		int[,] dis;
        void solve(){
            cin = new Scanner();
            can = new List<Tuple<int,int>>();
            h = cin.nextInt();
            w = cin.nextInt();
            k = cin.nextInt();
            r = new string[h];
			dis = new int[h, w];
            log = new int[h, w];

            int sx, sy;
            Queue<Tuple<int,int>> que = new Queue<Tuple<int,int>>();
            for (int i = 0; i < h;i++){
                r[i] = cin.next();
            }
            //first step
            for (int i = 0; i < h; i++)
                for (int j = 0; j < w; j++)
                    dis[i, j] = INF;
			for (int i = 0; i < h; i++)
				for (int j = 0; j < w; j++)
                    if(r[i][j]=='S'){
                        sy = i;
                        sx = j;
                        dis[sy, sx] = 0;
                        que.Enqueue(Tuple.Create(sy,sx));
                    }
            while(que.Count>0){
                Tuple<int, int> cur = que.Dequeue();
                int y = cur.Item1;
                int x = cur.Item2;
                can.Add(Tuple.Create(y, x));
                for (int i = 0; i < 4;i++){
                    int dy = y + dir[i];
                    int dx = x + dir[i + 1];
                    if(0<=dx&&dx<w&&0<=dy&&dy<h&&
                       dis[dy, dx] == INF&&r[dy][dx] != '#'){
						dis[dy, dx] = dis[y, x] + 1;
                        if(dis[dy,dx]<=k)
                            que.Enqueue(Tuple.Create(dy,dx));
                    }
                }
            }
            //n step
			int minY = h;
            int minX = w;
            int minXY = INF;
            int min = minXY;
            for (int i = 0; i < can.Count;i++){
                minY = Math.Min(can[i].Item2, w - 1 - can[i].Item2);
                minX = Math.Min(can[i].Item1, h - 1 - can[i].Item1);
                minXY = Math.Min(minY, minX);
                min = Math.Min(min, minXY);
            }
            if(min%k==0){
                ans = 1 + (min) / k;
            }else{
                ans = 2 + (min) / k;
            }
            Console.WriteLine(ans);
        }
    }
    class Scanner{
        string[] s;
        int i;
        char[] cs = new char[] { ' ' };
        public Scanner(){
            s = new string[0];
            i = 0;
        }
        public string next(){
            if (i < s.Length)
                return s[i++];
            string st = Console.ReadLine();
            while (st == "")
                st = Console.ReadLine();
            s = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
            i = 0;
            return s[i++];
        }
        public int nextInt(){
            return int.Parse(next());
        }

    }
}