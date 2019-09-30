import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int h = sc.nextInt();
		int w = sc.nextInt();

		String[] s = new String[h];

		int l = 0;
		for (int i = 0; i < h; i++) {
			String str = sc.next();
			if (!str.matches("[.]+")) {
				s[l++] = str;
			}
		}

		boolean[] b = new boolean[w];
		outer:
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < l; j++) {
				if (s[j].charAt(i) == '#') {
					continue outer;
				}
			}
			b[i] = true;
		}

		for (int i = 0; i < l; i++) {
			for (int j = 0; j < w; j++) {
				if (b[j])
					continue;
				System.out.print(s[i].charAt(j));
			}
			System.out.println();
		}

		sc.close();
	}
}