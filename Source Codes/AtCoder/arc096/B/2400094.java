import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long C = sc.nextLong();
		long[][] arraytmp = new long[N][2];
		long[][] arraytmp2 = new long[N][2];
		long[][] array = new long[N + 2][2];
		long[][] array2 = new long[N + 2][2];
		for (int i = 0; i < N; i++) {
			arraytmp[i][0] = sc.nextLong();
			arraytmp[i][1] = sc.nextLong();
		}
		System.arraycopy(arraytmp, 0, arraytmp2, 0, N);
		Arrays.sort(arraytmp, (a, b) -> Long.compare(a[0], b[0]));
		Arrays.sort(arraytmp2, (b, a) -> Long.compare(a[0], b[0]));
		System.arraycopy(arraytmp, 0, array, 1, N);
		System.arraycopy(arraytmp2, 0, array2, 1, N);
		array[0][0] = 0;
		array[0][1] = 0;
		array[N + 1][0] = C;
		array[N + 1][1] = 0;
		array2[0][0] = C;
		array2[0][1] = 0;
		array2[N + 1][0] = 0;
		array2[N + 1][1] = 0;

		long ans = 0;

		long[] memo = new long[N + 2];
		long go = 0;
		long stop = 0;
		for (int i = 1; i < N + 1; i++) {
			if (array[i][1] - array[i][0] >= 0) {
				go += array[i][1] - array[i][0] + array[i - 1][0];
			} else {
				stop = Math.max(stop, go);
				go += array[i][1] - array[i][0] + array[i - 1][0];
			}
			memo[i + 1] = Math.max(go, stop);
		}
		long[] memo2 = new long[N + 2];
		long go2 = 0;
		long stop2 = 0;
		for (int i = 1; i < N + 1; i++) {
			if (array2[i][1] - (C - array2[i][0]) >= 0) {
				go2 += array2[i][1] - (C - array2[i][0]) + (C - array2[i - 1][0]);
			} else {
				stop2 = Math.max(stop2, go2);
				go2 += array2[i][1] - (C - array2[i][0]) + (C - array2[i - 1][0]);
			}
			memo2[i + 1] = Math.max(go2, stop2);
		}
		long first = 0;
		long total = 0;
		for (int k = 0; k < N + 2; k++) {
			if (k != 0) {
				first += array2[k][1] - 2 * (C - array2[k][0] - (C - array2[k - 1][0]));
			}
			long tmp = memo[N + 1 - k];
			total = Math.max(total, first + tmp);
		}
		long first2 = 0;
		long total2 = 0;
		for (int k = 0; k < N + 2; k++) {
			if (k != 0) {
				first2 += array[k][1] - 2 * (array[k][0] - (array[k - 1][0]));
			}
			long tmp = memo2[N + 1 - k];
			total2 = Math.max(total2, first2 + tmp);
		}
		ans = Math.max(total, total2);

		System.out.println(ans);
	}
}