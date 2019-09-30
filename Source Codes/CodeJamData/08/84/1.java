import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.HashMap;

public class D
{
	final static String problem = "D-large";
	final static int prime=30031;
	BufferedReader in;
	BufferedWriter out;
	int n, k, p;
	class HashInt
	{
		int[] data;
		public HashInt(int[] data)
		{
			this.data = data;
		}
		public boolean equals(Object o)
		{
			HashInt obj = (HashInt) o;
			for (int i = 0; i < data.length; i++)
			{
				if (data[i] != obj.data[i])
				{
					return false;
				}
			}
			return true;
		}
		public int hashCode()
		{
			int res = 0;
			for (int i = 0; i < data.length; i++)
			{
				res *= 17;
				res += data[i];
			}
			return res;
		}
	}

	public HashMap<HashInt, Integer> map;
	public ArrayList<HashInt> list;
	int count;
	int[][] matrix;
	int[] cur;
	public void calcMatr()
	{
		cur = new int[k - 1];
		count = 0;
		map = new HashMap<HashInt, Integer>();
		list = new ArrayList<HashInt>();
		rec(0, p-1);
		matrix = new int[count][count];
		for (int i = 0; i < count; i++)
		{
			cur = list.get(i).data;
			int[] next = new int[k - 1];
			for (int j = 0; j <= k - 1; j++)
			{
				for (int s = 0; s < j; s++)
				{
					next[s] = cur[s] + 1;
				}
				for (int s = j; s < k - 2; s++)
				{
					next[s] = cur[s + 1] + 1;
				}
				if (j < k - 1)
				{
					next[k - 2] = 1;
				}
				Integer ind = map.get(new HashInt(next));
				if (ind!=null)
				{
					matrix[i][ind]++;
				}
			}
		}
	}
	public int[][] mult(int[][] m1,int[][] m2)
	{
		int[][] res=new int[count][count];
		for (int i=0;i<count;i++)
		{
			for (int j=0;j<count;j++)
			{
				for (int k=0;k<count;k++)
				{
					res[i][k]+=(m1[i][j]*m2[j][k])%prime;
				}
			}
		}
		for (int i=0;i<count;i++)
		{
			for (int j=0;j<count;j++)
			{
				res[i][j]=res[i][j]%prime;
			}
		}
		return res;
	}
	public void rec(int gl, int max)
	{
		if (gl == k - 1)
		{
			int[] curc = (int[]) cur.clone();
			HashInt h = new HashInt(curc);
			map.put(h, count);
			list.add(h);
			count++;
			return;
		}
		for (int i = 1; i <= max; i++)
		{
			cur[gl] = i;
			rec(gl + 1, i - 1);
		}
	}
	public int calcPower()
	{
		int[][] ans=new int[count][count];
		for (int i=0;i<count;i++)
		{
			ans[i][i]=1;
		}
		int deg=1;
		while (n>deg)
		{
			if ((n&deg)>0)
			{
				ans=mult(ans,matrix);
			}
			matrix=mult(matrix,matrix);
			deg*=2;
		}
		return ans[0][0]%prime;
	}
	public void solve() throws Exception
	{
		int cases = iread();
		for (int cur = 1; cur <= cases; cur++)
		{
			n = iread();
			k = iread();
			p = iread();
			n -= k;
			calcMatr();
			out.write("Case #"+cur+": "+calcPower()+"\n");
		}
	}

	public int iread() throws Exception
	{
		return Integer.parseInt(readWord());
	}

	public long lread() throws Exception
	{
		return Long.parseLong(readWord());

	}
	public double dread() throws Exception
	{
		return Double.parseDouble(readWord());
	}

	public String readWord() throws Exception
	{
		int c;
		StringBuilder b = new StringBuilder();
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

	public void run() throws Exception
	{
		in = new BufferedReader(new FileReader(problem + ".in"));
		out = new BufferedWriter(new FileWriter(problem + ".out"));
		solve();
		out.flush();
	}

	public static void main(String[] args)
	{
		try
		{
			new D().run();
		} catch (Exception e)
		{
			e.printStackTrace();
		}
	}
}
