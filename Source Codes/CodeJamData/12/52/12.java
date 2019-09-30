import java.util.*;
import java.io.*;
import java.math.*;
import java.awt.*;

public class B
{
	static int[] dr = {1, 1, 0, -1, -1, 0};
	static int[] dc = {0, 1, 1, 0, -1, -1};

	public static void main(String args[])
	{
		Scanner scan = new Scanner(System.in);
		int T = scan.nextInt();

		for(int ca=1;ca <= T;ca++)
		{
			int s = scan.nextInt();
			int n = s * 2 - 1;
			int m = scan.nextInt();
			boolean[][] a = new boolean[n][n];

			boolean br, fo, ri;
			br = fo = ri = false;
			int mo = 0;

			while(m --> 0)
			{
				int r = scan.nextInt()-1;
				int c = scan.nextInt()-1;
				a[r][c] = true;
				
				

				//BFS
				Queue<Point> q = new LinkedList<Point>();
				boolean[][] b = new boolean[n][n];
				q.offer(new Point(r, c));
				b[r][c] = true;

				boolean[] corn = new boolean[6];
				boolean[] edge = new boolean[6];

				boolean[] tedge = new boolean[6];
				if(r == 0) tedge[0] = true;
				if(c - r == s-1) tedge[1] = true;
				if(c == n-1) tedge[2] = true;
				if(r == n-1) tedge[3] = true;
				if(r - c == s-1) tedge[4] = true;
				if(c == 0) tedge[5] = true;

				boolean newcorn = false;

				for(int j=0;j < 6;j++)
				{
					if(tedge[j] && tedge[(j+5)%6]) {corn[j] = true; newcorn = true;}
				}
				
				if(!newcorn)
							for(int j=0;j < 6;j++)
								edge[j] |= tedge[j];

				while(!q.isEmpty())
				{
					Point p = q.poll();
					for(int i=0;i < 6;i++)
					{
						int nr = p.x + dr[i];
						int nc = p.y + dc[i];

						if(nr < 0 || nr >= n || nc < 0 || nc >= n || b[nr][nc] || !a[nr][nc]) continue;

						b[nr][nc] = true;
						//TODO: check edges corners
						q.offer(new Point(nr,nc));

						tedge = new boolean[6];
						if(nr == 0) tedge[0] = true;
						if(nc - nr == s-1) tedge[1] = true;
						if(nc == n-1) tedge[2] = true;
						if(nr == n-1) tedge[3] = true;
						if(nr - nc == s-1) tedge[4] = true;
						if(nc == 0) tedge[5] = true;

						newcorn = false;

						for(int j=0;j < 6;j++)
						{
							if(tedge[j] && tedge[(j+5)%6])
							{
								corn[j] = true;
								newcorn = true;
							}

							//System.out.println(edge[j] + " " + corn[j]);
						}

						if(!newcorn)
							for(int j=0;j < 6;j++)
								edge[j] |= tedge[j];
					}
				}

				//Check for rings
				b = new boolean[n][n];
				

				for(int i=0;i < n;i++)
				for(int j=0;j < n;j++)
				{
					if(a[i][j]) continue;
					if(b[i][j]) continue;
					q = new LinkedList<Point>();

					q.offer(new Point(i, j));
					b[i][j] = true;
					boolean leak = false;

					if(i == 0) leak = true;
					if(j - i == s-1) leak = true;
					if(j == n-1) leak = true;
					if(i == n-1) leak = true;
					if(i - j == s-1) leak = true;
					if(j == 0) leak = true;

					while(!q.isEmpty())
					{
						Point p = q.poll();
						for(int k=0;k < 6;k++)
						{
							int nr = p.x + dr[k];
							int nc = p.y + dc[k];

							if(nr < 0 || nr >= n || nc < 0 || nc >= n || b[nr][nc] || a[nr][nc]) continue;

							b[nr][nc] = true;
							q.offer(new Point(nr,nc));

							if(nr == 0) leak = true;
							if(nc - nr == s-1) leak = true;
							if(nc == n-1) leak = true;
							if(nr == n-1) leak = true;
							if(nr - nc == s-1) leak = true;
							if(nc == 0) leak = true;
						}
					}

					if(!leak) ri = true;

				}

				int ec = 0;
				int cc = 0;
				for(int i=0;i < 6;i++)
				{
					if(edge[i]) ec++;
					if(corn[i]) cc++;

					
				}

				if(ec >= 3) fo = true;
				if(cc >= 2) br = true;

				

				mo++;				

				if(ri || fo || br)
					break;
				
			}

			//What to print?
			System.out.print("Case #" + ca + ":");
			boolean first = true;

			if(br)
			{
				System.out.print(" bridge");
				first = false;
			}
			if(fo)
			{
				if(first) System.out.print(" fork");
				else System.out.print("-fork");
				first = false;
			}
			if(ri)
			{
				if(first) System.out.print(" ring");
				else System.out.print("-ring");
				first = false;
			}

			if(first) System.out.println(" none");
			else System.out.println(" in move " + mo);

			//Cleanup
			while(m --> 0)
			{
				scan.nextInt();
				scan.nextInt();
			}

			
		}
	}
}