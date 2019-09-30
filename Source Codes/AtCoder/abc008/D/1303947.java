import java.util.*;


public class Main {
	int N;
	private int[] x;
	private int[] y;
	private HashMap<String, Integer> hashMap;
        
	public void solve() {
		Scanner scanner = new Scanner(System.in);
		int W = scanner.nextInt();
		int H = scanner.nextInt();
		N = scanner.nextInt();
		x = new int[N];
		y = new int[N];
		for (int i = 0; i < N; i++) {
			x[i] = scanner.nextInt() - 1;
			y[i] = scanner.nextInt() - 1;
		}
		scanner.close();

		hashMap = new HashMap<String, Integer>();
		int max = dfs(0, 0, W - 1, H - 1);
		System.out.println(max);
	}

	private int dfs(int w1, int h1, int w2, int h2) {
		if (w1 > w2 || h1 > h2) {
			return 0;
		}
		String key = hash(w1, h1, w2, h2);
		if (hashMap.containsKey(key)) {
			return hashMap.get(key);
		}

		int max = 0;
		for (int i = 0; i < N; i++) {
			if (x[i] < w1 || w2 < x[i] || y[i] < h1 || h2 < y[i]) {
				continue;
			}
			int earn = (w2 - w1) + (h2 - h1) + 1;
			earn += dfs(w1, h1, x[i] - 1, y[i] - 1);// ??
			earn += dfs(x[i] + 1, h1, w2, y[i] - 1);// ??
			earn += dfs(w1, y[i] + 1, x[i] - 1, h2);// ??
			earn += dfs(x[i] + 1, y[i] + 1, w2, h2);// ??

			max = Math.max(max, earn);
		}
		hashMap.put(key, max);
		return max;
	}

	private String hash(int w1, int h1, int w2, int h2) {
		return w1 + "_" + h1 + "_" + w2 + "_" + h2;

        }

	public static void main(String[] args){
		new Main().solve();
	}

}