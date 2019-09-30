import java.math.BigInteger;
import java.util.Scanner;

public class B {
	private static int parse(String s) {
		BigInteger integer = new BigInteger(s);
		integer = integer.mod(BigInteger.valueOf(210));
		return integer.intValue();
	}

	public static void main(String[] args) {
		final Scanner scanner = new Scanner(System.in);
		final int N = scanner.nextInt();

		for (int testCase = 1; testCase <= N; ++testCase) {
			final String line = scanner.next();
			final int n = line.length();
			// i文字目からj文字目まで(exclusive)
			final int[][] partsTable = new int[n][n + 1];
			for (int begin = 0; begin < n; ++begin) {
				for (int end = begin + 1; end <= n; ++end) {
					partsTable[begin][end] = parse(line.substring(begin, end));
				}
			}

			// mod210テーブル作成
			// [何文字目][数字mod]
			final long[][] memo = new long[n + 1][210];
			++memo[0][0];

			for (int endIndex = 1; endIndex <= n; ++endIndex) {
				for (int beginIndex = 0; beginIndex < endIndex; ++beginIndex) {
					// 足し算
					{
						for (int prevMod = 0; prevMod < 210; ++prevMod) {
							final int nextMod = (prevMod + partsTable[beginIndex][endIndex]) % 210;
							memo[endIndex][nextMod] += memo[beginIndex][prevMod];
						}
					}

					// 引き算
					if (beginIndex != 0) {
						for (int prevMod = 0; prevMod < 210; ++prevMod) {
							final int nextMod = (prevMod - partsTable[beginIndex][endIndex] + 210) % 210;
							memo[endIndex][nextMod] += memo[beginIndex][prevMod];
						}
					}
				}
			}

			long answer = 0;
			for (int mod = 0; mod < 210; ++mod) {
				if (mod % 2 == 0 || mod % 3 == 0 || mod % 5 == 0 || mod % 7 == 0) {
					answer += memo[n][mod];
				}
			}

			System.out.printf("Case #%d: %d\n", testCase, answer);
		}
	}
}
