import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		solve();
	}

	private static void solve() {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] t = new int[N];
		int[] v = new int[N];

		for (int i = 0; i < N; i++) {
			t[i] = sc.nextInt();
		}

		for (int i = 0; i < N; i++) {
			v[i] = sc.nextInt();
		}
		sc.close();

		int totalTime = 0;
		for (int i = 0; i < N; i++) {
			totalTime += t[i];
		}

		int[] vmax = new int[totalTime * 2 + 1];
		vmax[0] = 0;

		int elapsed = 0;

		for (int i = 0; i < N; i++) {
			for (int j = elapsed * 2 + 1; j < (elapsed * 2 + 1) + (t[i] * 2); j++) {
				vmax[j] = v[i];
			}
			elapsed += t[i];
		}
		vmax[totalTime * 2] = 0;

		double[] vact = new double[totalTime * 2 + 1];
		vact[0] = 0;

		for (int i = 1; i < vact.length - 1; i++) {
			vact[i] = Math.min(vact[i - 1] + 0.5, vmax[i]);
		}

		vact[vact.length - 1] = 0;

		for (int i = vact.length - 2; i > 0; i--) {
			if (vmax[i] > vmax[i + 1] && vmax[i + 1] != 0) {
				vact[i] = Math.min(vact[i + 1] + 0.5, Math.min(vact[i], vmax[i + 1]));
			} else {
				vact[i] = Math.min(vact[i + 1] + 0.5, Math.min(vact[i], vmax[i]));
			}
		}

		double area = 0;
		for (int i = 0; i < vact.length - 1; i++) {
			area += (vact[i] + vact[i + 1]) * 0.5 / 2;
		}
		System.out.println(area);
	}
}