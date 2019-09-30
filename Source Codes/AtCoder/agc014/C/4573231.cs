using System;
using System.Collections.Generic;

public class CSharp{
    public static void Main(){
        Kyopuro chokudai = new Kyopuro();
	    chokudai.AtCoder();
	}
}

public class Kyopuro{
    int h, w, k;
    int sx, sy;
    bool[][] g;
    int close;
    List<List<int>> list;
    
    public void AtCoder(){
        string[] s;
        s = Console.ReadLine().Split(' ');
        h = int.Parse(s[0]);
        w = int.Parse(s[1]);
        k = int.Parse(s[2]);
        g = new bool[h][];
        int tmpx, tmpy;
        string t;
        for(int i=0; i<h; i++){
            g[i] = new bool[w];
            t = Console.ReadLine();
            for(int j=0; j<w; j++){
                if(t[j] != '#') g[i][j] = true;
                if(t[j] == 'S'){
                    sx = i;
                    sy = j;
                    tmpx = i;
                    tmpy = j;
                    if(h - 1 - i < i) tmpx = h - 1 - i;
                    if(w - 1 - j < j) tmpy = w - 1 - j;
                    close = tmpx;
                    if(tmpy < tmpx) close = tmpy;
                }
            }
        }
        list = new List<List<int>>();
        list.Add(new List<int>());
        list[0].Add(sy + sx * w);
        Bfs(0);
        if(close % k == 0) Console.WriteLine(close / k + 1);
        else Console.WriteLine(close / k + 2);
    }
    
    void Bfs(int z){
        if(z>k) return;
        if(close < 1) return;
        list.Add(new List<int>());
        foreach(int r in list[z]){
            int x = r / w;
            int y = r % w;
            g[x][y] = false;
            if(x == 0 || x == h - 1 || y == 0 || y == w - 1){
                close = 0;
                return;
            }
            int tmpx = x;
            int tmpy = y;
            if(h - 1 - x < x) tmpx = h - 1 - x;
            if(w - 1 - y < y) tmpy = w - 1 - y;
            if(tmpx < close) close = tmpx;
            if(tmpy < close) close = tmpy;
            
            if(g[x-1][y]) list[z+1].Add(y + w * (x-1));
            if(g[x+1][y]) list[z+1].Add(y + w * (x+1));
            if(g[x][y-1]) list[z+1].Add((y-1) + w * x);
            if(g[x][y+1]) list[z+1].Add((y+1) + w * x);
            g[x-1][y] = false;
            g[x+1][y] = false;
            g[x][y-1] = false;
            g[x][y+1] = false;
        }
        if(list[z+1].Count>0) Bfs(z+1);
    }
    
    public static void DebugWL(object x){ System.Diagnostics.Debug.WriteLine(x); }
}