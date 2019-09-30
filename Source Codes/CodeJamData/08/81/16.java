import java.io.*;
import java.util.*;

public class Main implements Runnable{

	Scanner in;
	PrintWriter out;

	double EPS = 1e-10;
	// ret -1 no 0 uniq 1 many
	//matrix, equations, x, result
	int Gauss(double[][] a, int n, int m, double[] x)
	{
		int[] was = new int[n];
		Arrays.fill(was, -1);
		for (int i = 0; i < m; i++)
		{
			int k = -1;
			for (int j = 0; j < n; j++)
			if (was[j] == -1 && Math.abs(a[j][i]) > EPS)
			{ k = j; break; }
			if (k == -1)
			continue;
			was[k] = i;
			double t = 1 / a[k][i];
			for (int j = 0; j <= m; j++)
			a[k][j] *= t;
			for (int j = 0; j < n; j++)
			if (j != k)
			{
				double p = -a[j][i];
				for (int h = 0; h <= m; h++)
				a[j][h] += p * a[k][h];
			}
		}
		int flag = 0;
		Arrays.fill(x, 0);
		for (int i = 0; i < n; i++)
		if (was[i] == -1)
		{
			if (Math.abs(a[i][m]) > EPS)
			return -1;
			flag++;
		}
		else
			x[was[i]] = a[i][m];
		if (n - flag == m)
			return 0;
		else
			return 1;
	}

	public void Run()throws IOException
	{
		in = new Scanner(new File("input.txt"));
		out = new PrintWriter("output.txt");

		int nt = in.nextInt();
		in.nextLine();
		for(int it=0;it<nt;it++)
		{
			out.print("Case #" + (it + 1) + ": ");
			double x11 = in.nextInt(), y11 = in.nextInt();
			double x12 = in.nextInt(), y12 = in.nextInt();
			double x13 = in.nextInt(), y13 = in.nextInt();

			double x21 = in.nextInt(), y21 = in.nextInt();
			double x22 = in.nextInt(), y22 = in.nextInt();
			double x23 = in.nextInt(), y23 = in.nextInt();

			double [][] a = new double[6][7];
			a[0][0] = x11;
			a[0][1] = y11;
			a[0][4] = 1;
			a[0][6] = x21;

			a[1][2] = x11;
			a[1][3] = y11;
			a[1][5] = 1;
			a[1][6] = y21;

			a[2][0] = x12;
			a[2][1] = y12;
			a[2][4] = 1;
			a[2][6] = x22;

			a[3][2] = x12;
			a[3][3] = y12;
			a[3][5] = 1;
			a[3][6] = y22;

			a[4][0] = x13;
			a[4][1] = y13;
			a[4][4] = 1;
			a[4][6] = x23;

			a[5][2] = x13;
			a[5][3] = y13;
			a[5][5] = 1;
			a[5][6] = y23;

			double [] x = new double[6];
			int ret = Gauss(a, 6, 6, x);
			if(ret != 0)
			{
				out.println("IMPOSSIBLE");
				continue;
			}

			double [][]na = new double[2][3];
			na[0][0] = x[0] - 1.0;
			na[0][1] = x[1];
			na[1][0] = x[2];
			na[1][1] = x[3] - 1.0;
			na[0][2] = -x[4];
			na[1][2] = -x[5];

			double [] nx = new double[2];
			ret = Gauss(na, 2, 2, nx);
			if(ret != 0)
			{
				out.println("IMPOSSIBLE");
				continue;
			}
			out.printf(Locale.US, "%.6f %.6f\n", nx[0], nx[1]);
		}

		in.close();
		out.close();
	}

	public void run() {
		try
		{
			Run();
		}
		catch(IOException e)
		{
			e.printStackTrace();
		}
	}

	public static void main(String[] args) throws IOException
	{
		new Main().Run();
		//new Thread(new Main()).start();
	}

}
