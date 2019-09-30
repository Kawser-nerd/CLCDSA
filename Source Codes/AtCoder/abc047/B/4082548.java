import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		@SuppressWarnings("resource")
		Scanner scan = new Scanner(System.in);

		int w = scan.nextInt();
		int h = scan.nextInt();
		int n = scan.nextInt();
		int[] xn = new int[n];
		int[] yn = new int[n];
		int[] an = new int[n];

		for (int i = 0; i < n; i++) {
			xn[i] = scan.nextInt();
			yn[i] = scan.nextInt();
			an[i] = scan.nextInt();
		}

		int wl = 0;
		int wr = w;
		int hl = 0;
		int ht = h;
		for (int i = 0; i < n; i++) {
			switch (an[i]) {
			case 1:
				if (wl < xn[i]) {
					wl = xn[i];
				}
				break;
			case 2:
				if (wr > xn[i]) {
					wr = xn[i];
				}
				break;
			case 3:
				if (hl < yn[i]) {
					hl = yn[i];
				}
				break;
			case 4:
				if (ht > yn[i]) {
					ht = yn[i];
				}
				break;
			}
		}
		if (wr - wl < 0 || ht - hl < 0) {
			System.out.println(0);
		} else {
			System.out.println((wr - wl) * (ht - hl));
		}
	}
}