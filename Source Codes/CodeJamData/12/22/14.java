import java.util.*;

public class B
{
	static int[] dr = {0, 1, 0, -1};
	static int[] dc = {1, 0, -1, 0};

	public static void main(String args[])
	{
		Scanner scan = new Scanner(System.in);
		final double EPS = 1e-14;

		int T = scan.nextInt();

		for(int ca=1;ca <= T;ca++)
		{
			int h = scan.nextInt();
			int m = scan.nextInt();
			int n = scan.nextInt();

			int[][] c = new int[m][n];
			int[][] f = new int[m][n];

			for(int i=0;i < m;i++)
			for(int j=0;j < n;j++)
				c[i][j] = scan.nextInt();

			for(int i=0;i < m;i++)
			for(int j=0;j < n;j++)
				f[i][j] = scan.nextInt();

			int[][][] d = new int[m][n][h+1];
			for(int i=0;i < m;i++)
			for(int j=0;j < n;j++)
				Arrays.fill(d[i][j], 999999999);

			PriorityQueue<State> q = new PriorityQueue<State>();
			q.offer(new State(0, 0, h, 0));
			d[0][0][h] = 0;

			int rtn = 999999999;

			while(!q.isEmpty())
			{
				State s = q.poll();
				int dist = d[s.r][s.c][s.h];
				if(s.d > dist) continue; //deprecated entry

				if(s.r == m-1 && s.c == n-1)
				{
					rtn = s.d;
					break;
				}

				//Wait for 0.1 secs?
				if(s.h > 0 && dist+1 < d[s.r][s.c][s.h-1])
				{
					q.offer(new State(s.r, s.c, s.h-1, dist+1));
					d[s.r][s.c][s.h-1] = dist+1;
				}

				//Move?
				for(int i=0;i < 4;i++)
				{
					int nr = s.r + dr[i];
					int nc = s.c + dc[i];

					if(nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
					if(c[s.r][s.c] - f[nr][nc] < 50) continue;
					if(c[nr][nc] - f[nr][nc] < 50) continue;
					if(c[nr][nc] - f[s.r][s.c] < 50) continue;
					if(c[nr][nc] - s.h < 50) continue;

					//Move for free?
					if(s.h == h)
					{
						if(dist < d[nr][nc][s.h])
						{
							q.offer(new State(nr, nc, s.h, dist));
							d[nr][nc][s.h] = dist;
						}
					}
					else if(s.h - f[s.r][s.c] >= 20) //Move fast!
					{
						int nh = Math.max(0, s.h-10);
						if(dist+10 < d[nr][nc][nh])
						{
							q.offer(new State(nr, nc, nh, dist+10));
							d[nr][nc][nh] = dist+10;
						}
					}
					else //Move slow...
					{
						int nh = Math.max(0, s.h-100);
						if(dist+100 < d[nr][nc][nh])
						{
							q.offer(new State(nr, nc, nh, dist+100));
							d[nr][nc][nh] = dist+100;
						}
					}
				}
			}

			//Find answer
			for(int i=0;i <= h;i++)
				rtn = Math.min(rtn, d[m-1][n-1][i]);
			
			System.out.println("Case #" + ca + ": " + (rtn/10.0));
		}
	}
}


class State implements Comparable<State>
{
	int r, c, h, d;
	public State(int ir, int ic, int ih, int id)
	{
		r = ir;
		c = ic;
		h = ih;
		d = id;
	}

	public int compareTo(State that)
	{
		return this.d - that.d;
	}
}