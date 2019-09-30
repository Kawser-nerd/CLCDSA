import java.io.*;
import java.util.*;

public class Solution implements Runnable
{
	BufferedReader in;
	PrintWriter out;
	
	int n;
	
	int x, y;
	int dx, dy;
	int M = 6010;
	boolean[][] top;
	boolean[][] left;
	int[][] cleft;
	int[][] ctop;
	
	void moveLeft()
	{
		int t = dx;
		dx = -dy;
		dy = t;
	}
	void moveRight()
	{
		int t = dx;
		dx = dy;
		dy = -t;
	}
	void moveFront()
	{
		if (dx == 0)
		{
			if (dy == 1)
			{
				left[x][y] = true;
			}
			else
			{
				left[x][y - 1] = true;
			}
		}
		else if (dx == 1)
		{
			top[x][y] = true;
		}
		else
		{
			top[x - 1][y] = true;
		}
		x += dx;
		y += dy;
	}
	
	private void solve() throws Exception
	{
		int tests = Integer.parseInt(in.readLine());
		for (int test = 0; test < tests; test++)
		{
			System.err.println("test " + (test + 1));
			x = M / 2;
			y = M / 2;
			dy = 1;
			dx = 0;
			String[] t;
			t = in.readLine().split(" ");
			n = Integer.parseInt(t[0]);
			String ss = "";
			int k = 0;
			while (k < n)
			{
				t = in.readLine().split(" ");
				for (int i = 0; i < t.length; i += 2, k++)
				{
					String s = t[i];
					int l = Integer.parseInt(t[i + 1]);
					for (int j = 0; j < l; j++)
					{
						ss += s;
					}
				}
			}
			top = new boolean[M][M];
			left = new boolean[M][M];
			cleft = new int[M][M];
			ctop = new int[M][M];
			for (int i = 0; i < ss.length(); i++)
			{
				char c = ss.charAt(i);
				if (c == 'L') moveLeft();
				else if (c == 'R') moveRight();
				else moveFront();
			}
			for (int y = 0; y < M; y++)
			{
				int cur = 0;
				for (int x = 0; x < M; x++)
				{
					if (left[x][y]) cur++;
					cleft[x][y] = cur;
				}
			}
			for (int x = 0; x < M; x++)
			{
				int cur = 0;
				for (int y = 0; y < M; y++)
				{
					if (top[x][y]) cur++;
					ctop[x][y] = cur;
				}
			}
			int res = 0;
			for (int y = 0; y < M; y++)
			{
				for (int x = 0; x < M; x++)
				{
					int ct = ctop[x][y];
					int cb = ctop[x][M - 1] - ct;
					int cl = cleft[x][y];
					int cr = cleft[M - 1][y] - cl;
					if (ct % 2 != 0 || cl % 2 != 0) continue;
					if ((cl > 0 && cr > 0) || (ct > 0 && cb > 0)) res++;
				}
			}
			out.printf("Case #%d: %d\r\n", test + 1, res);
		}
	}

	public void run()
	{
		try
		{
			solve();
		}
		catch (Exception ex)
		{
			throw new RuntimeException(ex);
		}
		finally
		{
			out.close();
		}
	}
	
	public Solution() throws IOException
	{
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
	}

	public static void main(String[] args) throws IOException
	{
		Locale.setDefault(Locale.US);
		new Thread(new Solution()).start();
	}
}
