import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Locale;

// 1.6
public class A
{
	static final int THREADS = 1;

	static final String NAME = "a-large";

	StringBuilder out;

	int w, h;

	int[][] walls;

	int[] start;

	int[] finish;

	int boxes;

	public int code(int x, int y)
	{
		return x + y * w;
	}

	public int getX(int code)
	{
		return code % w;
	}

	public int getY(int code)
	{
		return code / w;
	}

	public void readData() throws Exception
	{
		h = Integer.parseInt(readWord());
		w = Integer.parseInt(readWord());
		walls = new int[w][h];
		List<Integer> startPos = new ArrayList<Integer>();
		List<Integer> finishPos = new ArrayList<Integer>();
		for (int j = 0; j < h; j++)
		{
			String s = readWord();
			for (int i = 0; i < w; i++)
			{
				char c = s.charAt(i);
				if (c == '#')
				{
					walls[i][j] = 1;
					continue;
				}
				if (c == 'o' || c == 'w')
				{
					startPos.add(code(i, j));
				}
				if (c == 'x' || c == 'w')
				{
					finishPos.add(code(i, j));
				}
			}
		}
		assert startPos.size() == finishPos.size();
		boxes = startPos.size();
		start = new int[startPos.size()];
		for (int i = 0; i < startPos.size(); i++)
		{
			start[i] = startPos.get(i);
		}
		finish = new int[finishPos.size()];
		for (int i = 0; i < finishPos.size(); i++)
		{
			finish[i] = finishPos.get(i);
		}
	}

	static class BoxConfig
	{
		int[] boxes;

		boolean isConnected;

		public BoxConfig(int[] boxes, boolean isConnected)
		{
			this.boxes = boxes.clone();
			this.isConnected = isConnected;
			Arrays.sort(this.boxes);
		}

		public boolean isFree(int code)
		{
			for (int i = 0; i < boxes.length; i++)
			{
				if (boxes[i] == code)
				{
					return false;
				}
			}
			return true;
		}

		@Override
		public int hashCode()
		{
			final int prime = 31;
			int result = 1;
			result = prime * result + Arrays.hashCode(boxes);
			return result;
		}

		@Override
		public boolean equals(Object obj)
		{
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			BoxConfig other = (BoxConfig) obj;
			if (!Arrays.equals(boxes, other.boxes))
				return false;
			return true;
		}

	}

	final static int[] dx = new int[] { -1, 1, 0, 0 };

	final static int[] dy = new int[] { 0, 0, -1, 1 };

	int[][] matrix;

	int[] wallArray;

	public void calcMatrix()
	{
		matrix = new int[w * h][4];
		wallArray = new int[w * h];
		for (int i = 0; i < w; i++)
		{
			for (int j = 0; j < h; j++)
			{
				int c = code(i, j);
				wallArray[c] = walls[i][j];
				for (int dir = 0; dir < 4; dir++)
				{
					int ii = i + dx[dir];
					int jj = j + dy[dir];
					int c1 = -1;
					if (ii >= 0 && ii < w && jj >= 0 && jj < h && walls[ii][jj] == 0)
					{
						c1 = code(ii, jj);
					}
					matrix[c][dir] = c1;
				}
			}
		}
	}

	private boolean hasEdge(int v1, int v2)
	{
		for (int dir = 0; dir < 4; dir++)
		{
			if (matrix[v1][dir] == v2)
			{
				return true;
			}
		}
		return false;
	}

	public boolean isConnected(int[] pos)
	{
		int n = pos.length;
		boolean[] flags = new boolean[n];
		int[] list = new int[n];
		list[0] = 0;
		flags[0] = true;
		int left = 0;
		int right = 1;
		while (right > left)
		{
			int cur = pos[list[left]];
			left++;
			for (int j = 0; j < n; j++)
			{
				if (!flags[j] && hasEdge(cur, pos[j]))
				{
					list[right] = j;
					right++;
					flags[j] = true;
				}
			}
		}
		return right == n;
	}

