package round1c;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Scanner;

public class UglyNumbers {

	/**
	 * @param args
	 */

	static BigInteger[][] big;

	static int len;

	static BigInteger count(int x) {
		BigInteger[][] mod = new BigInteger[len + 1][x];
		mod[0][0] = new BigInteger("1");
		BigInteger modul = new BigInteger(Integer.toString(x));
		for (int i = 1; i < x; i++)
			mod[0][i] = new BigInteger("0");
		for (int i = 1; i <= len; i++) {
			for (int j = 0; j < x; j++)
				mod[i][j] = new BigInteger("0");
			for (int j = 0; j < i; j++) {
				int ost = big[j][i].mod(modul).intValue();
				for (int o1 = 0; o1 < x; o1++) {
					int o2 = (o1 + ost) % x;
					mod[i][o2] = mod[i][o2].add(mod[j][o1]);
					if (j > 0) {
						o2 = (o1 - ost + x) % x;
						mod[i][o2] = mod[i][o2].add(mod[j][o1]);
					}
				}
			}
		}
		return mod[len][0];
	}

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new BufferedReader(new FileReader(new File(
				"B-large.in"))));
		BufferedWriter wr = new BufferedWriter(
				new FileWriter(new File("b.out")));
		int n = sc.nextInt();
		sc.nextLine();
		for (int test = 1; test <= n; test++) {
			String s = sc.nextLine();
			len = s.length();
			big = new BigInteger[s.length() + 1][s.length() + 1];
			for (int i = 0; i < s.length(); i++)
				for (int j = i + 1; j <= s.length(); j++)
					big[i][j] = new BigInteger(s.substring(i, j));
			BigInteger[] x = new BigInteger[211];
			x[2] = count(2);
			x[3] = count(3);
			x[5] = count(5);
			x[7] = count(7);
			x[6] = count(6);
			x[10] = count(10);
			x[14] = count(14);
			x[15] = count(15);
			x[21] = count(21);
			x[35] = count(35);
			x[30] = count(30);
			x[42] = count(42);
			x[70] = count(70);
			x[105] = count(105);
			x[210] = count(210);
			BigInteger res = new BigInteger("0");
			res = res.add(x[2]).add(x[3]).add(x[5]).add(x[7]);
			res = res.subtract(x[6]).subtract(x[10]).subtract(x[14]);
			res = res.subtract(x[15]).subtract(x[21]).subtract(x[35]);
			res = res.add(x[30]).add(x[42]).add(x[70]).add(x[105]);
			res = res.subtract(x[210]);
			wr.write("Case #" + test + ": " + res.toString() + "\n");
			System.out.println(res);
		}
		wr.close();
		sc.close();
	}

}
