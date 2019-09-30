import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int h = in.nextInt();
		int w = in.nextInt();
		String[] a = new String[h];
		for (int i = 0; i < h; i++) {
			a[i] = in.next();
		}

		boolean[] row = new boolean[h];
		Arrays.fill(row, false);
		boolean[] col = new boolean[w];
		Arrays.fill(col, false);
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (a[i].charAt(j) == '#') {
					row[i] = true;
					col[j] = true;
				}
			}
		}

		for (int i = 0; i < h; i++) {
			if (row[i]) {
				for (int j = 0; j < w; j++) {
					if (col[j]) {
						System.out.print(a[i].charAt(j));
					}
				}
				System.out.println();
			}
		}
	}
}