	public void solve()
	{
		calcMatrix();
		HashSet<BoxConfig> all = new HashSet<BoxConfig> ();
		HashSet<BoxConfig> cur = new HashSet<BoxConfig>();
		HashSet<BoxConfig> next = new HashSet<BoxConfig>();
		BoxConfig startPos=new BoxConfig(start,true);
		cur.add(startPos);
		all.add(startPos);
		BoxConfig finPos = new BoxConfig(finish, true);
		int ans = 0;
		while (cur.size() > 0)
		{
			for (BoxConfig c : cur)
			{
				if (c.equals(finPos))
				{
					out.append(ans + "\n");
					return;
				}
				boolean fconnected = c.isConnected;
				int[] boxs = c.boxes;
				for (int i = 0; i < boxes; i++)
				{
					int box = boxs[i];
					for (int dir = 0; dir < 4; dir+=2)
					{
						int m1=matrix[box][dir+1];
						int m2=matrix[box][dir];
						if (m1==-1 || m2==-1)
						{
							continue;
						}
						if (!c.isFree(m1) || !c.isFree(m2))
						{
							continue;
						}
						boxs[i]=m1;
						BoxConfig nextBox=new BoxConfig(boxs,isConnected(boxs));
						if ((nextBox.isConnected || fconnected) && !all.contains(nextBox))
						{
							all.add(nextBox);
							next.add(nextBox);
						}
						boxs[i] = m2;
						nextBox = new BoxConfig(boxs, isConnected(boxs));
						if ((nextBox.isConnected || fconnected) && !all.contains(nextBox))
						{
							all.add(nextBox);
							next.add(nextBox);
						}
						boxs[i] = box;
					}
				}
			}
			cur = next;
			next = new HashSet<BoxConfig>();
			ans++;
		}
		out.append("-1\n");
	}

	static String readWord() throws Exception
	{
		StringBuilder b = new StringBuilder();
		int c;
		while (true)
		{
			c = Common.stdin.read();
			if (c < 0)
			{
				return "";
			}
			if (c > 32)
			{
				break;
			}
		}
		while (true)
		{
			b.append((char) c);
			c = Common.stdin.read();
			if (c <= 32)
			{
				break;
			}
		}
		return b.toString();
	}

	static String readLine() throws Exception
	{
		return Common.stdin.readLine();
	}

	static class Common
	{
		static BufferedReader stdin;

		static BufferedWriter stdout;

		static int tests;

		static int test;

		static String[] answers;

		public static void startThreads()
		{
			try
			{
				stdin = new BufferedReader(new FileReader(NAME + ".in"));
				stdout = new BufferedWriter(new FileWriter(NAME + ".out"));
				tests = Integer.parseInt(readLine().trim());
				answers = new String[tests];
				test = 0;
				Thread[] threads = new Thread[THREADS];
				for (int i = 0; i < threads.length; i++)
				{
					final A inst = new A();
					threads[i] = new Thread(new Runnable()
					{
						public void run()
						{
							while (true)
							{
								inst.out = new StringBuilder();
								int ltest = 0;
								synchronized (stdin)
								{
									ltest = test;
									test++;
									if (ltest >= tests)
									{
										return;
									}
									try
									{
										inst.readData();
									}
									catch (Throwable e)
									{
										e.printStackTrace();
									}
								}
								try
								{
									inst.solve();
								}
								catch (Throwable e)
								{
									e.printStackTrace();
								}
								synchronized (answers)
								{
									answers[ltest] = inst.out.toString();
								}
							}
						}
					});
					threads[i].start();
				}
				for (int i = 0; i < threads.length; i++)
				{
					threads[i].join();
				}
				for (int test = 1; test <= tests; test++)
				{
					stdout.write("Case #" + test + ": " + answers[test - 1]);
				}
				stdout.close();
				stdin.close();
			}
			catch (Exception e)
			{
				e.printStackTrace();
			}
		}
	}

	public static void main(String[] args)
	{
		try
		{
			Locale.setDefault(Locale.US);
			Common.startThreads();
		}
		catch (Throwable e)
		{
			e.printStackTrace();
		}
	}
}
