import java.util.*;

public class Main {
	static class BIT {
		int L;
		long[] min;
		public BIT(int N) {
			L = 1;
			while(L<N) {
				L<<=1;
			}
			min = new long[L*2-1];
			Arrays.fill(min, Long.MAX_VALUE);
		}
		public void set(int x, long v) {
			int p = L-1+x;
			min[p] = v;
			while(p>0) {
				p=(p-1)/2;
				min[p] = Math.min(min[p*2+1], min[p*2+2]);
			}
		}
		public long getMin(int a, int b) {
			return getMin(a, b, 0, L, 0);
		}
		
		public long getMin(int a, int b, int l, int r, int idx) {
			if(r<=a || b<=l)
				return Long.MAX_VALUE;
			else if(a<=l && r<=b)
				return min[idx];
			else
				return Math.min(getMin(a, b, l,(l+r)/2,idx*2+1), getMin(a, b, (l+r)/2,r,idx*2+2));
		}
		
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		int E = sc.nextInt();
		int T = sc.nextInt();
		long[] x = new long[N+1];
		for(int i=0; i<N; i++)
			x[i+1] = sc.nextInt();
		
		long[] dp = new long[N+1];
		BIT bit = new BIT(N+1);
		bit.set(0, E+(E-x[1])*2);
		int j=0;
		for(int i=1; i<=N; i++) {
			while((x[i]-x[j+1])*2>T)
				j++;
			
			long min = bit.getMin(0, j);
			dp[i] = Math.min(min-(E-x[i])*3, dp[j]+x[i]-x[j]+T);
			if(i<N)
				bit.set(i, dp[i]+E-x[i]+(E-x[i+1])*2);
		}
		
		System.out.println(dp[N]+E-x[N]);
		sc.close();
	}
}