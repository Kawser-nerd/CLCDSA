import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		long n = sc.nextLong();
		ArrayList<Long> list = new ArrayList<>();
		for (long i = Math.max(n - 9 * 18, 1); i < n; i++) {
			if (i + f(i) == n) {
				list.add(i);
			}
		}
		StringBuilder sb = new StringBuilder();
		sb.append(list.size()).append("\n");
		for (long x : list) {
			sb.append(x).append("\n");
		}
		System.out.print(sb);
	}
	
	static long f(long x) {
		long ans = 0;
		while (x > 0) {
			ans += x % 10;
			x /= 10;
		}
		return ans;
	}
}