import java.io.*;
import java.util.*;

public class TaskC implements Runnable
{	
	//private String IFILE = "input.txt";
	private String IFILE = "C-small-attempt1.in";
	private Scanner in;
	private PrintWriter out;
	
	int n;
	int[][] pos;
	int[] pow;
	
	public void Run() throws IOException
	{
		Locale.setDefault(Locale.US);
		in = new Scanner(new File(IFILE));
		out = new PrintWriter("output.txt");
		
		int ntest = in.nextInt();
		for(int test = 1; test <= ntest; test++)
		{
			out.print("Case #" + test + ": ");
			n = in.nextInt();
			pos = new int[n][3];
			pow = new int[n];
			for(int i = 0; i < n; i++)
			{
				for(int j = 0; j < 3; j++)
					pos[i][j] = in.nextInt();
				pow[i] = in.nextInt();
			}
			double[] p = new double[3];
			double min = 0.0;
			double max = 1e8;
			//System.out.println(test);
			while (max - min > 1e-8)
			{
				double v = (min + max) / 2.0;
				boolean ok = true;
				for(int k = 0; k < 1000; k++)
				{
					ok = true;
					for(int i = 0; i < n; i++)
					{
						double dist = 0;
						for(int j = 0; j < 3; j++)
							dist += Math.abs(p[j] - pos[i][j]);
						if (dist > pow[i] * v + 1e-8)
						{
							ok = false;
							double d = 1 - pow[i] * v / dist;
							for(int j = 0; j < 3; j++)
								p[j] += (pos[i][j] - p[j]) * d;
						}
					}
					if (ok)
						break;
				}
				if (!ok)
					min = v;
				else
					max = v;
			}
			
			out.printf("%.10f\n",max);
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
		new TaskC().Run();
		//new Thread(new TaskC()).start();
	}

}
