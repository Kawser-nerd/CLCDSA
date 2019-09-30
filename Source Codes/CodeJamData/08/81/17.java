import java.util.*;
import java.math.*;
import java.text.*;
import java.io.*;


public class Main implements Runnable{

	final String problem="A";
	final boolean large = false;
	final int attempt = 0;

	final double eps = 1e-8;

	int dist(int x, int y)
	{
		return x*x+y*y;
	}
	double dist(double x, double y)
	{
		return x*x+y*y;
	}

	public void solve() throws IOException
	{
		int[] x = new int[6], y = new int[6];
		for (int i=0; i<6; i++)
		{
			x[i] = iread();
			y[i] = iread();
		}
		double scale1 = Math.sqrt(dist(x[1]-x[0], y[1]-y[0])),
			scale2 = Math.sqrt(dist(x[4]-x[3], y[4]-y[3]));
		double[] cx = new double[3], cy = new double[3], r = new double[3];
		for (int i=0; i<3; i++)
		{
			double a = x[i+3]-x[i];
			double b = y[i+3]-y[i];
			double d = dist(x[i+3]-x[i],y[i+3]-y[i]);
			d = Math.sqrt(d);
			double t = scale2/ (scale1 - scale2);
			double u = scale2/ (scale1 + scale2);
			cx[i] = x[i+3] + (t-u)/2.0*a;
			cy[i] = y[i+3] + (t-u)/2.0*b;
			r[i] = (t+u)*d / 2.0;
		}
		for (int i=0; i<3; i++)
		{
			int j = (i+1)%3;
			double a = cx[j]-cx[i], b = cy[j]-cy[i];
			double d =dist(a, b);
			if (d<eps)
				continue;
			d = Math.sqrt(d);
			a/=d;b/=d;
			double t = (d*d+r[i]*r[i]-r[j]*r[j])/(2*d);
			double u = Math.sqrt(r[i]*r[i]-t*t);
			if (r[i]*r[i]-t*t<-eps) continue;
			if (r[i]*r[i]-t*t<0)
				u = 0;
			double ax = cx[i] + a*t - b*u, ay = cy[i] + b*t + a*u;
			for (int k=0; k<3; k++)
			{
				if (Math.abs(dist(ax-cx[k], ay-cy[k])-r[i]*r[i])>eps) break;
				DecimalFormat df = new DecimalFormat("0.00000000000");
				out.write(df.format(ax)+" "+df.format(ay)+"\n");
				return;
			}
		}
		System.out.println("FAIL");
		out.write("FAIL\n");
	}

	public static void main(String[] args) {
		Main instance = new Main();
		new Thread(instance).run();
	}

	public String getFilename()
	{
		if (large)
			return problem+"-large";
		return problem+"-small-attempt"+attempt;
	}

	BufferedReader in;
	BufferedWriter out;
	public void run() {
		try
		{
			in = new BufferedReader(new FileReader(getFilename()+".in"));
			out = new BufferedWriter(new FileWriter(getFilename()+".out"));
			int ntests = iread();
			for (int test = 1; test<=ntests; test++)
			{
				out.write("Case #"+test+": ");
				solve();
			}
			out.flush();
		} catch (Exception e)
		{
			e.printStackTrace();
			System.exit(1);
		}
	}
	public String readword() throws IOException
	{
		int c = in.read();
		while (c<=32)
		{
			if (c<0) return "";
			c = in.read();
		}
		StringBuilder sb = new StringBuilder();
		while (c>32)
		{
			sb.append((char)c);
			c = in.read();
		}
		return sb.toString();
	}
	public int iread() throws IOException
	{
		return Integer.parseInt(readword());
	}
	public double dread() throws IOException
	{
		return Double.parseDouble(readword());
	}
	public long lread() throws IOException
	{
		return Long.parseLong(readword());
	}
}
