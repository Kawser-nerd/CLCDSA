import java.util.Arrays;
import java.util.Scanner;

public class A {
	static int n;
	static long[] D;
	static long[] L;
	static int[] P;
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int cas=1; cas<=T; cas++) {
			n = in.nextInt();
			D = new long[n+2];
			L = new long[n+2];
			P = new int[n+2];
			D[0] = 0;
			L[0] = 0;
			for(int i=0; i<n; i++) {
				D[i+1] = in.nextLong();
				L[i+1] = in.nextLong();
			}
			D[n+1] = in.nextLong();
			L[n+1] = 0;
			for(int i=0; i<n+2; i++)
				P[i] = n+10;
			P[1] = 0;
			for(int c=1; c<n+2; c++) {
				if(P[c] == n+10) continue;
				long my_len = Math.min(L[c], D[c]-D[P[c]]);
				for(int nxt=c+1; nxt<n+2 && D[nxt]-D[c] <= my_len; nxt++) {
					P[nxt] = Math.min(P[nxt], c);
				}
			}
			System.out.printf("Case #%d: %s\n", cas, P[n+1]==n+10?"NO":"YES");
		}
	}
}