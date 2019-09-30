import java.util.*;

public class Main {
	static class Criteria {
		int l,r;
		int x;
		public Criteria(int l, int r, int x) {
			this.l = l;
			this.r = r;
			this.x = x;
		}
	}
	static int N;
	static ArrayList<ArrayList<Criteria>> list;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		final long MOD = 1000000007;
		
		N = sc.nextInt();
		int M = sc.nextInt();
		list = new ArrayList<>();
		for(int i=0; i<N+1; i++)
			list.add(new ArrayList<>());
		for(int i=0; i<M; i++) {
			int l = sc.nextInt()-1;
			int r = sc.nextInt();
			int x = sc.nextInt();
			list.get(r).add(new Criteria(l, r, x));
		}
		
		int[][][] dp = new int[N+1][N+1][N+1];
		dp[0][0][0] = 1;

		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				for(int k=0; k<N; k++) {
					if(dp[i][j][k]==0)
						continue;
					if(isOK(i, j, k)) {
						int max = Math.max(i, Math.max(j, k));
						dp[max+1][j][k] = (int)(((long)dp[max+1][j][k] + dp[i][j][k])%MOD);
						dp[i][max+1][k] = (int)(((long)dp[i][max+1][k] + dp[i][j][k])%MOD);
						dp[i][j][max+1] = (int)(((long)dp[i][j][max+1] + dp[i][j][k])%MOD);
					}
				}
			}
		}
		long ans = 0;
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				if(isOK(N, i, j))
					ans = (ans + dp[N][i][j] + dp[j][N][i] + dp[i][j][N])%MOD;
		
		System.out.println(ans);
		sc.close();
	}
	
	static boolean isOK(int i, int j, int k) {
		int max = Math.max(i, Math.max(j, k));
		for(Criteria c : list.get(max))
			if(!isOK(c, i, j, k))
				return false;
		return true;
	}
	
	static boolean isOK(Criteria c , int i, int j, int k) {
		int ci3 = Math.min(i, Math.min(j, k));
		int ci1 = Math.max(i, Math.max(j, k));
		int ci2 = i^j^k^ci3^ci1;
		if(c.x==1) {
			return ci2 <= c.l;
		} else if(c.x==2) {
			return ci3 <= c.l && c.l < ci2;
		} else {
			return c.l < ci3;
		}
	}
}