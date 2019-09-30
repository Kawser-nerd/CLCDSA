package b1;

import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new FileReader("A-large.in"));
		PrintWriter out = new PrintWriter(new FileWriter(
				new File("a-large.out")));
		int n = sc.nextInt();

		for (int T = 1; n-- > 0; T++) {
			long N = sc.nextLong();
			long total = 0;
			if (N > 10) {
				total += 10;
			}
			if (N >= 100) {
				total += 10 - 1 + 10;
				if (N == 100L) {
					out.println("Case #" + T + ": " + total);
					System.out.println("Case #" + T + ": " + total);
					continue;
				}
			}
			if (N >= 1000L) {
				total += 100 - 1 + 10;
				if (N == 1000) {
					out.println("Case #" + T + ": " + total);
					System.out.println("Case #" + T + ": " + total);
					continue;
				}
			}
			if (N >= 10000L) {
				total += 100 - 1 + 100;
				if (N == 10000) {
					out.println("Case #" + T + ": " + total);
					System.out.println("Case #" + T + ": " + total);
					continue;
				}
			}
			if (N >= 100000L) {
				total += 1000 - 1 + 100;
				if (N == 100000) {
					out.println("Case #" + T + ": " + total);
					System.out.println("Case #" + T + ": " + total);
					continue;
				}
			}
			if (N >= 1000000L) {
				total += 1000 - 1 + 1000;
				if (N == 1000000) {
					out.println("Case #" + T + ": " + total);
					System.out.println("Case #" + T + ": " + total);
					continue;
				}
			}
			if (N >= 10000000L) {
				total += 10000 - 1 + 1000;
				if (N == 10000000) {
					out.println("Case #" + T + ": " + total);
					System.out.println("Case #" + T + ": " + total);
					continue;
				}
			}
			if (N >= 100000000L) {
				total += 10000 - 1 + 10000;
				if (N == 100000000) {
					out.println("Case #" + T + ": " + total);
					System.out.println("Case #" + T + ": " + total);
					continue;
				}
			}
			if (N >= 1000000000L) {
				total += 100000 - 1 + 10000;
				if (N == 1000000000) {
					out.println("Case #" + T + ": " + total);
					System.out.println("Case #" + T + ": " + total);
					continue;
				}
			}
			if (N >= 10000000000L) {
				total += 100000 - 1 + 100000;
				if (N == 10000000000L) {
					out.println("Case #" + T + ": " + total);
					System.out.println("Case #" + T + ": " + total);
					continue;
				}
			}
			if (N >= 100000000000L) {
				total += 1000000 - 1 + 100000;
				if (N == 100000000000L) {
					out.println("Case #" + T + ": " + total);
					System.out.println("Case #" + T + ": " + total);
					continue;
				}
			}
			if (N >= 1000000000000L) {
				total += 1000000 - 1 + 1000000;
				if (N == 1000000000000L) {
					out.println("Case #" + T + ": " + total);
					System.out.println("Case #" + T + ": " + total);
					continue;
				}
			}
			if (N >= 10000000000000L) {
				total += 10000000 - 1 + 1000000;
				if (N == 10000000000000L) {
					out.println("Case #" + T + ": " + total);
					System.out.println("Case #" + T + ": " + total);
					continue;
				}
			}

			String s = Long.toString(N);
			if (N <= 10) {
				total = N;
			} else if (s.endsWith("0")) {
				s = Long.toString(N-1);
				int mid = s.length() / 2;
				String firstMid = s.substring(0, mid);
				firstMid = new StringBuilder(firstMid).reverse().toString();
				int firstIntReverse = Integer.parseInt(firstMid);

				String secondMid = s.substring(mid, s.length());
				int secondInt = Integer.parseInt(secondMid);
				if (N - Math.pow(10, s.length() - 1) <= firstIntReverse
						+ secondInt) {
					total += N - Math.pow(10, s.length() - 1);
				} else {
					total += firstIntReverse + secondInt + 1;
				}
			} else {
				int mid = s.length() / 2;
				String firstMid = s.substring(0, mid);
				firstMid = new StringBuilder(firstMid).reverse().toString();
				int firstIntReverse = Integer.parseInt(firstMid);

				String secondMid = s.substring(mid, s.length());
				int secondInt = Integer.parseInt(secondMid);
				if (N - Math.pow(10, s.length() - 1) < firstIntReverse
						+ secondInt) {
					total += N - Math.pow(10, s.length() - 1);
				} else {
					total += firstIntReverse + secondInt;
				}
			}

			out.println("Case #" + T + ": " + total);
			System.out.println("Case #" + T + ": " + total);
		}
		out.flush();
	}
}