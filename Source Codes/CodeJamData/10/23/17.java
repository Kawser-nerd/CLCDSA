import java.util.*;
import java.io.*;
public class R1C {
	static long BIG = 100003;
	
	public static void main(String args[]) throws Exception
	{
		Scanner in = new Scanner(new File("C-large.in"));
		PrintStream out = new PrintStream(new File("C-large.out"));
		long binom[][] = new long[600][600];
		binom[0][0] = 1;
		binom[1][0] = binom[1][1] = 1;
		
		for(int n = 2; n < 600; n++)
		{
			binom[n][0] = binom[n][n] = 1;
			for(int r = 1; r < n; r++)
			{
				binom[n][r] = (binom[n-1][r] + binom[n-1][r-1])%BIG;
			}
		}
		
		int cas = in.nextInt();
		for(int iii = 0; iii < cas; iii++)
		{
			int N = in.nextInt();
			
			long table[][] = new long[N+1][N+1];
			for(int i = 0; i <= N; i++) Arrays.fill(table[i], 0);
			for(int i = 1; i < N; i++) table[N][i] = 1;
			
			for(int n = N-1; n >= 2; n--)
			for(int k = 1; k < n; k++)
			{
				for(int next = n+(n-k); next <= N; next++)
				{
					table[n][k] = (table[n][k] + (binom[next-n-1][n-k-1]*table[next][n])%BIG)%BIG;
				}
			}
			
			for(int i = 2; i <= N; i++) table[1][0] = (table[i][1]+table[1][0])%BIG;
			
			out.println("Case #" + (iii+1) + ": " + table[1][0]);	
		}
		
		out.close();
	}
}