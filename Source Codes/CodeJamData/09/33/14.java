import java.util.Scanner;
import java.util.Arrays;

public class Prisioners {

	public static int P, Q;

	public static int [] free;

	public static int [][] dp;

	public static int get (int a, int b, int n) {
		
		int i, min, next;
		
		min = Integer.MAX_VALUE;
		if (dp[a][b]==-1) {
			if (b-a < 0)
				min = 0;
			else {
				for (i=a ; i<=b ; i++) {
					next = (free[i]-free[a-1]-1) + (free[b+1]-free[i]-1) + get (a, i-1, n+1) + get(i+1, b, n+1);
					if (next < min)
						min = next;
				}
			}
			dp[a][b] = min;
		}
		
		return dp[a][b];
		
	}

	public static void main (String [] args) {
		
		Scanner S;
		int T, i, caso;
		
		S = new Scanner (System.in);
		T = S.nextInt();
		caso = 1;
		while (T-- > 0) {
			P = S.nextInt();
			Q = S.nextInt();
			free = new int [Q+2];
			free[0] = -1;
			for (i=1 ; i<=Q ; i++)
				free[i] = S.nextInt()-1;
			free[Q+1] = P;
			dp = new int [Q+2][Q+2];
			for (i=0 ; i<Q+2 ; i++)
				Arrays.fill(dp[i], -1);
			System.out.println("Case #" + (caso++) + ": " + get(1, Q, 0));
		}
		
	}

}