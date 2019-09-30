import java.util.Arrays;
import java.util.Scanner;

public class Main {
	static String S;

	public static void main(String[] args) {
		readInput();

		solve();
	}

	static void solve() {
		char[] c_array = S.toCharArray();
		
		int[] sum = new int['z'- 'a' + 1];
		for(int idx = 0; idx < c_array.length; idx++) {
			sum[c_array[idx] - 'a']++;
		}
		
		long ans = 0;
		
		long[] conv = new long[1 << 26];
		Arrays.fill(conv, -1);
		conv[0] = 1;
		
		int max = 1 << 26;
		
		for(int bit = 1; bit < max; bit++) {
			conv[bit] = 0;
			
			for(int idx = 0; idx < 26; idx++) {
				int b_idx = 1 << idx;
				if((bit & b_idx) > 0) {
					conv[bit] = (conv[bit - b_idx] * sum[idx]) % 1000000007;
					break;
				}
			}
			
			ans = (ans + conv[bit]) % 1000000007;
		}
		
		System.out.println(ans);
	}
	

	static void readInput() {
		try (Scanner sc = new Scanner(System.in)) {
			sc.nextLine();
			S = sc.nextLine();
		}
	}
}