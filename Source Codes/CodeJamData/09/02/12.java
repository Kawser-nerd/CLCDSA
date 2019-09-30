import java.io.*;

public class Watersheds {
	static int t,h,w;
	static int nums[][];
	static char current;
	static char[][] result;
	
	public static char flow(int i, int j)
	{
		if (result[i][j] == ' ')
		{
			int nn,ww,ee,ss;
			int num = nums[i][j];
			nn = (i>0)?nums[i-1][j]:50000;
			ww = (j>0)?nums[i][j-1]:50000;
			ee = (j<w-1)?nums[i][j+1]:50000;
			ss = (i<h-1)?nums[i+1][j]:50000;
			if (num<=nn && num<=ww && num<=ee && num<=ss)
			{
				result[i][j] = current++;
			}
			else if (ww>=nn && ee>=nn && ss>=nn)
			{
				result[i][j] = flow(i-1,j);
			}
			else if (nn>=ww && ee>=ww && ss>=ww)
			{
				result[i][j] = flow(i,j-1);
			}
			else if (nn>=ee && ww>=ee && ss>=ee)
			{
				result[i][j] = flow(i,j+1);
			}
			else
			{
				result[i][j] = flow(i+1,j);
			}
		}
		return result[i][j];
	}
	
	public static char[][] solve()
	{
		int i,j;
		result = new char[h][w];
		current = 'a';
		for (i=0;i<h;i++)
		{
			for (j=0;j<w;j++)
			{
				result[i][j] = ' ';
			}
		}
		for (i=0;i<h;i++)
		{
			for (j=0;j<w;j++)
			{
				if (result[i][j]==' ')
				{
					flow(i,j);
				}
			}
		}
		return result;
	}
	
	public static void main(String args[])
	{
		try
		{
			BufferedReader reader = new BufferedReader(new FileReader("src/B-large.in"));
			BufferedWriter writer = new BufferedWriter(new FileWriter("output"));
			int i,j,k;
			t = Integer.parseInt(reader.readLine());
			for (i=0;i<t;i++)
			{
				String line[] = reader.readLine().split(" ");
				h = Integer.parseInt(line[0]);
				w = Integer.parseInt(line[1]);
				nums = new int[h][w];
				for (j=0;j<h;j++)
				{
					line = reader.readLine().split(" ");
					for (k=0;k<w;k++)
					{
						nums[j][k] = Integer.parseInt(line[k]);
					}
				}
				solve();
				writer.write("Case #"+(i+1)+":");
				writer.newLine();
				for (j=0;j<h;j++)
				{
					for (k=0;k<w;k++)
					{
						writer.write(result[j][k]);
						if (k!=w-1)
						{
							writer.write(" ");
						}
					}
					writer.newLine();
				}
			}
			reader.close();
			writer.close();
		}
		catch (Exception ex)
		{
			ex.printStackTrace();
		}
	}
}
