import java.util.*;
import java.io.*;
import java.math.*;

public class Fast {
	public void doMain() throws Exception {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		
		int T = sc.nextInt();
		
		for (int caseNum=1; caseNum <= T; caseNum++) {
			System.out.println("case " + caseNum);
			pw.print("Case #" + caseNum + ": ");
			int N = sc.nextInt();
			long L = sc.nextLong();
			long H = sc.nextLong();
			long[] F = new long[N];
			for (int i=0; i<N; i++)
				F[i] = sc.nextLong();
			
			Arrays.sort(F);
			BigInteger[] gcd = new BigInteger[N];
			gcd[N-1] = BigInteger.valueOf(F[N-1]);
			for (int i=N-2; i>=0; i--) {
				gcd[i] = gcd[i+1].gcd(BigInteger.valueOf(F[i]));
			}
			
			final BigInteger INF = BigInteger.valueOf(1000000000000000000L);
			
			BigInteger[] lcm = new BigInteger[N];
			lcm[0] = BigInteger.valueOf(F[0]);
			for (int i=1; i<N; i++) {
				lcm[i] = lcm[i-1].multiply(BigInteger.valueOf(F[i])).divide(lcm[i-1].gcd(BigInteger.valueOf(F[i])));
				if (lcm[i].compareTo(INF) >= 0) {
					for (int j=i+1; j<N; j++)
						lcm[j] = lcm[i];
					break;
				}
			}
			
			long ans = INF.longValue();
			
			// just lcm
			if (lcm[N-1].compareTo(INF) < 0) {
				long LCM = lcm[N-1].longValue();
				long cand = L / LCM * LCM;
				if (cand < L) cand += LCM;
				if (cand >= L && cand <= H)
					ans = Math.min(ans, cand);
			}
			
			// just gcd
			{
				long GCD = gcd[0].longValue();
				System.out.println("GCD = " + GCD);
				for (long i=1; i * i <= GCD; i++) if (GCD % i == 0) {
					if (i >= L && i <= H)
						ans = Math.min(ans, i);
					if (GCD/i >= L && GCD/i <= H)
						ans = Math.min(ans, GCD/i);
				}
			}
			
			// hybrid
			for (int i=0; i+1 < N; i++)
				if (gcd[i+1].remainder(lcm[i]).equals(BigInteger.ZERO)) {
					long LCM = lcm[i].longValue();
					long GCD = gcd[i+1].longValue();
					long MUL = GCD / LCM;
					System.out.println("MUL = " + MUL);
					for (long x=1; x * x <= MUL; x++) if (MUL % x == 0) {
						if (x*LCM >= L && x*LCM <= H)
							ans = Math.min(ans, x*LCM);
						if ((MUL/x)*LCM >= L && (MUL/x)*LCM <= H)
							ans = Math.min(ans, (MUL/x)*LCM);
					}
				}
			
			// print
			pw.println(ans == INF.longValue() ? "NO" : ans);
		}
		
		sc.close();
		pw.flush();
		pw.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new Fast()).doMain();
	}
}
