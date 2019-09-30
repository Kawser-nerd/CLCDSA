import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] x = new int[n];
		int[] array = new int[n * n];
		int[] ref = new int[n * n];
		for (int i = 0; i < n; ++i) {
			x[i] = sc.nextInt();
			array[x[i] - 1] = i + 1;
			ref[x[i] - 1] = i + 1;
		}

		int pos = 0;
		for (int i = 0; i < n * n; ++i) {
			if (ref[i] > 0) {
				int cnt = 0;
				while (cnt < array[i] - 1) {
					if (array[pos] == 0) {
						array[pos] = array[i];
						++cnt;
					}
					++pos;
				}
			}
		}
		pos = n * n - 1;
		for (int i = n * n - 1; i >= 0; --i) {
			if (ref[i] > 0) {
				int cnt = 0;
				while (cnt < n - array[i]) {
					if (array[pos] == 0) {
						array[pos] = array[i];
						++cnt;
					}
					--pos;
				}
			}
		}

		for (int i = 0; i < n * n; ++i) {
			if (ref[i] > 0) {
				int cnt = 0;
				for (int j = 0; j < i; ++j) {
					if (array[j] == ref[i]) {
						++cnt;
					}
				}
				if (cnt != ref[i] - 1) {
					System.out.println("No");
					return;
				}
				for (int j = i + 1; j < n * n; ++j) {
					if (array[j] == ref[i]) {
						++cnt;
					}
				}
				if (cnt != n - 1) {
					System.out.println("No");
					return;
				}
			}
		}
		System.out.println("Yes");
		for (int i = 0; i < n * n; ++i) {
			System.out.print(array[i] + (i == n * n - 1 ? "\n" : " "));
		}

	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}