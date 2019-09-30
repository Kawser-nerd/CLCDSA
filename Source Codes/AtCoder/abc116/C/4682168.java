import java.io.InputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class Main {
	InputStream in = System.in;
	PrintStream out = System.out;

	int next(int[] h, int idx) {
		for (int i = idx; i < h.length; i++) {
			if (h[i] != 0) {
				return i;
			}
		}
		return -1;
	}

	public void _main(String[] args) {
		Scanner sc = new Scanner(in);

		int n = sc.nextInt();
		int[] h = new int[n];
		for (int i = 0; i < n; i++) {
			h[i] = sc.nextInt();
		}

		int ans = 0;
		int idx = 0;
		while (true) {
			idx = next(h, idx);
			if (idx == -1) {
				break;
			}

			while (h[idx] > 0) {
				ans++;
				for (int i = idx; i < n && h[i] > 0; i++) {
					h[i]--;
				}
			}
		}

		out.println(ans);

		sc.close();

	}

	public static void main(String[] args) {
		new Main()._main(args);
	}

}