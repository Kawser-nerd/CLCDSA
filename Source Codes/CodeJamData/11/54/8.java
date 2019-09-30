package round3;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class D {
	static long[] stepeni = new long[62];
	static {
		stepeni[0] = 1;
		for (int i = 1; i < stepeni.length; i++)
			stepeni[i] = 2 * stepeni[i - 1];
	}

	static boolean jePotpunKvadrat(long a) {
		long koren = Math.round(Math.sqrt(a));
		return koren * koren == a;
	}

	static long resi(String s, long value, int position) {
		if (jePotpunKvadrat(value))
			return value;
		if (position == s.length())
			return -1;
		if (s.charAt(position) == '?') {
			long res = resi(s, value, position + 1);
			if (res != -1)
				return res;
			return resi(s, value + stepeni[s.length() - position - 1],
					position + 1);
		} else
			return resi(s, value, position + 1);
	}

	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new File("D.in"));
		PrintWriter out = new PrintWriter(new File("D.out"));
		int tt = in.nextInt();
		for (int ttt = 1; ttt <= tt; ttt++) {
			String s = in.next();

			long min = 0;
			for (int i = 0; i < s.length(); i++)
				if (s.charAt(s.length() - i - 1) == '1')
					min += stepeni[i];

			long res = resi(s, min, 0);

			out.printf("Case #%d: %s", ttt, Long.toBinaryString(res));
			out.println();
		}
		out.flush();
		out.close();
		in.close();
	}
}
