import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	static Pancake[] p;
	static Double[][] memo;
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new File("A.in"));
		PrintWriter out = new PrintWriter(new File("A.out"));
		int T = sc.nextInt();
		for (int t = 1; t <= T; t++) {
			int N = sc.nextInt();
			int K = sc.nextInt();
			memo = new Double[N+1][K+1];
			p = new Pancake[N];
			for (int a = 0; a < N; a++) {
				p[a] = new Pancake(sc.nextInt(), sc.nextInt());
			}

			Arrays.sort(p);

			double ans = DP(N-1,K);
			
//			for (int x = 0; x < N; x++) {
//				double tempAns = 0;
//				tempAns += Math.PI * p[x].R * p[x].R;
//				tempAns += 2.0 * Math.PI * p[x].R * p[x].H;
//
//				int max = K - 1;
//				for (int a = 0; a < max; a++) {
//					if (a == x) {
//						max++;
//						continue;
//					}
//					tempAns += 2.0 * Math.PI * p[a].R * p[a].H;
//				}
//				ans = Math.max(ans, tempAns);
//			}

			System.out.printf("Case #%d: %.12f%n", t, ans);
			out.printf("Case #%d: %.12f%n", t, ans);
		}
		out.close();
	}

	private static double DP(int i, int k) {
		if(i<0||k<=0)return 0;
		if(memo[i][k]!=null) return memo[i][k];
		double ans = DP(i-1,k-1);
		if(k==1){
			ans+= Math.PI * p[i].R * p[i].R;
		}
		ans += 2.0 * Math.PI * p[i].R * p[i].H;
		
		ans = Math.max(ans, DP(i-1,k));
		return memo[i][k]=ans;
	}

	static class Pancake implements Comparable<Pancake> {
		int R, H;

		Pancake(int a, int b) {
			R = a;
			H = b;
		}

		@Override
		public int compareTo(Pancake that) {
			return (that.R - this.R);
		}
	}
}
