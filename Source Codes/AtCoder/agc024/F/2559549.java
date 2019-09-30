import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	static final int MAX = 22;
	static int N, K;
	
	static int[][] next;
	
	static int calcNext(int n, int dig) {
		for (int i = MAX; i >= 0; i--) {
			if ((n & (1 << i)) != 0) {
				for (int j = i - 1; j >= 0; j--) {
					if (((n & (1 << j))) == 0 == (dig == 0)) {
						return n & ((1 << j) - 1) | (1 << j);
					}
				}
			}
		}
		return 0;
	}
	
	static char[] current;
	static char[] best;
	static int[][] count;
	
	static void bt(int pos) {
		if (pos > best.length) {
			best = Arrays.copyOf(current, pos);
		} else if (pos == best.length) {
			boolean copy = false;
			for (int i = 0; i < best.length; i++) {
				if (best[i] < current[i] && !copy) break;
				else if (copy || best[i] > current[i]) {
					copy = true;
					best[i] = current[i];
				}
			}
		}
		for (int j = 0; j < 2; j++) {
			int total = 0;
			for (int i = 1; i < count[pos].length; i++) {
				int vec = next[i][j];
				count[pos + 1][vec] += count[pos][i];
				if (vec > 0) total += count[pos][i];
			}
			if (total >= K) {
				current[pos] = (char)('0'+ j);
				bt(pos+1);
			}
			for (int i = 1; i < count[pos].length; i++) {
				count[pos + 1][next[i][j]] -= count[pos][i];
			}
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		N = sc.nextInt();
		K = sc.nextInt();
		next = new int[1 << (N + 1)][2];
		for (int i = 1; i < next.length; i++) {
			next[i][0] = calcNext(i, 0);
			next[i][1] = calcNext(i, 1);
		}
		count = new int[N+2][];
		for (int i = 0; i < count.length; i++) {
			count[i] = new int[1<<(N + 1 - i)];
		}
		int offset = 1;
		for (int i = 0; i <= N; i++) {
			char[] tmp = sc.next().toCharArray();
			for (int j = 0; j < tmp.length; j++) {
				if (tmp[j] == '1') count[0][offset+j] = 1;
			}
			offset *= 2;
		}
		best = new char[0];
		current = new char[N+1];
		bt(0);
		System.out.println(new String(best));
	}
}