import java.math.BigDecimal;
import java.util.Arrays;
import java.util.Scanner;

public class ProblemA {
	
	public static void main(String[] args) throws Exception {
		
		try (Scanner sc = new Scanner(System.in)) 
		{
			int cases = sc.nextInt();
			
			for (int caseNum=1; caseNum<=cases; caseNum++)
			{
				solve(sc, caseNum);
			}
		}
	}
	
	static void solve(Scanner sc, int caseNum)
	{
		int N = sc.nextInt();
		int K = sc.nextInt();
		
		P[] ps = new P[N];
		for (int i=0; i<N; i++) {
			ps[i] = new P(sc.nextInt(), sc.nextInt());
		}
		Arrays.sort(ps);
		
		double max = -1;
		//BigDecimal max = BigDecimal.ZERO;
		for (int i=0; i<N-K+1; i++) {
			P[] ps2 = Arrays.copyOfRange(ps, i+1, N);
			Arrays.sort(ps2, (p1,p2) -> (Long.compare(p2.H*p2.R, p1.H*p1.R)));
			double area = Math.PI * ps[i].R * ps[i].R;
			area += Math.PI*ps[i].H*ps[i].R*2;
			//BigDecimal area = BigDecimal.valueOf(Math.PI).multiply(BigDecimal.valueOf(ps[i].R)).multiply(BigDecimal.valueOf(ps[i].R));
			//area = area.add(BigDecimal.valueOf(Math.PI).multiply(BigDecimal.ps[i].H*ps[i].R*2);
			for (int j=0; j<K-1; j++) {
				area += Math.PI*ps2[j].H*ps2[j].R*2;
			}
			max = Math.max(area, max);
		}
		
		System.out.printf("Case #%d: %.8f\n", caseNum, max);
	}
	
	static class P implements Comparable<P>
	{
		long R,H;

		public P(long r, long h) {
			super();
			R = r;
			H = h;
		}

		@Override
		public int compareTo(P arg0) {
			return Long.compare(arg0.R, R);
		}
		
	}
}
