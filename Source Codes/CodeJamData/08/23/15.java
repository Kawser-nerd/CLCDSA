import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Locale;
import java.util.StringTokenizer;


public class Solution implements Runnable {

	void solve() throws Exception {
		int tc = nextInt();
		for (int tt = 0; tt < tc; tt++) {
			int k = nextInt();
			int n = nextInt();
			int[] d = new int[n];
			for (int i = 0; i < n; i++) {
				d[i] = nextInt() - 1;
			}

			ArrayList<Integer> list = new ArrayList<Integer>();
			list.add(k);
			int pos = 0;
			int card = k - 1;
			for (int i = 0; i < k - 1; i++) {
				for (int j = 0; j < card; j++) {
					pos--;
					if (pos < 0) {
						pos = list.size() - 1; 
					}
				}
				list.add(pos, card);
				card--;
			}
			
			int onePos = -1;
			for (int i = 0; i < k; i++) {
				if (list.get(i) == 1) {
					onePos = i;
				}
			}
			
			int[] ans = new int[k];

			for (int i = 0; i < k; i++) {
				ans[i] = list.get((onePos + i) % k);
			}
			
			
			out.print("Case #" + (tt + 1) +":");
			for (int i = 0; i < n; i++) {
				out.print(" " + (ans[d[i]]));
			}
			out.println();
			System.out.println(tt + 1);
		}
	}
	
	public static void main(String[] args) throws Exception {
		Locale.setDefault(Locale.US);
		new Thread(new Solution("c")).start();
	}

	private BufferedReader in;
	private StringTokenizer st;
	private PrintWriter out;
	
	public Solution(String fname) throws IOException {
		in = new BufferedReader(new FileReader(fname + ".in"));
		st = new StringTokenizer("");
		out = new PrintWriter(new FileWriter(fname + ".out"));
	}
	
	
	String nextToken() throws IOException {
		while (!st.hasMoreTokens()) {
			st = new StringTokenizer(in.readLine());
		}
		return st.nextToken();
	}
	
	int nextInt() throws NumberFormatException, IOException {
		return Integer.parseInt(nextToken());
	}
	
	public void run() {
		try {
			solve();
		} catch (Exception e) {
			apstenu(e);
		} finally {
			out.close();
		}
	}

	private void apstenu(Exception e) {
		e.printStackTrace();
		System.exit(1);
	}
	
}
