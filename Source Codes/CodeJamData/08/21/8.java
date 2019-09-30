import java.io.*;
import java.util.*;

public class TaskA implements Runnable
{	
	private String IFILE = "A-large.in";
	private Scanner in;
	private PrintWriter out;
	
	public void Run() throws IOException
	{
		in = new Scanner(new File(IFILE));
		out = new PrintWriter("output.txt");
		
		int ntest = in.nextInt();
		for(int test = 1; test <= ntest; test++)
		{
			int n = in.nextInt();
			long a = in.nextInt();
			long b = in.nextInt();
			long c = in.nextInt();
			long d = in.nextInt();
			long x0 = in.nextInt();
			long y0 = in.nextInt();
			long m = in.nextInt();			
			out.print("Case #" + test + ": ");
			long[][] mas = new long[3][3];
			for(int i = 0; i < n; i++)
			{
				//System.out.println(x0 + " " + y0);
				mas[(int)(x0 % 3)][(int)(y0 % 3)]++;
				x0 = (a * x0 + b) % m;
				y0 = (c * y0 + d) % m;
			}
			long res = 0;
			for(int i = 0; i < 3; i++)
				for(int j = 0; j < 3; j++)
					res += mas[i][j] * (mas[i][j] - 1) * (mas[i][j] - 2) / 6;

			for(int i = 0; i < 3; i++)
				res += mas[i][0] * mas[i][1] * mas[i][2];

			for(int i = 0; i < 3; i++)
				res += mas[0][i] * mas[1][i] * mas[2][i];
			
			for(int i = 0; i < 3; i++)
				for(int j = 0; j < 3; j++)
					for(int k = 0; k < 3; k++)
						if (i != j && i != k && j != k)
							res += mas[0][i] * mas[1][j] * mas[2][k];
			
			out.println(res);
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
		new TaskA().Run();
		//new Thread(new XXX()).start();
	}

}
