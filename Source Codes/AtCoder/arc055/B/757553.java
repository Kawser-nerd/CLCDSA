import java.util.*;

public class Main {
	static int N;
	static double[][][] memo;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		N = sc.nextInt();
		int K = sc.nextInt();
		memo = new double[2][N+1][K+1];
		for(int t=0; t<2; t++)
			for(int i=0; i<N+1; i++)
				Arrays.fill(memo[t][i], -1);
		
		System.out.println(calc(0, 0, K));

		sc.close();
	}
	static double calc(int i, int j, int k) {
		if(memo[i][j][k]>=0)
			return memo[i][j][k];
		
		double ans = 0;
		if(j==N)
			return i==1 ? 1.0 : 0.0;
		
		double p = 1.0/(j+1);
		if(k>0) {
			ans = p*Math.max(calc(0,j+1,k), calc(1,j+1,k-1)) + (1-p)*calc(i,j+1,k);
		} else {
			ans = p*calc(0,j+1,k) + (1-p)*calc(i,j+1,k);
		}
		
		return memo[i][j][k] = ans;
	}
}