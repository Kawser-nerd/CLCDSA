import java.util.Scanner;

public class B {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int T = s.nextInt();
		for (int i = 0; i < T; i++) {
			int L = s.nextInt();
			int P = s.nextInt();
			long C = s.nextInt();

				System.out.printf("Case #%d: %d\n", i + 1, calc(L, P, C));
		}
	}

	public static int calc(int min, int max, long C) {

		if(C*C < C){
			return 0;
		}
		if (min * C < max) {
			return calc(min,  max, (C * C)) + 1;
		} else {
			return 0;
		}

	}
}
