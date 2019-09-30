import java.util.Scanner;

public class Main {
	static int n;
	static int[] a = new int[50];
	static int[] b = new int[50];

	public static void main(String[] args) {
		final Scanner sc = new Scanner(System.in);

		n = sc.nextInt();

		for (int i = 0; i < n; i++)
			a[i] = sc.nextInt();
		for (int i = 0; i < n; i++)
			b[i] = sc.nextInt();

		long ans = (1L << 51) - 1;//51?

		if (!DrawEdge(ans)) {
			System.out.println(-1);
			return;
		}

		for (int i = 51; i >= 0; i--) {
			Long tmp = ans & ~(1L << i);
			if (DrawEdge(tmp)) {
				ans = tmp;
			}
		}

		System.out.println(ans);
	}

	static void priArr(boolean[][] arr) {
		for (boolean[] ar : arr) {
			for (boolean b : ar) {
				System.out.print(b ? "T " : "F ");
			}
			System.out.println();
		}
	}

	static boolean DrawEdge(long bit) {
		boolean[][] arr = new boolean[51][51];

		for (int i = 0; i <= 50; i++) {
			arr[i][i] = true;
		}

		for (int k = 1; k <= 50; k++) {
			if ((bit & (1L << k)) != 0) {
				for (int v1 = 0; v1 <= 50; v1++) {
					arr[v1][v1 % k] = true;
				}
			}
		}

		for (int k = 0; k <= 50; k++) {
			for (int i = 0; i <= 50; i++) {
				for (int j = 0; j <= 50; j++) {
					arr[i][j] |= arr[i][k] & arr[k][j];
				}
			}
		}

		for (int i = 0; i < n; i++) {
			if (!arr[a[i]][b[i]]) {
				return false;
			}
		}
		return true;
	}
}