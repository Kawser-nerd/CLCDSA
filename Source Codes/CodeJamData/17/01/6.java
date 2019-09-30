import java.util.*;

class A {
	static int solve() {
		int[] str  = in.next().chars().map((i) -> i == '+' ? 0 : 1).toArray();
		int   size = in.nextInt();
		
		int  count = 0;
		
		for (int i = 0; i < str.length - size + 1; ++i) {
			if (str[i] != 0) {
				count++;
				for (int j = i; j < i + size; ++j) {
					str[j] = str[j] == 1 ? 0 : 1;
				}
			}
		}
		
		for (int i = str.length - size + 1; i < str.length; ++i) {
			if (str[i] != 0)
				return -1;
		}
		
		return count;
	}
	
	static Scanner in = new Scanner(System.in);
	public static void main(String[] args) {
		int T = in.nextInt();
		
		for (int t = 0; t < T; ++t) {
			int c = solve();
			System.out.printf("Case #%d: %s%n", t + 1, c >= 0 ? Integer.toString(c) : "IMPOSSIBLE");
		}
	}
}