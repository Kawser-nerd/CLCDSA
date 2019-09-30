import java.io.*;
import java.util.*;

public class B implements Runnable
{	
	 
	private final int MAX_VALUE = Integer.MAX_VALUE;
	private final int[] DX = new int[] {-1, 1, 0, 0};
	private final int[] DY = new int[] {0, 0, -1, 1};
	
	private String IFILE = "B-large.in";
	//private String IFILE = "B-small-attempt0.in";
	//private String IFILE = "input.txt";
	private Scanner in;
	private PrintWriter out;
	
	public void Run() throws IOException
	{
		in = new Scanner(new File(IFILE));
		out = new PrintWriter("output.txt");
		
		int ntest = in.nextInt();
		for(int test = 1; test <= ntest; test++)
		{
			out.print("Case #" + test + ": ");
			int h = in.nextInt();
			int n = in.nextInt();
			int m = in.nextInt();
			int[][] up = new int[n][m];
			int[][] down = new int[n][m];
			for(int i = 0; i < n; i++)
				for(int j = 0; j < m; j++)
					up[i][j] = in.nextInt();
			for(int i = 0; i < n; i++)
				for(int j = 0; j < m; j++)
					down[i][j] = in.nextInt();
			int[][] time = new int[n][m];
			int[][] f = new int[n][m];
			f[0][0] = 1;
			while (true)
			{
				int min = MAX_VALUE;
				int minx = -1;
				int miny = -1;
				for(int i = 0; i < n; i++)
					for(int j = 0; j < m; j++)
						if (f[i][j] == 1 && min > time[i][j])
						{
							min = time[i][j];
							minx = i;
							miny = j;
						}

				if (minx == n - 1 && miny == m - 1)
				{
					out.println(min / 10.0);
					break;
				}
				
				f[minx][miny] = 2;
				for(int i = 0; i < 4; i++)
				{
					int xx = minx + DX[i];
					int yy = miny + DY[i];
					if (xx < 0 || xx >= n || yy < 0 || yy >= m)
						continue;
					
					int u = Math.min(up[minx][miny], up[xx][yy]);
					int d = Math.max(down[minx][miny], down[xx][yy]);
					if (u - d < 50)
						continue;
					
					int startTime = Math.max(h - (u - 50), 0);
					startTime = Math.max(startTime, min);
					int endTime = startTime;
					if (startTime > 0)
					{
						if (h - startTime - down[minx][miny] >= 20)
							endTime += 10;
						else
							endTime += 100;
					}
					if (f[xx][yy] == 0 || time[xx][yy] > endTime)
					{
						time[xx][yy] = endTime;
						f[xx][yy] = 1;
					}
				}
				
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
