import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Arrays;
import java.util.Locale;

//java 1.6
public class A implements Runnable
{
	static final String NAME = "a-large";
	int x, y, dx, dy;

	int[] min;

	int[] max;
	
	int[] miny;

	int[] maxy;
	
	int s;

	void move(char c)
	{
		if (c == 'R')
		{
			int t = dx;
			dx = -dy;
			dy = t;
			return;
		}
		if (c == 'L')
		{
			int t = dx;
			dx = dy;
			dy = -t;
			return;
		}
		s += x * dy - y * dx;
		x += dx;
		y += dy;
		miny[y] = Math.min(miny[y], x);
		maxy[y] = Math.max(maxy[y], x);
		if (dx == 0)
		{
			return;
		}
		if (dx > 0)
		{
			max[x - 1] = Math.max(max[x - 1], y);
			min[x - 1] = Math.min(min[x - 1], y);
		}
		else
		{
			max[x] = Math.max(max[x], y);
			min[x] = Math.min(min[x], y);
		}

	}
	public String solve() throws Exception
	{
		x = 4000;
		y = 4000;
		dx = 1;
		dy = 0;
		min = new int[8000];
		max = new int[8000];
		miny = new int[8000];
		maxy = new int[8000];
		s = 0;
		Arrays.fill(min, Integer.MAX_VALUE);
		Arrays.fill(max, Integer.MIN_VALUE);
		Arrays.fill(miny, Integer.MAX_VALUE);
		Arrays.fill(maxy, Integer.MIN_VALUE);
		int l = Integer.parseInt(readWord());
		for (int i = 0; i < l; i++)
		{
			String s = readWord();
			int t = Integer.parseInt(readWord());
			for (int j = 0; j < t; j++)
			{
				for (int k = 0; k < s.length(); k++)
				{
					move(s.charAt(k));
				}
			}
		}
		for (int i = 0; i < 8000; i++)
		{
			if (maxy[i] > miny[i])
			{
				for (int j = miny[i]; j < maxy[i]; j++)
				{
					max[j] = Math.max(max[j], i);
					min[j] = Math.min(min[j], i);
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < 8000; i++)
		{
			if (max[i] > min[i])
			{
				ans += max[i] - min[i];
			}
		}
		ans -= Math.abs(s / 2);
		return ans + "";
	}
	public void init()
	{

	}
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
			b.append((char)c);
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
			init();
			int ntest = Integer.parseInt(readWord());
			for (int test = 1; test <= ntest; test++)
			{
				stdout.write("Case #" + test + ": " + solve() + "\n");
			}
			stdout.close();
			stdin.close();
		} catch (Exception e)
		{
			e.printStackTrace();
		}
	}
	public static void main(String[] args)
	{
		try
		{
			Locale.setDefault(Locale.US);
		} catch (Throwable e)
		{
		}
		new Thread(new A()).start();
	}
	static BufferedReader stdin;
	static BufferedWriter stdout;
	int test;
}
