import java.io.InputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	InputStream in = System.in;
	PrintStream out = System.out;

	public void _main(String[] args) {
		Scanner sc = new Scanner(in);

		String S = sc.next();
		String T = sc.next();

		int[] ms = new int[26];
		int[] mt = new int[26];
		Arrays.fill(ms, -1);
		Arrays.fill(mt, -1);

		String ans = "Yes";
		for (int i = 0; i < S.length(); i++) {
			int ss = S.charAt(i) - 'a';
			int tt = T.charAt(i) - 'a';

			if ((ms[ss] == -1 || ms[ss] == tt) && (mt[tt] == -1 || mt[tt] == ss)) {
				ms[ss] = tt;
				mt[tt] = ss;
			} else {
				ans = "No";
				break;
			}
		}

		out.println(ans);

		sc.close();

	}

	public static void main(String[] args) {
		new Main()._main(args);
	}

}