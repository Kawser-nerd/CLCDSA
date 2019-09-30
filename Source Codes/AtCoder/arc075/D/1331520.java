import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int D = sc.nextInt();
		
		System.out.println(solve(D));

		sc.close();
	}
	
	static final int MAXL=17;
	static int N;
	static long[] v;
	
	static long solve(int D) {
		if(D%9 != 0)
			return 0;
		D /= 9;
		
		long[] B = new long[MAXL];
		B[0] = 1;
		for(int i=1; i<MAXL; i++)
			B[i] = B[i-1]*10;

		long ans =0;
		for(int i=1; i<=MAXL; i++) {
			N = (i+1)/2;
			v = new long[N];
			for(int j=0; j<N; j++)
				for(int k=j; k<i-j; k++)
					v[j] += B[k];
			ans += count(D, i, 0, new int[N]);
		}
		
		return ans;
	}
	
	static long count(long D, int l, int t, int[] x) {
		if(t==N) {
			if(D!=0)
				return 0;
			
			long ans = 1;
			for(int i=0; i<N; i++) {
				ans *= (i==0 ? 9 : 10) - Math.abs(x[i]);
			}
			if(l%2==0)
				ans *= 10;
			return ans;
		}
		long ans = 0;
		for(int m=-9; m<=9; m++) {
			if(-v[t] < D+v[t]*m && D+v[t]*m < v[t]) {
				x[t] = m;
				ans += count(D+v[t]*m, l, t+1, x);
			}
		}
		return ans;
	}
}