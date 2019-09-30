import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();
		int X = sc.nextInt();

		int x[] = new int[N+1];
		x[0] = X;

		for (int i = 1; i <= N; i++) {
			x[i] = sc.nextInt();
		}
		Arrays.sort(x);

		int dif[] = new int[N];
		for (int i = 0; i < N; i++) {
			dif[i] = x[i+1] - x[i];
		}

		if (N == 1) {
			System.out.println(dif[0]);
			return;
		}

		int ans = gcd(dif[0],dif[1]);
		for (int i = 2; i < dif.length; i++) {
			ans = gcd(ans, dif[i]);
		}
		System.out.println(ans);
	}

	public static int gcd(int a, int b) {
		if (b==0) {
			return a;
		}
		return gcd(b,a%b);
	}
}