import java.util.*;
import java.io.*;
import java.math.*;

public class B
{
	PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	Scanner in = new Scanner(new InputStreamReader(System.in));
	private String fileName = "B-small-attempt1";

	private void solution() throws IOException
	{
		in = new Scanner(new FileReader(fileName + ".in"));
		out = new PrintWriter(fileName + ".out");
		int test = in.nextInt();
		for (int cas = 1; cas <= test; ++cas)
		{
			out.printf("Case #%d: %s\n", cas, solve());
		}
		out.flush();
	}

	private class State implements Comparable<State>
	{
		int x, y, cost, mask, nextmask;

		public State(int x, int y, int cost, int mask, int nextmask)
		{
			this.x = x;
			this.y = y;
			this.cost = cost;
			this.mask = mask;
			this.nextmask = nextmask;
		}

		@Override
		public int compareTo(State other)
		{
			return cost - other.cost;
		}
	}

	private String solve() throws IOException
	{
		int height = in.nextInt();
		int width = in.nextInt();
		int fail = in.nextInt();
		char[][] grid = new char[height][];
		for (int i = 0; i < grid.length; ++i)
			grid[i] = in.next().toCharArray();
		PriorityQueue<State> q = new PriorityQueue<State>();
		int[][][][] res = new int[height][width][1 << width][1 << width];
		for (int i = 0; i < res.length; ++i)
			for (int j = 0; j < res[i].length; ++j)
				for (int k = 0; k < res[i][j].length; ++k)
					Arrays.fill(res[i][j][k], Integer.MAX_VALUE);
		q.add(new State(0, 0, 0, getMask(grid[0]), getMask(grid[1])));
		while (!q.isEmpty())
		{
			State cur = q.poll();
			if (res[cur.x][cur.y][cur.mask][cur.nextmask] != Integer.MAX_VALUE)
				continue;
			else
				res[cur.x][cur.y][cur.mask][cur.nextmask] = cur.cost;
			if (cur.x == height - 1)
				return "Yes " + cur.cost;
			for (int i = 0; i < width; ++i)
			{
				if (canMove(cur.mask, cur.nextmask, cur.y, i))
				{
					for (int dy = -1; dy <= 1; dy += 2)
					{
						int ny = i + dy;
						if (ny >= 0 && ny < width)
						{
							if (((cur.mask >> ny) & 1) == 0)
							{
								if (((cur.nextmask >> ny) & 1) != 0)
								{
									int nmask = cur.nextmask ^ (1 << ny);
									if (res[cur.x][i][cur.mask][nmask] == Integer.MAX_VALUE)
										q.add(new State(cur.x, i, cur.cost + 1, cur.mask, nmask));
								}
								else
								{
									// int nmask = 0;
									// if (cur.x + 2 < height)
									// nmask = getMask(grid[cur.x + 2]);
									int nx = failDown(cur.x + 1, ny, cur.mask, cur.nextmask, grid);
									if (nx - cur.x <= fail)
									{
										int mask = getMask(grid[nx]);
										int nextmask = 0;
										if (nx - cur.x == 1)
											mask = cur.nextmask;
										if (nx + 1 != grid.length)
											nextmask = getMask(grid[nx + 1]);
										if (res[nx][ny][mask][nextmask] == Integer.MAX_VALUE)
											q.add(new State(nx, ny, cur.cost, mask, nextmask));
									}
								}
							}
						}
					}
				}
			}
		}
		return "No";
	}

	private int failDown(int x, int y, int mask, int nextmask, char[][] grid)
	{
		while (x + 1 < grid.length)
		{
			if (grid[x + 1][y] == '#')
				return x;
			++x;
		}
		return x;
	}

	private int getMask(char[] arr)
	{
		int mask = 0;
		for (int i = 0; i < arr.length; ++i)
			if (arr[i] == '#')
				mask |= 1 << i;
		return mask;
	}

	private boolean canMove(int mask, int nextmask, int left, int right)
	{
		if (left > right)
		{
			int tmp = left;
			left = right;
			right = tmp;
		}
		for (int i = left; i <= right; ++i)
		{
			if (((mask >> i) & 1) != 0)
				return false;
			if (((nextmask >> i) & 1) == 0)
				return false;
		}
		return true;
	}

	private class Scanner
	{
		private BufferedReader reader;
		private StringTokenizer tokenizer;

		public Scanner(Reader in)
		{
			reader = new BufferedReader(in);
			tokenizer = new StringTokenizer("");
		}

		public boolean hasNext() throws IOException
		{
			while (!tokenizer.hasMoreTokens())
			{
				String tmp = reader.readLine();
				if (tmp == null)
					return false;
				tokenizer = new StringTokenizer(tmp);
			}
			return true;
		}

		public String next() throws IOException
		{
			hasNext();
			return tokenizer.nextToken();
		}

		public int nextInt() throws IOException
		{
			return Integer.parseInt(next());
		}

		public long nextLong() throws IOException
		{
			return Long.parseLong(next());
		}

		public double nextDouble() throws IOException
		{
			return Double.parseDouble(next());
		}

		public String nextLine() throws IOException
		{
			tokenizer = new StringTokenizer("");
			return reader.readLine();
		}
	}

	public static void main(String[] args) throws IOException
	{
		new B().solution();
	}
}
