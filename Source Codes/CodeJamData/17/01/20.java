import java.io.*;
import java.util.*;

class Solution
{
	public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(in.readLine());
		for (int i = 1;i <= t;i++)
		{
			System.err.print("Running test "+i+"... "); System.out.flush();
			System.out.print("Case #"+i+": ");
			solve(in);
			System.err.println("done!");
		}
		System.exit(0);
	}
	private static void solve(BufferedReader in) throws Exception
	{
		StringTokenizer st = new StringTokenizer(in.readLine());
		char[] buf = st.nextToken().toCharArray();
		int k = Integer.parseInt(st.nextToken());
		int ans = 0;
		for (int i = 0;i <= buf.length-k;i++) if (buf[i] == '-')
		{
			for (int j = 0;j < k;j++)
			{
				if (buf[i+j] == '-') buf[i+j] = '+';
				else buf[i+j] = '-';
			}
			ans++;
		}
		for (int i = 0;i < buf.length;i++) if (buf[i] != '+')
		{
			System.out.println("IMPOSSIBLE");
			return;
		}
		System.out.println(ans);
	}
}
