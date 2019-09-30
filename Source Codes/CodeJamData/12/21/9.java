import java.util.Scanner;


public class A {

	static Scanner in = new Scanner(System.in);

	void solve() {
		int N = in.nextInt();
		int[] s = new int[N];
		int X = 0;
		for (int i=0; i<N; ++i) {
			s[i] = in.nextInt();
			X+=s[i];
		}
		for (int i=0; i<N; ++i) {
			double a=0.0;
			double b=1.0;
			for (int q=0; q<100; ++q) {
				double c = (a+b)/2;
				double val = s[i] + c*X;
				double used = c*X;
				for (int j=0; j<N; ++j) {
					if (i==j) continue;
					if (s[j]>=val) continue;
					used += val - s[j];
				}
				if (used >= X) {
					b = c;
				} else {
					a = c;
				}
			}
			System.out.print(String.format(" %.6f", 100*a).replace(",","."));
		}
		System.out.println();
	}
	
	
	public static void main(String[] args) {
		int T = in.nextInt();
		for (int i=1; i<=T; ++i) {
			System.out.print("Case #" + i + ":");
			new A().solve();
		}

	}

}
