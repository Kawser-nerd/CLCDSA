import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String[] s = new String[n];
		for (int i = 0; i < n; i++) {
			s[i] = sc.next();
		}
		int m = sc.nextInt();
		String[] t = new String[m];
		for (int i = 0; i < m; i++) {
			t[i] = sc.next();
		}
		int max = Integer.MIN_VALUE;
		for (int i = 0; i < n; i++) {
			int cb = 0;
			int cr = 0;
			for (int j = 0; j < n; j++) {
				if (s[i].equals(s[j]))
					cb++;
			}
			for (int j = 0; j < m; j++) {
				if (s[i].equals(t[j]))
					cr++;
			}
			if (max < cb - cr) {
				max = cb - cr;
			}
		}
		System.out.println(max > 0 ? max : 0);
		sc.close();
	}
}