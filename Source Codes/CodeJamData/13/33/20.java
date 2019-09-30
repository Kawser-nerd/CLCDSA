import java.io.*;
import java.util.*;

public class GreatWallSmall {

	FastScanner in;
	PrintWriter out;
	
	final int MAX_DAYS = 676060;

	class Attack implements Comparable<Attack> {
		int tribe, day;
		int number;
		
		public Attack(int tribe, int day, int number) {
			super();
			this.tribe = tribe;
			this.day = day;
			this.number = number;
		}
		
		@Override
		public int compareTo(Attack o) {
			return day - o.day;
		}

		@Override
		public String toString() {
			return "Attack [tribe=" + tribe + ", day=" + day + ", number="
					+ number + "]";
		}
		
		
	}
	
	void solve() {
		int n = in.nextInt();
		int[] d = new int[n], attacksCount = new int[n];
		int[] w = new int[n], e = new int[n];
		int[] s = new int[n];
		int[] dd = new int[n], dp = new int[n], ds = new int[n];
		for (int i = 0; i < n; i++) {
			d[i] = in.nextInt();
			attacksCount[i] = in.nextInt();
			w[i] = in.nextInt();
			e[i] = in.nextInt();
			s[i] = in.nextInt();
			dd[i] = in.nextInt();
			dp[i] = in.nextInt();
			ds[i] = in.nextInt();
		}
		
		List<Attack> attacks = new ArrayList<Attack>();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < attacksCount[i]; j++) {
				attacks.add(new Attack(i, d[i] + dd[i] * j, j));
			}
		}
		
		Collections.sort(attacks);
//		System.err.println(attacks);
		
		final int WALL_LENGTH = 1000;
		final int SHIFT = 500;
		int[] wall = new int[WALL_LENGTH + 1];
		
		int countSuccesses = 0;
		
		for (int i = 0; i < attacks.size(); ) {
			int j = i + 1;
			while (j < attacks.size() && attacks.get(j).day == attacks.get(i).day) {
				j++;
			}
			
			for (int k = i; k < j; k++) {
				int tribe = attacks.get(k).tribe;
				int attackNumber = attacks.get(k).number;
				int left = w[tribe] + dp[tribe] * attackNumber;
				int right = e[tribe] + dp[tribe] * attackNumber;
				int strength = s[tribe] + ds[tribe] * attackNumber;
				
				for (int pos = left; pos < right; pos++) {
					if (strength > wall[pos + SHIFT]) {
						countSuccesses++;
						break;
					}
				}
			}
			
			for (int k = i; k < j; k++) {
				int tribe = attacks.get(k).tribe;
				int attackNumber = attacks.get(k).number;
				int left = w[tribe] + dp[tribe] * attackNumber;
				int right = e[tribe] + dp[tribe] * attackNumber;
				int strength = s[tribe] + ds[tribe] * attackNumber;
				
				for (int pos = left; pos < right; pos++) {
					wall[pos + SHIFT] = Math.max(wall[pos + SHIFT], strength);
				}
			}
			
			i = j;
		}
		
		out.println(countSuccesses);
	}
	
	
	

	void run() {
		try {
			in = new FastScanner(new File("input.txt"));
			out = new PrintWriter("output.txt");

			int tests = in.nextInt();
			for (int i = 0; i < tests; i++) {
				out.printf("Case #%d: ", (i + 1));
				solve();
			}

			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(File file) {
			try {
				br = new BufferedReader(new FileReader(file));
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] args) {
		new GreatWallSmall().run();
	}
}
