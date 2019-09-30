import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();
		int T = sc.nextInt();

		int[] cs = new int[N];
		for (int i = 0; i < N; i++) {
			int c = sc.nextInt();
			if (sc.nextInt() <= T) {
				cs[i] = c;
			} else {
				cs[i] = 1001;
			}
		}
		Arrays.sort(cs);

		System.out.println(cs[0] <= 1000 ? cs[0] : "TLE");

		sc.close();
	}
}