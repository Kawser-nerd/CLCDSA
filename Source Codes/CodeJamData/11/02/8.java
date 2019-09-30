import java.io.*;
import java.util.*;
import java.math.*;

public class Main implements Runnable {
	String file = "B-large";

	private void solve() throws IOException {
		int tn = nextInt();
		for (int testN = 1; testN <= tn; ++testN) {
			Map<String, Character> combine = new HashMap<String, Character>();
			int[] was = new int[28];
			boolean[][] opposed = new boolean[28][28];
			int combs = nextInt();
			for (int i = 0; i < combs; ++i) {
				String s = next();
				combine.put(s.substring(0, 2), s.charAt(2));
			}
			int opps = nextInt();
			for (int i = 0; i < opps; ++i) {
				String s = next();
				opposed[s.charAt(0) - 'A'][s.charAt(1) - 'A'] = true;
				opposed[s.charAt(1) - 'A'][s.charAt(0) - 'A'] = true;
			}
			next();
			String played = next();
			ArrayList<Character> ans = new ArrayList<Character>();
			for (char character : played.toCharArray()) {
				int c = character - 'A';
				++was[c];

				if (ans.size() > 0
						&& combine.containsKey("" + character
								+ ans.get(ans.size() - 1))) {
					--was[c];
					--was[ans.get(ans.size() - 1) - 'A'];
					char t = combine.get("" + character
							+ ans.get(ans.size() - 1));
					ans.remove(ans.size() - 1);
					ans.add(t);
				} else if (ans.size() > 0
						&& combine.containsKey("" + ans.get(ans.size() - 1)
								+ character)) {
					--was[c];
					--was[ans.get(ans.size() - 1) - 'A'];
					char t = combine.get("" + ans.get(ans.size() - 1)
							+ character);
					ans.remove(ans.size() - 1);
					ans.add(t);
				} else {
					for (int i = 0; i < 28; ++i) {
						if (was[i] != 0 && opposed[c][i]) {
							ans.clear();
							Arrays.fill(was, 0);
							break;
						}
					}
					if (was[c] != 0) {
						ans.add(character);
					}
				}
			}
			out.printf("Case #%d: %s\n", testN, ans.toString());
		}
	}

	public static void main(String[] args) {
		new Thread(new Main()).start();
	}

	StringTokenizer tok;
	PrintWriter out;
	BufferedReader br;

	@Override
	public void run() {
		try {
			Locale.setDefault(Locale.US);
			out = new PrintWriter(new FileWriter(file + ".out"));
			br = new BufferedReader(new FileReader(file + ".in"));
			tok = new StringTokenizer("");
			while (hasNext()) {
				solve();
			}
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	boolean hasNext() throws IOException {
		while (!tok.hasMoreElements()) {
			String line = br.readLine();
			if (line == null) {
				return false;
			}
			tok = new StringTokenizer(line);
		}
		return true;
	}

	String next() throws IOException {
		if (hasNext()) {
			return tok.nextToken();
		}
		throw new IOException("No more tokens");
	}

	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	long nextLong() throws IOException {
		return Long.parseLong(next());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	String nextLine() throws IOException {
		if (hasNext()) {
			return tok.nextToken("\n");
		}
		throw new IOException("No more tokens");
	}
}
