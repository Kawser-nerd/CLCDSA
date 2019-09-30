import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int r, g, b;
		r = sc.nextInt();
		g = sc.nextInt();
		b = sc.nextInt();
		int[] f = new int[r + g + b + 1];
		Arrays.fill(f, Integer.MAX_VALUE / 3);
		f[r + g + b] = 0;
		for (int i = -1000; i <= 1000; ++i) {
			for (int res = 1; res <= r + g + b; ++res) {
				if (res > g + b) {
					f[res - 1] = Math.min(f[res - 1], f[res] + Math.abs(-100 - i));
				} else if (res > b && g + b >= res) {
					f[res - 1] = Math.min(f[res - 1], f[res] + Math.abs(i));
				} else {
					f[res - 1] = Math.min(f[res - 1], f[res] + Math.abs(100 - i));
				}
			}
		}
		System.out.println(f[0]);

	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

}