import java.util.*;

public class D {
	static boolean bit_set(int set, int bit) { return ((set>>>bit)&1)==1; }
	
	static Double[][] DP = new Double[21][1<<20];
	static double f(int n, int used) {
		if(used == (1<<n)-1) return 0;
		if(DP[n][used]!=null) return DP[n][used];
		
		double ans = 0;
		for(int i=0; i<n; i++) {
			int nxt = i;
			int money = n;
			while(bit_set(used, nxt)) {
				nxt = (nxt+1)%n;
				money--;
			}
			ans += 1.0/n*(money+f(n,used|1<<nxt));
		}
		return DP[n][used]=ans;
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int cas=1; cas<=T; cas++) {
			char[] S = in.next().toCharArray();
			int used = 0;
			for(int i=0; i<S.length; i++)
				if(S[i]=='X')
					used |= 1<<i;
			System.out.printf("Case #%d: %.10f\n", cas, f(S.length, used));
		}
	}
}
