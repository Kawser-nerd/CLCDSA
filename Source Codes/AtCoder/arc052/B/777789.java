import java.util.Scanner;

public class Main {
	int N, Q;
	long[][] ensui;

	public static void main(String[] args) {
		new Main().run();
	}
	
	public void run() {
		Scanner sc = new Scanner(System.in);
		
		N = sc.nextInt();
		Q = sc.nextInt();
		ensui = new long[N][3];
		for (int i = 0; i < N; i++) {
			ensui[i][0] = sc.nextLong();
			ensui[i][1] = sc.nextLong();
			ensui[i][2] = sc.nextLong();
		}
		
		double[] ans = new double[Q];
		for (int i = 0; i < Q; i++) {
			int A = sc.nextInt();
			int B = sc.nextInt();
			ans[i] = solve(A, B);
		}
		
		for (int i = 0; i < Q; i++) {
			System.out.println(ans[i]);
		}
		
		sc.close();
	}

	private double solve(int a, int b) {
		double ans = 0;
		for (int i = 0; i < N; i++) {
			long X = ensui[i][0];
			long R = ensui[i][1];
			long H = ensui[i][2];
			if (X + H <= a || b <= X) {
				continue;
			} else {
				double S = (Math.PI * R * R * H) / 3;
				double sumS, subS;
				if (X < a) {
					sumS = S * Math.pow(((double)(H - (a - X))) / H, 3);
				} else sumS = S;
				ans += sumS;
				if (b < X + H) {
					subS = S * Math.pow(((double)(H + X - b)) / H, 3);
					ans -= subS;
				}
			}
		}
		return ans;
	}

}