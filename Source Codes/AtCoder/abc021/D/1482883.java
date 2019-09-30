import java.util.Scanner;

/**
 * http://abc021.contest.atcoder.jp/tasks/abc021_d
 * ???????
 */
public class Main {
	
	static final int INF = 1000000007;

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		final int N = sc.nextInt();
		final int K = sc.nextInt();
		sc.close();
		
		System.out.println( getHomogeneousCombination(N,K));

	}
	
	/**
	 * ???????
	 */
	private static long getHomogeneousCombination(int n, int r){
	    return getCombination(n-1+r, n-1);
	}

	/**
	 * ?????
	 */
	private static long getCombination(int n, int r){
		
		long[] modDp = new long[n+1];
		long[] modInvDp = new long[n+1];
	    modDp[0] = 1; 
	    modInvDp[n] = 1;
	    for (int i=1; i<=n; i++) modDp[i] = (modDp[i-1]*i) % INF;
	    
	    long tmp = modDp[n];
	    long doubling = INF-2;
	    while (doubling > 0) {
	        if (doubling%2==1) modInvDp[n] = (modInvDp[n]*tmp) % INF;
	        tmp = (tmp*tmp)%INF; 
	        doubling /= 2;
	    }
	    for (int i=n; i>0; i--) modInvDp[i-1] = modInvDp[i]*i % INF;

	    long ans = modDp[n];
	    ans = ans*modInvDp[r] % INF;
	    ans = ans*modInvDp[n-r] % INF;
		return ans;

	}

}