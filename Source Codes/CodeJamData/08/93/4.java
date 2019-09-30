import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class C implements Runnable
{
	public static String file = "c-large";
	public BufferedReader in;
	public BufferedWriter out;
	int r, c;
	int[][] table;
	int[] sums;

	public void calcSums()
	{
		sums=new int[r];
		for (int i = 0; i < r; i++)
		{
			if (c % 3 == 0)
			{
				for (int j=1;j<c;j+=3)
				{
					sums[i]+=table[i][j];
				}
			}else
			{
				for (int j=0;j<c;j+=3)
				{
					sums[i]+=table[i][j];
				}
			}
		}
	}
	
	int[] cx;
	int[] ax;
	int ans;
	
	public void solveSys()
	{
		cx=new int[r];
		ax=new int[r];
		cx[0]=1;
		ax[0]=0;
		cx[1]=-1;
		ax[1]=sums[0];
		for (int i=1;i<r-1;i++)
		{
			cx[i+1]=-cx[i]-cx[i-1];
			ax[i+1]=sums[i]-ax[i]-ax[i-1];
		}
		if (cx[r/2]==0)
		{
			ans=ax[r/2];
			return;
		}
		int x=(sums[r-1]-ax[r-1]-ax[r-2])/(cx[r-1]+cx[r-2]);
		ans=cx[r/2]*x+ax[r/2];
	}

	public void solve() throws Exception
	{
		int ntest = Integer.parseInt(readWord());
		for (int test = 1; test <= ntest; test++)
		{
			r = Integer.parseInt(readWord());
			c = Integer.parseInt(readWord());
			table = new int[r][c];
			for (int i = 0; i < r; i++)
			{
				for (int j = 0; j < c; j++)
				{
					table[i][j] = Integer.parseInt(readWord());
				}
			}
			calcSums();
			solveSys();
			out.write("Case #" + test + ": " + ans+"\n");
		}
	}

	public String readWord() throws Exception
	{
		StringBuilder b = new StringBuilder();
		int c;
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

	public void run()
	{
		try
		{
			in = new BufferedReader(new FileReader(file + ".in"));
			out = new BufferedWriter(new FileWriter(file + ".out"));
			solve();
			in.close();
			out.close();
		} catch (Exception e)
		{
			e.printStackTrace();
		}
	}

	public static void main(String[] args)
	{
		try
		{
			new Thread(new C()).start();
		} catch (Exception e)
		{
			e.printStackTrace();
		}
	}

}
