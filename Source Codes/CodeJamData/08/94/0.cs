using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

public class ProblemD
{
	static void Main(string[] args)
	{
//		TextReader sr = new StreamReader(@"c:\temp\d.in");
		//		TextReader sr = Console.In;
//				TextReader sr = new StreamReader(@"c:\temp\d-small-attempt0.in");
				TextReader sr = new StreamReader(@"c:\temp\d-large.in");
				TextWriter sw = new StreamWriter(@"c:\temp\d.out");
//		TextWriter sw = Console.Out;

		int N = int.Parse(sr.ReadLine());
		for (int caseNo = 1; caseNo <= N; caseNo++)
		{
			sw.Write("Case #" + caseNo + ": ");
			Solve(sr, sw);
		}
		sw.Close();
	}

    private static char[,] map;

	private static void Solve(TextReader sr, TextWriter sw)
	{
	    string[] split = sr.ReadLine().Split(' ');
	    int ysize = int.Parse(split[0]);
	    int xsize = int.Parse(split[1]);

	    map = new char[ysize, xsize];
	    for (int i = 0; i < ysize; i++)
	    {
	        string s = sr.ReadLine();
	        for (int j = 0; j < xsize; j++)
	        {
	            map[i, j] = s[j];
	        }
	    }

	    List<int> startX = new List<int>(), startY = new List<int>();
	    startX.Add(0);
	    startY.Add(0);
	    map[0, 0] = '#';
        bool[,] done = new bool[ysize, xsize];
        done[0, 0] = true;

	    int cx, cy, sum = 0;
	    int[,] distFromBase = simpleBFS(map, startX, startY, "#T", false, out cx, out cy);
        while (cx >= 0)
        {
            startX.Add(cx);
            startY.Add(cy);
            map[cy, cx] = '#';

            int curDist = distFromBase[cy, cx];
            while (curDist > 0)
            {
                if (!done[cy,cx])
                    sum += curDist;
                done[cy, cx] = true;
                for (int d = 0; d < 4; d++)
                {
                    int nx = cx + dx[d], ny = cy + dy[d];
                    if (nx >= 0 && nx < xsize && ny >= 0 && ny < ysize && distFromBase[ny, nx] == curDist - 1)
                    {
                        cx = nx;
                        cy = ny;
                        curDist--;
                        break;
                    }
                }
            }
            
            distFromBase = simpleBFS(map, startX, startY, "#T", false, out cx, out cy);
        }

	    for (int y = 0; y < ysize; y++)
	    {
	        for (int x = 0; x < xsize; x++)
	        {
	            if (!done[y,x] && map[y,x] != '.')
	            {
	                int cost = distFromBase[y, x];
//                    Console.WriteLine("x = " + x + ", y = " + y + ", cost = " + cost);
	                sum += cost;
	                done[y, x] = true;
	            }
	        }
	    }

	    sw.WriteLine(sum);
	}

    static int[] dx = { 0, 1, 0, -1, 1, 1, -1, -1 }, dy = { 1, 0, -1, 0, -1, 1, -1, 1 };

    public static int[,] simpleBFS(char[,] map, List<int> startX, List<int> startY, string allowedSquares, bool allowDiagonal, out int cx, out int cy)
    {
        cx = -1;
        cy = -1;
        int xSize = map.GetLength(1), ySize = map.GetLength(0), maxDir = allowDiagonal ? 8 : 4;
        int[,] dist = new int[ySize, xSize];
        for (int y = 0; y < ySize; y++) for (int x = 0; x < xSize; x++) dist[y, x] = -1;
        Queue<int> q = new Queue<int>();
        for (int i = 0; i < startX.Count; i++)
        {
            q.Enqueue(startY[i] * xSize + startX[i]);
            dist[startY[i], startX[i]] = 0;
        }
        
        while (q.Count > 0)
        {
            int e = q.Dequeue();
            int curX = e % xSize, curY = e / xSize;
            for (int d = 0; d < maxDir; d++)
            {
                int nx = curX + dx[d], ny = curY + dy[d];
                if (nx >= 0 && ny >= 0 && nx < xSize && ny < ySize &&
                    allowedSquares.IndexOf(map[ny,nx]) >= 0 && dist[ny, nx] < 0)
                {
                    dist[ny, nx] = dist[curY, curX] + 1;
                    q.Enqueue(ny * xSize + nx);
                    if (map[ny,nx] == 'T')
                    {
                        cx = nx;
                        cy = ny;
                        return dist;
                    }
                }
            }
        }
        return dist;
    }
}