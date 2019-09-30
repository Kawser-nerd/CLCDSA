import java.util.Scanner;

/**
 * http://abc025.contest.atcoder.jp/tasks/abc025_d
 */
public class Main {

	static final int N = 5;
	static final int DP_NUM = 0x1<<N*N;
	static final int MOD = 1000000007;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[][] f = new int[N][N];
		for(int y=0; y<N; y++)
			for(int x=0; x<N; x++)
				f[y][x] = sc.nextInt();
		sc.close();

		int[] dp = new int[DP_NUM];
		dp[0] = 1;
		
		for(int m=0; m<DP_NUM-1; m++){
			
			if(dp[m]==0) continue;
			int n = Integer.bitCount(m)+1;
			for(int i=0; i<N*N; i++){
				if(( m & 0x1<<i ) > 0) continue;
				int y = i/N;
				int x = i%N;
				if(f[y][x]!=0 && f[y][x]!=n) continue;
				if(check(y, x, m)){
					int nm = m | 0x1 << i;
					dp[nm] = (dp[nm]+dp[m])%MOD;
				}
			}
		}
		
		System.out.println(dp[DP_NUM-1]);
		
	}

	static boolean check(int y, int x, int m) {
		int lx = x-1;
		int rx = x+1;
		int uy = y-1;
		int dy = y+1;
		if (lx>=0 && rx<N){
			int ltmp = 0x1 << (lx+y*N);
			int rtmp = 0x1 << (rx+y*N);
			if ((m&ltmp)==0&&(m&rtmp)>0 || (m&ltmp)>0&&(m&rtmp)==0) return false;
		}
		if (uy>=0 && dy<N){
			int utmp = 0x1 << (x+uy*N);
			int dtmp = 0x1 << (x+dy*N);
			if ((m&utmp)==0&&(m&dtmp)>0 || (m&utmp)>0&&(m&dtmp)==0) return false;
		}
		return true;
	}
	
	
}