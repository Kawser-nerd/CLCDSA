import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int H = sc.nextInt();

		Integer a[] = new Integer[N];
		Integer b[] = new Integer[N];

		int max = 0;
		int cnt = 0;

		for (int i = 0; i < N; i++) {
			a[i] = sc.nextInt();
			b[i] = sc.nextInt();
			max = Math.max(max, a[i]);
		}

		Arrays.sort(b);

		int x = N - 1;

		while (x >= 0 && b[x] > max && H > 0) {
			H -= b[x];
			x--;
			cnt++;
		}

		if (H > 0) {
			cnt += H / max;
			if (H % max != 0)
				cnt++;
		}

		System.out.println(cnt);
	}
}