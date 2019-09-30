import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.text.DecimalFormat;
import java.util.Locale;

//java 1.6
public class C implements Runnable
{
	static final String NAME = "c-small0";
	int n;

	double[][] coords;

	double[] ps;

	private double calc()
	{
		double left, right, middle;
		double a1, a2, b1, b2, c1, c2, d1, d2;
		left = 0;
		right = 1e+10;
		while (true)
		{
			middle = (left + right) / 2;
			if (middle <= left || middle >= right)
			{
				return middle;
			}
			a1 = -Double.MAX_VALUE;
			a2 = Double.MAX_VALUE;
			b1 = -Double.MAX_VALUE;
			b2 = Double.MAX_VALUE;
			c1 = -Double.MAX_VALUE;
			c2 = Double.MAX_VALUE;
			d1 = -Double.MAX_VALUE;
			d2 = Double.MAX_VALUE;
			for (int i = 0; i < n; i++)
			{
				double d = middle * ps[i];
				double dsum = coords[0][i] + coords[1][i] + coords[2][i];
				d1 = Math.max(d1, dsum - d);
				d2 = Math.min(d2, dsum + d);
				double asum = -coords[0][i] + coords[1][i] + coords[2][i];
				a1 = Math.max(a1, asum - d);
				a2 = Math.min(a2, asum + d);
				double bsum = coords[0][i] - coords[1][i] + coords[2][i];
				b1 = Math.max(b1, bsum - d);
				b2 = Math.min(b2, bsum + d);
				double csum = coords[0][i] + coords[1][i] - coords[2][i];
				c1 = Math.max(c1, csum - d);
				c2 = Math.min(c2, csum + d);
			}
			boolean isIntersect = true;
			if (a1 > a2 || b1 > b2 || c1 > c2 || d1 > d2)
			{
				isIntersect = false;
			}
			d1 = Math.max(d1, a1 + b1 + c1);
			d2 = Math.min(d2, a2 + b2 + c2);
			if (d1 > d2)
			{
				isIntersect = false;
			}
			if (isIntersect)
			{
				right = middle;
			}
			else
			{
				left = middle;
			}
		}
	}

	public void solve() throws Exception
	{
		DecimalFormat df = new DecimalFormat("###########0.00000000");
		int ntest = Integer.parseInt(readWord());
		for (int test = 1; test <= ntest; test++)
		{
			n = Integer.parseInt(readWord());
			coords = new double[3][n];
			ps = new double[n];
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					coords[j][i] = Integer.parseInt(readWord());
				}
				ps[i] = Integer.parseInt(readWord());
			}
			stdout.write("Case #" + test + ": " + df.format(calc()) + "\n");
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
			solve();
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
		new Thread(new C()).start();
	}
}
