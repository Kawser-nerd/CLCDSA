import java.io.*;
import java.util.*;

public class Main implements Runnable
{
	private final String IFILE = "A-large.in";
	//private final String IFILE = "";
	private final String OFILE = "output.txt";
	//private final String OFILE = "";

	private Scanner in;
	private PrintWriter out;

	public void run()
	{
		try
		{
			Run();
		}
		catch(IOException e)
		{
			e.printStackTrace();
		}
	}

	public void Run() throws IOException
	{
		in = new Scanner(new File(IFILE));
		out = new PrintWriter(OFILE);
		int dd = in.nextInt();
		for(int d = 1; d <= dd; d++)
		{
			out.print("Case #" + d + ": ");
			int[][][] p = new int[2][3][2];
			for(int i = 0; i < 2; i++)
				for(int j = 0; j < 3; j++)
					for(int k = 0; k < 2; k++)
						p[i][j][k] = in.nextInt();

			for(int i = 0; i < 2; i++)
				for(int j = 1; j < 3; j++)
					for(int k = 0; k < 2; k++)
						p[i][j][k] -= p[i][0][k];

			int a11 = p[0][1][0] - p[1][1][0];
			int a12 = p[0][2][0] - p[1][2][0];
			int b1 = p[1][0][0] - p[0][0][0];
			int a21 = p[0][1][1] - p[1][1][1];
			int a22 = p[0][2][1] - p[1][2][1];
			int b2 = p[1][0][1] - p[0][0][1];
			int ddd = a11 * a22 - a21 * a12;
			int d1 = b1 * a22 - b2 * a12;
			int d2 = a11 * b2 - a21 * b1;
			if (ddd == 0)
			{
				//if (d1 == 0 && d2 == 0)
				//	out.println(p[1][0][0] + " " + p[1][0][1]);
				out.println("No solution");
				continue;
			}
			double u = (d1 + 0.0) / ddd;
			double v = (d2 + 0.0) / ddd;
			double x = p[0][0][0] + p[0][1][0] * u + p[0][2][0] * v;
			double y = p[0][0][1] + p[0][1][1] * u + p[0][2][1] * v;
			 out.println(x + " " + y);
		}
		in.close();
		out.close();
	}

	public static void main(String[] args) throws IOException
	{
		new Main().Run();
		//new Thread(new Main()).start();
	}

}
