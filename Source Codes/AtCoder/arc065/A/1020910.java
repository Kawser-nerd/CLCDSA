import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.nextLine();
		int n = s.length();
		boolean[] vis = new boolean[n + 1];
		vis[0] = true;
		for (int i = 0; i < n; ++i) {
			if (!vis[i])
				continue;
			if (i + 5 <= n) {
				String s5 = s.substring(i, i + 5);
				if (s5.equals("dream") || s5.equals("erase")) {
					vis[i + 5] = true;
				}
			}
			if (i + 6 <= n) {
				String s6 = s.substring(i, i + 6);
				if (s6.equals("eraser")) {
					vis[i + 6] = true;
				}
			}
			if (i + 7 <= n) {
				String s7 = s.substring(i, i + 7);
				if (s7.equals("dreamer")) {
					vis[i + 7] = true;
				}
			}
		}
		if (vis[n]) {
			System.out.println("YES");
		} else {
			System.out.println("NO");
		}
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}