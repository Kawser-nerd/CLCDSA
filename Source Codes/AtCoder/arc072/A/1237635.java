import java.io.*;
import java.util.*;

public class Main 
{
	public static int n;
	public static long[] nums;
	public static void main(String[] args) throws IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		nums = new long[n];
		for(int i = 0; i < n; i++)
			nums[i] = Long.parseLong(st.nextToken());
		long sum = nums[0];
		if(sum == 0)
			pw.println(Math.min(solve(1L, 1L), solve(-1L, 1L)));
		else if(sum > 0)
			pw.println(Math.min(solve(sum, 0L), solve(-1L, sum + 1L)));
		else if(sum < 0)
			pw.println(Math.min(solve(sum, 0L), solve(1L, -sum + 1L)));
		br.close();
		pw.close();
		System.exit(0);
	}
	public static long solve(long sum, long ans)
	{
		for(int i = 1; i < n; i++)
		{
			long num = nums[i];
			if(sum > 0)
			{
				sum += num;
				if(sum >= 0)
				{
					ans += sum + 1;
					sum = -1;
				}
			}
			else if(sum < 0)
			{
				sum += num;
				if(sum <= 0)
				{
					ans += -sum + 1;
					sum = 1;
				}
			}
		}
		return ans;
	}
}