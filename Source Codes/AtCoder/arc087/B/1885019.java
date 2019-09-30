import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
	static ArrayList<Integer> xs, ys;
	static int x, y;
	static Boolean[][] mem1, mem2;
	static int offset = 8001;

	static boolean solve(int idx, int sum) {
		if (idx == xs.size())
			return sum == x;
		if (mem1[idx][sum + offset] != null)
			return mem1[idx][sum + offset];
		return mem1[idx][sum + offset] = solve(idx + 1, sum + xs.get(idx)) || solve(idx + 1, sum - xs.get(idx));
	}

	static boolean solve2(int idx, int sum) {
		if (idx == ys.size())
			return sum == y;
		if (mem2[idx][sum + offset] != null)
			return mem2[idx][sum + offset];
		return mem2[idx][sum + offset] = solve2(idx + 1, sum + ys.get(idx)) || solve2(idx + 1, sum - ys.get(idx));
	}

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		x = sc.nextInt();
		y = sc.nextInt();

		xs = new ArrayList<>();
		ys = new ArrayList<>();

		int start = 0;

		while (start < s.length() && s.charAt(start) == 'F') {
			x--;
			start++;
		}

		boolean inX = true;
		for (int i = start; i < s.length(); i++) {
			if (s.charAt(i) == 'T') {
				inX = !inX;
			}
			else {
				int cnt = 0;
				boolean in = false;
				while (i < s.length() && s.charAt(i) == 'F') {
					cnt++;
					i++;
					in = true;
				}
				if (in)
					i--;
				if (inX)
					xs.add(cnt);
				else
					ys.add(cnt);
			}
		}
		mem1 = new Boolean[xs.size() + 1][8002 * 2];
		mem2 = new Boolean[ys.size() + 1][8002 * 2];
		if (solve(0, 0) && solve2(0, 0))
			System.out.println("Yes");
		else
			System.out.println("No");

	}

	static class Scanner {
		StringTokenizer st;
		BufferedReader br;

		public Scanner(InputStream s) {
			br = new BufferedReader(new InputStreamReader(s));
		}

		public String next() throws IOException {
			while (st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}

		public int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		public String nextLine() throws IOException {
			return br.readLine();
		}
	}
}