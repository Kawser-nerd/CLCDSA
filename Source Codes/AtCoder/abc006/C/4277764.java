import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();

		if (M < N*2 || N*4 < M) {
			System.out.println("-1 -1 -1");
			return;
		}

		int o = 0;
		int r = 0;
		int a = 0;

		for (int i = N; i >= 0; i--) {
			a = i;
			for (int j = 0; j <= 1; j++) {
				r = j;
				o = N-a-r;
				if (M == a*4 + r*3 + o*2) {
					System.out.println(o + " " + r + " " + a);
					return;
				}
			}
		}
		System.out.println("-1 -1 -1");
	}
}