import java.util.Scanner;

public class D {

	static int CASE;
	static Scanner in = new Scanner(System.in);
	
	public static void main(String[] args) {
		int T = in.nextInt();
		for (CASE=1; CASE<=T; ++CASE) {
			new D().go();
		}
	}
	
	int A1 = in.nextInt();
	int A2 = in.nextInt();
	int B1 = in.nextInt();
	int B2 = in.nextInt();
	
	static boolean win(int a, int b) {
		if (b>a) {
			int t = b;
			b = a;
			a = t;
		}
		if (a >= 2*b) return true;
		if (b == 0) return true;
		return !win(b, a-b);
	}
	
	int minfalse(int N) {
		int a = 1;
		int b = N;
		while (a < b) {
			int c = (a+b)/2;
			if (win(c, N)) {
				a = c+1;
			} else {
				b = c;
			}
		}
		return a;
	}
	
	int maxfalse(int N) {
		int a = N;
		int b = 2*N;
		while (a < b) {
			int c = (a+b+1)/2;
			if (win(c, N)) {
				b = c-1;
			} else {
				a = c;
			}
		}
		return a;
	}
	
	void go() {
		long ans = 0;
		for (int a=A1; a<=A2; ++a) {
			int minf = minfalse(a);
			int maxf = maxfalse(a);
			if (B1 < minf) {
				ans += Math.min(B2, minf-1) - B1 + 1;
			}
			if (B2 > maxf) {
				ans += B2 - Math.max(B1, maxf+1) + 1;
			}
		}
		System.out.println("Case #" + CASE + ": " + ans);
	}
	
}
