import java.util.*;
public class cross
{
	public static void main(String[] args) throws Throwable
	{
		Scanner in = new Scanner(System.in);
		int TT = in.nextInt();
		for(int tt = 1; tt <= TT; tt++)
		{
			int N = in.nextInt(), M = in.nextInt();
			long[][] S = new long[N][M];
			long[][] W = new long[N][M];
			long[][] T = new long[N][M];
			long[][][] map = new long[N][M][4];
			for(int i = 0; i < N; i++)
				for(int j = 0; j < M; j++)
				{
					S[i][j] = in.nextInt();
					W[i][j] = in.nextInt();
					T[i][j] = in.nextInt();
					for(int k = 0; k < 4; k++)
						map[i][j][k] = -1;
				}
			PriorityQueue<QUAD> pq = new PriorityQueue<QUAD>();
			pq.add(new QUAD(N-1, 0, 0, 0));
			while(!pq.isEmpty())
			{
				QUAD n = pq.remove();
				if(map[n.x][n.y][n.z] == -1)
				{
					map[n.x][n.y][n.z] = n.w;
					QUAD p;
					long seg = (((n.w-T[n.x][n.y])%(S[n.x][n.y]+W[n.x][n.y])) + (S[n.x][n.y]+W[n.x][n.y]))%(S[n.x][n.y]+W[n.x][n.y]);
					//cross vert
					p = new QUAD();
					p.x = n.x;
					p.y = n.y;
					p.z = (n.z^1);
					if(seg < S[n.x][n.y])
						p.w = n.w+1;
					else
						p.w = n.w+S[n.x][n.y]+W[n.x][n.y]-seg+1;
					pq.add(p);
					//cross horiz
					p = new QUAD();
					p.x = n.x;
					p.y = n.y;
					p.z = (n.z^2);
					if(seg >= S[n.x][n.y])
						p.w = n.w+1;
					else
						p.w = n.w+S[n.x][n.y]-seg+1;
					pq.add(p);
					//walk vert
					p = new QUAD();
					if(n.z == 0 || n.z == 2)
					{
						p.x = n.x+1;
						p.y = n.y;
						p.z = n.z+1;
						p.w = n.w+2;
					}
					else
					{
						p.x = n.x-1;
						p.y = n.y;
						p.z = n.z-1;
						p.w = n.w+2;
					}
					if(p.x >= 0 && p.x < N && p.y >= 0 && p.y < M)
						pq.add(p);
					//walk horiz
					p = new QUAD();
					if(n.z == 0 || n.z == 1)
					{
						p.x = n.x;
						p.y = n.y-1;
						p.z = n.z+2;
						p.w = n.w+2;
					}
					else
					{
						p.x = n.x;
						p.y = n.y+1;
						p.z = n.z-2;
						p.w = n.w+2;
					}
					if(p.x >= 0 && p.x < N && p.y >= 0 && p.y < M)
						pq.add(p);
				}
			}
			System.out.println("Case #"+tt+": "+map[0][M-1][3]);
		}
	}
}
class QUAD implements Comparable<QUAD>
{
	public int x,y,z;
	public long w;
	public QUAD()
	{
		w=x=y=z=-1;
	}
	public QUAD(int a, int b, int c, long d)
	{
		x=a;y=b;z=c;w=d;
	}
	public int compareTo(QUAD o)
	{
		if(w-o.w > 0)
			return 1;
		else if(w-o.w == 0)
			return 0;
		else
			return -1;
	}
}

// 0 = SW; 1 = NW; 2 = SE; 3 = NE