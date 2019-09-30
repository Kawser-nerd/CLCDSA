import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class C {

	// public static final String FILE_NAME = "C-large";

	public static final String FILE_NAME = "C-small-attempt0";

	// public static final String FILE_NAME = "test";

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws Exception {
		BufferedReader input = new BufferedReader(new FileReader(FILE_NAME + ".in"));
		BufferedWriter output = new BufferedWriter(new FileWriter(FILE_NAME + ".out"));
		final int T = Integer.parseInt(input.readLine());
		for (int t = 0; t < T; t++) {
			output.append("Case #" + (t + 1) + ":\n");
			String[] wqStr = input.readLine().trim().split(" +");
			final int W = Integer.parseInt(wqStr[0]);
			final int Q = Integer.parseInt(wqStr[1]);
			char[][] sq = new char[W][W];
			for (int p = 0; p < W; p++) {
				System.arraycopy(input.readLine().trim().toCharArray(), 0, sq[p], 0, W);
			}
			String query[] = input.readLine().trim().split(" +");
			Set<Integer> left = new HashSet<Integer>();
			Map<Integer, String> results = new HashMap<Integer, String>();
			for (int i = 0; i < Q; i++) {
				left.add(Integer.parseInt(query[i]));
			}
			boolean firstIter = true;
			Map<Integer, String>[][] ovals = null;
			Map<Integer, String>[][] vals = null;
			while (!left.isEmpty()) {
				ovals = vals;
				vals = new HashMap[W][W];
				for (int p = 0; p < W; p++) {
					for (int q = 0; q < W; q++) {
						if (sq[p][q] != '+' && sq[p][q] != '-') {
							vals[p][q] = new HashMap<Integer, String>();
							if (firstIter) {
								// First iteration
								vals[p][q].put(sq[p][q] - '0', String.valueOf(sq[p][q]));
							} else {
								getForSign(sq, ovals, sq[p][q] - '0', p - 1, q, vals[p][q]);
								getForSign(sq, ovals, sq[p][q] - '0', p + 1, q, vals[p][q]);
								getForSign(sq, ovals, sq[p][q] - '0', p, q - 1, vals[p][q]);
								getForSign(sq, ovals, sq[p][q] - '0', p, q + 1, vals[p][q]);
							}

							for (Integer num : left) {
								if (vals[p][q].containsKey(num)) {
									if (!results.containsKey(num)
											|| results.get(num).compareTo(vals[p][q].get(num)) > 0) {
										results.put(num, vals[p][q].get(num));
									}
								}
							}
						}
					}
				}
				for (Integer num : results.keySet()) {
					left.remove(num);
				}
				firstIter = false;
			}
			for (int i = 0; i < Q; i++) {
				output.append(results.get(Integer.parseInt(query[i])));
				output.append('\n');
			}
		}
		output.close();
	}

	private static void getForSign(char[][] sq, Map<Integer, String>[][] ovals, int digit, int p, int q,
			Map<Integer, String> result) {
		if (p < 0 || q < 0 || p >= sq.length || q >= sq.length)
			return;
		char sign = sq[p][q];
		getForDigit(sq, ovals, digit, sign, p - 1, q, result);
		getForDigit(sq, ovals, digit, sign, p + 1, q, result);
		getForDigit(sq, ovals, digit, sign, p, q - 1, result);
		getForDigit(sq, ovals, digit, sign, p, q + 1, result);
	}

	private static void getForDigit(char[][] sq, Map<Integer, String>[][] ovals, int digit, char sign, int p, int q,
			Map<Integer, String> result) {
		if (p < 0 || q < 0 || p >= sq.length || q >= sq.length)
			return;
		for (Map.Entry<Integer, String> entry : ovals[p][q].entrySet()) {
			int key = entry.getKey() + (sign == '+' ? 1 : -1) * digit;
			String value = entry.getValue() + sign + digit;
			if (!result.containsKey(key) || result.get(key).compareTo(value) > 0) {
				result.put(key, value);
			}
		}
	}
}
