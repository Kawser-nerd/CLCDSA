import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Locale;
import java.util.Set;

// 1.6
public class C implements Runnable
{
	static final String NAME = "c-large";

	static final int SHIFT = 600;

	char[][] field;

	int w;

	int q;

	int[] req;

	int maxReq;

	String[][][] table;

	String[] answers;

	int remain;

	static class DPoint
	{
		int x;

		int y;

		int req;

		public DPoint(int x, int y, int req)
		{
			this.x = x;
			this.y = y;
			this.req = req;
		}

		@Override
		public int hashCode()
		{
			final int prime = 31;
			int result = 1;
			result = prime * result + req;
			result = prime * result + x;
			result = prime * result + y;
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
			DPoint other = (DPoint) obj;
			if (req != other.req)
				return false;
			if (x != other.x)
				return false;
			if (y != other.y)
				return false;
			return true;
		}

	}

	public boolean better(String s1, String s2)
	{
		if (s2.length() < s1.length())
		{
			return true;
		}
		if (s2.length() > s1.length())
		{
			return false;
		}
		return s2.compareTo(s1) < 0;
	}

	public void add(int x, int y, int req, String s, Set<DPoint> points)
	{
		if (req >= maxReq + 1 + 2 * SHIFT)
		{
			return;
		}
		if (req < 0)
		{
			System.out.println("bad?");
			return;
		}
		if (table[x][y][req] != null && !better(table[x][y][req], s))
		{
			return;
		}
		table[x][y][req] = s;
		points.add(new DPoint(x, y, req));
		if (req >= SHIFT && req < maxReq + 1 + SHIFT)
		{
			if (answers[req - SHIFT] == null)
			{
				answers[req - SHIFT] = s;
				remain--;
			}
			else
			{
				if (better(answers[req - SHIFT], s))
				{
					answers[req - SHIFT] = s;
				}
			}
		}
	}

	final static int[] dx = new int[] { -1, 1, 0, 0 };

	final static int[] dy = new int[] { 0, 0, -1, 1 };

	public void fillTable()
	{
		answers = new String[maxReq + 1];
		Arrays.fill(answers, "");
		remain = 0;
		for (int i = 0; i < req.length; i++)
		{
			if (answers[req[i]] != null)
			{
				answers[req[i]] = null;
				remain++;
			}
		}
		table = new String[w][w][maxReq + 1 + 2 * SHIFT];
		Set<DPoint> start = new HashSet<DPoint>();
		for (int i = 0; i < w; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (Character.isDigit(field[i][j]))
				{
					add(i, j, field[i][j] - '0' + SHIFT, field[i][j] + "", start);
				}
			}
		}
		while (remain > 0)
		{
			Set<DPoint> next = new HashSet<DPoint>();
			for (DPoint point : start)
			{
				String s = table[point.x][point.y][point.req];
				for (int dir = 0; dir < 4; dir++)
				{
					int xx = point.x + dx[dir];
					int yy = point.y + dy[dir];
					if (xx < 0 || xx >= w || yy < 0 || yy >= w)
					{
						continue;
					}
					char sign = field[xx][yy];
					for (int dir1 = 0; dir1 < 4; dir1++)
					{
						int xxx = xx + dx[dir1];
						int yyy = yy + dy[dir1];
						if (xxx < 0 || xxx >= w || yyy < 0 || yyy >= w)
						{
							continue;
						}
						int v = field[xxx][yyy] - '0';
						int req = point.req + (sign == '+' ? v : -v);
						add(xxx, yyy, req, s + sign + field[xxx][yyy], next);
					}
				}
			}
			start = next;
		}
	}

	public void solve() throws Exception
	{
		int tests = Integer.parseInt(readWord());
		for (int test = 1; test <= tests; test++)
		{
			stdout.write("Case #" + test + ":\n");
			w = Integer.parseInt(readWord());
			q = Integer.parseInt(readWord());
			field = new char[w][w];
			for (int i = 0; i < w; i++)
			{
				String s = readWord();
				for (int j = 0; j < w; j++)
				{
					field[i][j] = s.charAt(j);
				}
			}
			req = new int[q];
			maxReq = 0;
			for (int i = 0; i < q; i++)
			{
				req[i] = Integer.parseInt(readWord());
				maxReq = Math.max(maxReq, req[i]);
			}
			fillTable();
			for (int i = 0; i < q; i++)
			{
				stdout.write(answers[req[i]] + "\n");
			}
			System.out.println(test);
		}
	}

	static BufferedReader stdin;

	static BufferedWriter stdout;

	String readWord() throws Exception
	{
		StringBuilder b = new StringBuilder();
		int c;
		while (true)
		{
			c = stdin.read();
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
			c = stdin.read();
			if (c <= 32)
			{
				break;
			}
		}
		return b.toString();
	}

	public void run()
	{
		try
		{
			stdin = new BufferedReader(new FileReader(NAME + ".in"));
			stdout = new BufferedWriter(new FileWriter(NAME + ".out"));
			solve();
			stdout.close();
			stdin.close();
		}
		catch (Exception e)
		{
			e.printStackTrace();
		}
	}

	public static void main(String[] args)
	{
		try
		{
			Locale.setDefault(Locale.US);
		}
		catch (Throwable e)
		{
		}
		new Thread(new C()).start();
	}
}
