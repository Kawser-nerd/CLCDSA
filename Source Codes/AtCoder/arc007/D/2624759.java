import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	static boolean debug = false;
	static boolean debug2 = false;

	public static void main(String[] args) throws java.io.IOException {
		debug = 1 <= args.length;
		debug2 = 2 <= args.length;

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

		StringBuilder left = new StringBuilder(in.readLine());
		StringBuilder first = new StringBuilder();
		if (left.charAt(0) == '0') {
			first.append('1');
		} else {
			first.append(left.charAt(0));
			left.deleteCharAt(0);
		}
		while (0 < left.length() && left.charAt(0) == '0') {
			first.append(left.charAt(0));
			left.deleteCharAt(0);
		}

		BigInteger diff = BigInteger.ONE;
		if (0 < left.length() && left.length() < first.length()) {
			if (!first.toString().startsWith(left.toString())) {
				while (left.length() < first.length()) {
					left.append('0');
				}
			}
		}
		if (first.length() <= left.length()) {
			StringBuilder second = new StringBuilder(left.substring(0, first.length()));
			left.delete(0, first.length());
			while (true) {
				BigInteger first_big = new BigInteger(first.toString());
				BigInteger second_big = new BigInteger(second.toString());
				BigInteger first_to_second = second_big.subtract(first_big);
				if (0 < first_to_second.compareTo(BigInteger.ZERO)) {
					BigInteger next_big = second_big.add(first_to_second);
					StringBuilder next = new StringBuilder(next_big.toString(10));
					while (next.length() < left.length()) {
						next_big = next_big.add(first_to_second);
						next.append(next_big.toString(10));
					}
					if (next.toString().startsWith(left.toString())) {
						diff = first_to_second;
						break;
					}
				}
				if (0 < left.length()) {
					second.append(left.charAt(0));
					left.deleteCharAt(0);
				} else {
					second.append('0');
				}
				while (0 < left.length() && left.charAt(0) == '0') {
					second.append(left.charAt(0));
					left.deleteCharAt(0);
				}
			}
		}

		System.out.println(first.toString() + " " + diff.toString(10));
	}

}