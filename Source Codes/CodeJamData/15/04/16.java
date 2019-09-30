import java.util.Scanner;

public class D {

	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int T = sc.nextInt();
		for (int i = 1; i <= T; ++i) {
			System.out.printf("Case #%d: %s\n", i, solve() ? "GABRIEL" : "RICHARD");
		}
	}

	static boolean solve() {
		int X = sc.nextInt();
		int R = sc.nextInt();
		int C = sc.nextInt();
		if (R * C % X != 0) return false;
		if (R < C) {
			int tmp = R;
			R = C;
			C = tmp;
		}
		if (R < X) return false;
		if (X == 1) return true;
		if (X == 2) return true;
		if (X == 3) return C > 1;
		if (X == 4) return C > 2;
		if (X == 5) return C > 2 && R * C > 15;
		if (X == 6) return C > 3;
		return false; // X >= 7
	}
}
