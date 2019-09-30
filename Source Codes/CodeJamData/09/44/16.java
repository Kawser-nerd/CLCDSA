import java.io.*;
import java.util.*;

public class D implements Runnable
{	
	private String IFILE = "D-small-attempt0.in";
	private Scanner in;
	private PrintWriter out;
	
	double[] x;
	double[] y;
	double[] r;
	
	private double sqr(double x)
	{
		return x * x;
	}
	
	private double f(int a, int b)
	{
		return (r[a] + r[b] + Math.sqrt(sqr(x[a] - x[b]) + sqr(y[a] - y[b]))) / 2;
	}
	
	public void Run() throws IOException
	{
		Locale.setDefault(Locale.US);
		in = new Scanner(new File(IFILE));
		out = new PrintWriter("output.txt");
		
		int ntest = in.nextInt();
		for(int test = 1; test <= ntest; test++)
		{
			out.print("Case #" + test + ": ");
			
			int n = in.nextInt();
			x = new double[n];
			y = new double[n];
			r = new double[n];
			for(int i = 0; i < n; i++)
			{
				x[i] = in.nextInt();
				y[i] = in.nextInt();
				r[i] = in.nextInt();
			}
			
			double result = 1e+20;
			if (n == 1)
				result = r[0];
			else if (n == 2)
				result = Math.max(r[0], r[1]);
			else
			{
				result = Math.min(result, Math.max(f(0, 1), r[2]));
				result = Math.min(result, Math.max(f(0, 2), r[1]));
				result = Math.min(result, Math.max(f(1, 2), r[0]));
			}
			out.printf("%.8f\n", result);
		}
		
		in.close();
		out.close();
	}
	
	public void run()
	{
		try		
		{
			Run();
		}
		catch(IOException e)
		{
			
		}
	}

	public static void main(String[] args) throws IOException
	{
		new D().Run();
		//new Thread(new XXX()).start();
	}

}
