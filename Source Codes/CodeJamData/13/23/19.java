import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class ProblemC {

	public static void main(String[] args) {

		try {

			final String fileIn = ProblemC.class.getSimpleName().toLowerCase() + ".in";
			final String fileOut = ProblemC.class.getSimpleName().toLowerCase() + ".out";

			final Scanner in = new Scanner(new File(fileIn));
			final PrintWriter out = new PrintWriter(new File(fileOut));

			new ProblemC().solve(in, out);

			out.flush();
			out.close();

		} catch (Exception ex) {

			ex.printStackTrace();
		}
	}

	private static final class Node {

		boolean isEnd = false;
		final Map<Character, Node> nextNodes = new HashMap<Character, ProblemC.Node>();
	}

	private final Node root = new Node();

	private int maxLen = 0;

	private final void preprocess() throws Exception {

		final Scanner in = new Scanner(new File("dict.txt"));

		String word;

		while (in.hasNext() && (word = in.next()) != null) {

			Node currentNode = root;

			maxLen = Math.max(maxLen, word.length());

			for (int i = 0; i < word.length(); ++i) {

				final Character ch = word.charAt(i);

				if (!currentNode.nextNodes.containsKey(ch)) {

					currentNode.nextNodes.put(ch, new Node());
				}

				currentNode = currentNode.nextNodes.get(ch);
			}

			currentNode.isEnd = true;
		}
	}

	private final void solve(final Scanner in, final PrintWriter out) throws Exception {

		preprocess();

		final long start = System.currentTimeMillis();

		final int testCount = in.nextInt();
		maxLen = 5;

		for (int testCase = 1; testCase <= testCount; ++testCase) {

			final char[] s = in.next().toCharArray();

			final int d[][] = new int[s.length + 1][maxLen + 1];

			for (int i = 0; i < d.length; ++i) {

				Arrays.fill(d[i], -1);
			}

			d[0][maxLen] = 0;

			for (int i = 0; i < s.length; ++i) {

				for (int q = 0; q <= maxLen; ++q) {

					if (d[i][q] == -1) {

						continue;
					}

					dfs(d[i][q], i, q, d, s, root);
				}
			}

			int result = Integer.MAX_VALUE;

			for (int i = 0; i < d[s.length].length; ++i) {

				if (d[s.length][i] == -1) {
					continue;
				}

				result = Math.min(d[s.length][i], result);
			}

			out.printf("Case #%d: %d%n", testCase, result);
		}

		System.out.println((System.currentTimeMillis() - start));
	}

	private final void dfs(final int cost, final int pos, int last, final int[][] d, final char[] s, final Node currentNode) {

		if (last > maxLen) {

			last = maxLen;
		}

		if (pos == s.length) {

			if (!currentNode.isEnd) {
				return;
			}

			if (d[pos][last] == -1 || d[pos][last] > cost) {

				d[pos][last] = cost;
			}

			return;
		}

		if (currentNode.isEnd) {

			if (d[pos][last] == -1 || d[pos][last] > cost) {

				d[pos][last] = cost;
			}
		}

		if (last >= 5) {

			final Character currentChar = Character.valueOf(s[pos]);

			for (final Map.Entry<Character, Node> entry : currentNode.nextNodes.entrySet()) {

				dfs(cost + (entry.getKey().equals(currentChar) ? 0 : 1), pos + 1, entry.getKey().equals(currentChar) ? last + 1 : 1, d, s,
						entry.getValue());
			}
		} else {

			if (currentNode.nextNodes.containsKey(s[pos])) {

				dfs(cost, pos + 1, last + 1, d, s, currentNode.nextNodes.get(s[pos]));
			}
		}
	}
}
