import static java.math.BigInteger.valueOf;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class C {
	
	static BigInteger[] PRECALC;
	
	static BigInteger[] readPrecalc() throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("cprecalc.out"));
		List<BigInteger> list = new ArrayList<>();
		while (true) {
			String line = br.readLine();
			if (line == null || (line = line.trim()).isEmpty()) {
				break;
			}
			BigInteger big = new BigInteger(line);
			list.add(big.multiply(big));
		}
		br.close();
		return (BigInteger[]) list.toArray(new BigInteger[list.size()]);
	}
	
	static int total = 0;

	static void solveMultiTest() throws IOException {
//		for (int i = 1; i <= 51; i++) {
//			goAllPossibleNumbers(i, "");
//			System.err.println("length = "+i);
//			System.err.println("total: "+total);
//			out.flush();
//		}
		PRECALC = readPrecalc();
		int testCases = nextInt();
		for (int testCase = 1; testCase <= testCases; testCase++) {
			out.print("Case #" + testCase + ": ");
			solveOneTest();
		}
	}

	static void solveOneTest() throws IOException {
		BigInteger left = new BigInteger(nextToken());
		BigInteger right = new BigInteger(nextToken());
		int answer = solve(right) - solve(left.subtract(BigInteger.ONE));
		out.println(answer);
	}

	private static int solve(BigInteger right) {
		int pos = Arrays.binarySearch(PRECALC, right);
		if (pos >= 0) {
			pos++;
		} else {
			pos = ~pos;
		}
		return pos;
	}

	static void goAllPossibleNumbers(int fixedLength, String fixedSuffix) {
		if (fixedSuffix.length() * 2 >= fixedLength) {
			String fixedString;
			if (fixedLength == fixedSuffix.length() * 2) {
				fixedString = reverse(fixedSuffix) + fixedSuffix;
			} else {
				fixedString = reverse(fixedSuffix) + fixedSuffix.substring(1);
			}
			if (isGood(fixedString)) {
				++total;
				out.println(fixedString);
			}
			return;
		}
		String fixedPrefix = reverse(fixedSuffix);
		BigInteger tenPow = valueOf(10).pow(fixedSuffix.length() + 1);
		for (int digit = 0; digit < 3; digit++) {
			if (fixedSuffix.isEmpty() && digit == 0) {
				continue;
			}
			if (digit == 2 && fixedLength > 15 && !fixedSuffix.isEmpty() && fixedSuffix.length() * 2 + 1 != fixedLength) {
				continue;
			}
			BigInteger ending = new BigInteger(digit + fixedSuffix);
			ending = ending.multiply(ending).mod(tenPow);
			BigInteger beginning = new BigInteger(fixedPrefix + digit);
			BigInteger beginningHigh = beginning.add(BigInteger.ONE);
			beginning = beginning.multiply(beginning);
			beginningHigh = beginningHigh.multiply(beginningHigh);
			if (isPossible(beginning.toString(), beginningHigh.toString(),
					reverse(ending.toString()))) {
				goAllPossibleNumbers(fixedLength, digit + fixedSuffix);
			}
		}
	}

	private static boolean isPossible(String lowPrefix, String highPrefix,
			String wantPrefix) {
		for (int length = lowPrefix.length(); length <= highPrefix.length(); length++) {
			String low = lowPrefix;
			while (low.length() < length) {
				low = "0"  + low;
			}
			String high = highPrefix;
			low = low.substring(0, wantPrefix.length());
			boolean good = low.compareTo(wantPrefix)<= 0 && (high.length() > length || wantPrefix.compareTo(high) <= 0);
			if (good) {
				return true;
			}
		}
		return false;
	}

	private static boolean isGood(String s) {
		return isPalindrome(s)
				&& isPalindrome(new BigInteger(s).multiply(new BigInteger(s))
						.toString());
	}

	private static boolean isPalindrome(String s) {
		return s.equals(reverse(s));
	}

	private static String reverse(String string) {
		return new StringBuilder(string).reverse().toString();
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		InputStream input = System.in;
		PrintStream output = System.out;
		File file = new File("c.in");
		if (file.exists() && file.canRead()) {
			input = new FileInputStream(file);
			output = new PrintStream(new File("c.out"));
		}
		br = new BufferedReader(new InputStreamReader(input));
		out = new PrintWriter(output);
		solveMultiTest();
		out.close();
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				return null;
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}
}
