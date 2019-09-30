package round1c;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class TextMessage {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new BufferedReader(new FileReader(new File(
				"A-large.in"))));
		BufferedWriter wr = new BufferedWriter(
				new FileWriter(new File("a.out")));
		int n = sc.nextInt();
		for (int test = 1; test <= n ; test++) {
			int p = sc.nextInt(), k = sc.nextInt(), l = sc.nextInt();
			long[] f = new long[l];
			for (int i = 0; i < l ; i++)
				f[i] = sc.nextLong();
			Arrays.sort(f);
			long res = 0;
			int press = 1;
			for (int i = l-1; i >= 0; i--) {
				if (l-i>k*press) press++;
				res += press*f[i];
			}
			if (press > p)
				wr.write("Case #" + test + ": Impossible\n");
			else
				wr.write("Case #" + test + ": " + res+ "\n");
		}
		wr.close(); sc.close();
	}
	

}
