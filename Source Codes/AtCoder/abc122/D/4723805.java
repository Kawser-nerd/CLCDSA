import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Main {

	private static int N = 0;
	private static long MOD = 1000000007L;
	private static List<Map<String, Long>> memo = new ArrayList<Map<String, Long>>();
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		N = sc.nextInt();
		for (int i = 0; i <= N; i++) {
			memo.add(new HashMap<String, Long>());
		}

		System.out.println(dfs(0, "TTT"));

	}

	private static boolean ok(String last4) {
		for (int i = 0; i < 4; i++) {
			char[] t = last4.toCharArray();

			if (i >= 1) {
				char buf = t[i-1];
				t[i-1] = t[i];
				t[i] = buf;
			}
			if (String.valueOf(t).indexOf("AGC") >= 0) {
				return false;
			}
		}
		return true;
	}

	private static long dfs(int cur, String last3) {
//		System.out.println(cur);
		if (memo.get(cur).containsKey(last3)) {
			return memo.get(cur).get(last3);
		}

		if (cur == N) {
			return 1;
		}

		long ret = 0;

		char[] cList = {'A','C','G','T'};

		for (char c : cList) {
			if (ok(last3 + c)) {
				ret = (ret + dfs(cur + 1, last3.substring(1) + c)) % MOD;
			}
		}

		memo.get(cur).put(last3, ret);

		return ret;
	}

}