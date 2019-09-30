import java.util.Arrays;
import java.util.Scanner;

public class Main {
	private static final long DEV_NUM = 1000000000 + 7;
	private static final int MAX_COLOR_NUM = 2 * 100000;
	
	int[] jumpIndex = null;
	long[] patterns = null;
	int N = 0;

	public void solve() {
		Scanner in = new Scanner(System.in);
		N = in.nextInt();
		int[] color = new int[N];
		for (int i=0; i<N; i++) {
			color[i] = in.nextInt();
		}
		in.close();

		patterns = new long[N];
		Arrays.fill(patterns, -1);
		jumpIndex = new int[N];
		Arrays.fill(jumpIndex, -1);
		int[] beforeIndex = new int[MAX_COLOR_NUM+1];
		Arrays.fill(beforeIndex, -1);
		for (int i=0; i<N; i++) {
			int c = color[i];
			if (beforeIndex[c] == -1) {
				beforeIndex[c] = i;
			} else if (beforeIndex[c] == i-1) {
				beforeIndex[c] = i;
			} else {
				jumpIndex[beforeIndex[c]] = i;
				beforeIndex[c] = i;
			}
		}

		for (int i=N-1; i>=0; i--) {
			patterns[i] = getPatterns(i);
		}
		
		System.out.println(patterns[0]);
	}
	
	private long getPatterns(int index) {
		if (index >= N-2) {
			return 1;
		}
		long unjumpPatterns = patterns[index+1];
		long jumpPatterns = 0;
		if (jumpIndex[index] != -1) {
			jumpPatterns = patterns[jumpIndex[index]];
		}
		
		return (unjumpPatterns + jumpPatterns) % DEV_NUM;
	}
	
	public static void main(String[] args) {
		Main main = new Main();
		main.solve();
	}
}