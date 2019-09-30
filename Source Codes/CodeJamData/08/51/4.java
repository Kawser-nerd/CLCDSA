import java.io.*;
import java.util.*;

/**
 * @author Mikhail Dvorkin
 */
public class A implements Runnable {
	private Scanner in;
	private PrintWriter out;

	private void solve(int testCase) {
		int l = in.nextInt();
		int m = 3010;
		int[] min = new int[2 * m];
		int[] max = new int[2 * m];
		Arrays.fill(min, 2 * m);
		int dx = 1;
		int dy = 0;
		int x = m;
		int y = m;
		long area = 0;
		for (int i = 0; i < l; i++) {
			String s = in.next();
			int t = in.nextInt();
			for (int j = 0; j < t; j++) {
				for (int k = 0; k < s.length(); k++) {
					char c = s.charAt(k);
					if (c == 'F') {
						x += dx;
						y += dy;
						if (dy == 0) {
							int xx = x;
							if (dx > 0) {
								area += y;
								xx--;
							} else if (dx < 0) {
								area -= y;
							}
							min[xx] = Math.min(min[xx], y);
							max[xx] = Math.max(max[xx], y);
						}
					} else if (c == 'L') {
						int d = dx;
						dx = dy;
						dy = -d;
					} else {
						int d = dx;
						dx = -dy;
						dy = d;
					}
				}
			}
		}
		area = Math.abs(area);
		
		int left = 0;
		while (max[left] == 0)
			left++;
		int right = 2 * m - 1;
		while (max[right] == 0)
			right--;
		long ans = 0;

		int mid = left;
		for (int i = left; i <= right; i++) {
			if (max[i] > max[mid])
				mid = i;
		}
		y = max[left];
		for (int i = left; i <= mid; i++) {
			y = Math.max(y, max[i]);
			ans += y;
		}
		y = max[right];
		for (int i = right; i > mid; i--) {
			y = Math.max(y, max[i]);
			ans += y;
		}

		mid = left;
		for (int i = left; i <= right; i++) {
			if (min[i] < min[mid])
				mid = i;
		}
		y = min[left];
		for (int i = left; i <= mid; i++) {
			y = Math.min(y, min[i]);
			ans += 2 * m - y;
		}
		y = min[right];
		for (int i = right; i > mid; i--) {
			y = Math.min(y, min[i]);
			ans += 2 * m - y;
		}
		ans -= 2 * (long) m * (right - left + 1L);
		out.println("Case #" + testCase + ": " + (ans - area));
	}

	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		new Thread(new A()).start();
	}

	public void run() {
		try {
			in = new Scanner(new FileReader("a.in"));
			out = new PrintWriter("a.out");
			int n = in.nextInt();
			for (int i = 1; i <= n; i++)
				solve(i);
			in.close();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(1);
		}
	}
}
