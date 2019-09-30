import java.io.PrintWriter;
import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);

		int N = sc.nextInt();
		int D = sc.nextInt();
		int[] x = new int[N];
		for(int i=0; i<N; i++)
			x[i] = sc.nextInt();
		int Q = sc.nextInt();
		long[] qq = new long[Q];
		for(int i=0; i<Q; i++)
			qq[i] = (sc.nextLong()-1)<<30 | i;
		
		Arrays.sort(qq);
		
		int[] rest = new int[N+1];
		rest[0] = D;
		for(int i=0; i<N; i++)
			rest[i+1] = Math.min(rest[i], Math.abs(rest[i]-x[i]));
		
		boolean[] ans = new boolean[Q];
		long range = 0;
		int idx = Q-1;
		for(int i=N-1; i>=0; i--) {
			while(idx>=0 && (qq[idx]>>30)==i) {
				if(rest[i] > range) {
					ans[(int)(qq[idx]&((1<<30)-1))] = true;
				}
				idx--;
			}
			if(x[i]<=range*2+1) {
				range += x[i];
			}
		}
		
		for(int i=0; i<Q; i++)
			pw.println(ans[i] ? "YES" : "NO");
		
		sc.close();
		pw.close();
	}
}