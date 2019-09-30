import java.io.*;
import java.util.*;

public class B implements Runnable
{	
	private String IFILE = "B-large.in";
	private Scanner in;
	private PrintWriter out;
	
	private double calc(double x, double y, double z, double vx, double vy, double vz, double t)
	{
		double xx = x + vx * t;
		double yy = y + vy * t;
		double zz = z + vz * t;
		return Math.sqrt(xx * xx + yy * yy + zz * zz);
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
			long x = 0;
			long y = 0;
			long z = 0;
			long vx = 0;
			long vy = 0;
			long vz = 0;
			for(int i = 0; i < n; i++)
			{
				x += in.nextInt();
				y += in.nextInt();
				z += in.nextInt();
				vx += in.nextInt();
				vy += in.nextInt();
				vz += in.nextInt();
			}
			
			if (vx == 0 && vy == 0 && vz == 0)
			{
				double d = calc(x, y, z, vx, vy, vz, 0) / n; 
				out.printf("%.15f %.15f\n", d, 0.0);
			}
			else
			{
				long a = vx * vx + vy * vy + vz * vz;
				long b = - (x * vx + y * vy + z * vz);
				double t = (b + 0.0) / a;
				t = Math.max(0.0, t);
				double d = calc(x, y, z, vx, vy, vz, t) / n;
				out.printf("%.15f %.15f\n", d, t);
			}
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
		new B().Run();
		//new Thread(new XXX()).start();
	}

}
