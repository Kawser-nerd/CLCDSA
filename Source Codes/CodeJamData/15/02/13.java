package CodeJam2015;

import java.util.Scanner;

public class B {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int cases = 1; cases <= T; cases++) {
			int D = sc.nextInt();
			int P[] = new int[D];
			for (int i = 0; i < D; i++)
				P[i] = sc.nextInt();
			
			int best = P[0];
			for (int i = 1; i < D; i++)
				best = Math.max(best, P[i]);
			
			for (int n = 1; n < best; n++) {
				int s = 0;
				for (int i = 0; i < D; i++)
					s += (P[i] % n) == 0 ? P[i]/n - 1 : P[i]/n;
				//System.out.println(s + n);
				if (s + n < best)
					best = s+n;
			}
			
			System.out.println("Case #" + cases + ": " + best);
		}
		sc.close();
	}

}
/*
3
1
3
4
1 2 1 2
1
4
*/