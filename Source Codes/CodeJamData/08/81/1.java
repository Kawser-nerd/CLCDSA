import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.text.DecimalFormat;
import java.awt.geom.AffineTransform;
import java.awt.geom.Point2D;

public class A
{
	final static String problem = "A-large";
	BufferedReader in;
	BufferedWriter out;
	Point2D.Double[] tr1;
	Point2D.Double[] tr2;
	AffineTransform tres;
	public void apply(AffineTransform t)
	{
		for (int i = 0; i < 3; i++)
		{
			Point2D.Double temp = new Point2D.Double();
			t.transform(tr1[i], temp);
			tr1[i] = temp;
		}
	}
	public void findTrans()
	{
		AffineTransform a = new AffineTransform();
		a.translate(-tr1[0].x, -tr1[0].y);
		AffineTransform a1 = new AffineTransform();
		double d1 = tr1[0].distance(tr1[1]);
		double d2 = tr2[0].distance(tr2[1]);
		a1.scale(d2 / d1, d2 / d1);
		a1.concatenate(a);
		double ang1 = Math.atan2(tr1[1].y - tr1[0].y, tr1[1].x - tr1[0].x);
		double ang2 = Math.atan2(tr2[1].y - tr2[0].y, tr2[1].x - tr2[0].x);
		AffineTransform a2 = new AffineTransform();
		a2.rotate(ang2 - ang1);
		a2.concatenate(a1);
		AffineTransform a3 = new AffineTransform();
		a3.translate(tr2[0].x, tr2[0].y);
		a3.concatenate(a2);
		tres = a3;
		apply(a3);
	}

	public void solve() throws Exception
	{
		int cases = iread();
		for (int cur = 1; cur <= cases; cur++)
		{
			tr1 = new Point2D.Double[3];
			for (int i = 0; i < 3; i++)
			{
				double x = dread();
				double y = dread();
				tr1[i] = new Point2D.Double(x, y);
			}
			tr2 = new Point2D.Double[3];
			for (int i = 0; i < 3; i++)
			{
				double x = dread();
				double y = dread();
				tr2[i] = new Point2D.Double(x, y);
			}
			Point2D.Double start = (Point2D.Double) tr1[0].clone();
			findTrans();
			for (int i = 0; i < 100; i++)
			{
				tres.concatenate(tres);
			}
			Point2D.Double ans = new Point2D.Double();
			tres.transform(start, ans);
			DecimalFormat df = new DecimalFormat("###########0.00000000");
			out.write("Case #"+cur+": " + df.format(ans.x) + " " + df.format(ans.y)
					+ "\n");
		}
	}

	public int iread() throws Exception
	{
		return Integer.parseInt(readWord());
	}

	public long lread() throws Exception
	{
		return Long.parseLong(readWord());

	}
	public double dread() throws Exception
	{
		return Double.parseDouble(readWord());
	}

	public String readWord() throws Exception
	{
		int c;
		StringBuilder b = new StringBuilder();
		while (true)
		{
			c = in.read();
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
			c = in.read();
			if (c <= 32)
			{
				break;
			}
		}
		return b.toString();
	}

	public void run() throws Exception
	{
		in = new BufferedReader(new FileReader(problem + ".in"));
		out = new BufferedWriter(new FileWriter(problem + ".out"));
		solve();
		out.flush();
	}

	public static void main(String[] args)
	{
		try
		{
			new A().run();
		} catch (Exception e)
		{
			e.printStackTrace();
		}
	}
}
