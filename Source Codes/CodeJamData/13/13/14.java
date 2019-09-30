package luck;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Random;
import java.util.StringTokenizer;

public class luck {

	private static final HashMap<Integer, int[]> multi = new HashMap<Integer, int[]>();
	private static final int[][] marr = { { 18, 2, 3, 3 }, { 24, 2, 3, 4 }, { 30, 2, 3, 5 }, { 32, 2, 4, 4 },
			{ 40, 2, 4, 5 }, { 50, 2, 5, 5 }, { 27, 3, 3, 3 }, { 36, 3, 3, 4 }, { 45, 3, 3, 5 }, { 48, 3, 4, 4 },
			{ 60, 3, 4, 5 }, { 75, 3, 5, 5 }, { 64, 4, 4, 4 }, { 80, 4, 4, 5 }, { 100, 4, 5, 5 }, { 125, 5, 5, 5 } };
	static {
		for (int[] m : marr) {
			multi.put(m[0], Arrays.copyOfRange(m, 1, 4));
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("luck.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("luck.out")));

		Random rand = new Random();
		pw.println("Case #1:");
		br.readLine();
		StringTokenizer tk = new StringTokenizer(br.readLine());
		int r = in(tk), n = in(tk), m = in(tk), k = in(tk);
		for (int l = 0; l < r; ++l) {
			tk = new StringTokenizer(br.readLine());
			Map<Integer, Integer> must = new HashMap<>();
			for (int i = 0; i < k; i++) {
				int val = in(tk);
				update(val, must);
				if (sum(must) >= 3)
					break;
			}
			int rem = 0;
			for (Entry<Integer, Integer> ent : must.entrySet()) {
				for (int i = 0; i < ent.getValue(); i++) {
					pw.print(ent.getKey());
					rem++;
				}
			}
			for (int i = rem; i < 3; i++) {
				pw.print(rand.nextInt(m - 2) + 2);
			}
			pw.println();
		}

		br.close();
		pw.close();
	}

	private static final void multiProd(int prod, Map<Integer, Integer> must) {
		int[] val = multi.get(prod);
		if (val != null) {
			must.clear();
			for (int i : val) {
				must.put(i, get(must, i) + 1);
			}
		}
	}

	private static final void update(int prod, Map<Integer, Integer> must) {
		if (prod == 1)
			return;
		multiProd(prod, must);
		if (prod % 4 == 2)
			update(must, 2, 1);
		if (prod % 5 == 0)
			update(must, 5, 1);
		if (prod % 3 == 0)
			update(must, 3, 1);
		if (prod % 9 == 0)
			update(must, 3, 2);
		if (prod % 25 == 0)
			update(must, 5, 2);
	}

	public static final int sum(Map<Integer, Integer> must) {
		int ret = 0;
		for (int i : must.values()) {
			ret += i;
		}
		return ret;
	}

	public static final int get(Map<Integer, Integer> must, int num) {
		Integer ret = must.get(num);
		if (ret == null)
			return 0;
		return ret;
	}

	public static final void update(Map<Integer, Integer> must, int num, int min) {
		Integer cur = must.get(num);
		if (cur == null)
			must.put(num, min);
		else
			must.put(num, Math.max(cur, min));
	}

	private static final long lg(StringTokenizer tk) {
		return lg(tk.nextToken());
	}

	private static final long lg(String s) {
		return Long.parseLong(s);
	}

	private static final int in(StringTokenizer tk) {
		return in(tk.nextToken());
	}

	private static final int in(String s) {
		return Integer.parseInt(s);
	}
}
