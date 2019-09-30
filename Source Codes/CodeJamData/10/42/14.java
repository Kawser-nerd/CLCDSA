import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;


public class B {

	public static void main(String[] args) throws IOException {
		new B().run();
	}

	
	BufferedReader br;
	PrintWriter pw;
	
	int p, n;
	int[] miss;
	int[][] price;
	
	int[][][] d;
	final int inf = Integer.MAX_VALUE;
	
	private void run() throws IOException {
		br = new BufferedReader(new FileReader("b.in"));
		pw = new PrintWriter("b.out");
		
		int tests = Integer.parseInt(br.readLine());
		for (int test = 1; test <= tests; test++) {
			p = Integer.parseInt(br.readLine());
			n = 1 << p;
			miss = new int[n];
			StringTokenizer st = new StringTokenizer(br.readLine());
			for (int i = 0; i < n; i++) {
				miss[i] = p - Integer.parseInt(st.nextToken());
			}
			
			price = new int[p][];
			for (int i = 0; i < p; i++) {
				st = new StringTokenizer(br.readLine());
				int c = 1 << (p - i - 1);
				price[i] = new int[c];
				for (int j = 0; j < c; j++) {
					price[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			
			d = new int[p][n][p];
			for (int i = 0; i < p; i++) {
				for (int j = 0; j < n; j++) {
					Arrays.fill(d[i][j], -1);
				}
			}
			
			pw.println("Case #" + test + ": " + get(p - 1, 0, 0));
		}
		
		br.close();
		pw.close();
	}

	private int get(int level, int x, int got) {
		if (d[level][x][got] != -1) {
			return d[level][x][got];
		}
		int left = x * 2;
		int right = x * 2 + 1;

		int result = inf;
		if (level == 0) {
			int take = 0;
			if (miss[left] > got || miss[right] > got) {
				take = 1;
			}
			if (miss[left] > got + take || miss[right] > got + take) {
				result = inf;
			} else {
				result = take * price[level][x];
			}
		} else {
			int leftr = get(level - 1, left, got);
			int rightr = get(level - 1, right, got);
			if (leftr < inf && rightr < inf) {
				result = Math.min(result, leftr + rightr);
			}
			
			leftr = get(level - 1, left, got + 1);
			rightr = get(level - 1, right, got + 1);
			if (leftr < inf && rightr < inf) {
				result = Math.min(result, leftr + rightr + price[level][x]);
			}
		}
		
		return (d[level][x][got] = result);
	}

}
