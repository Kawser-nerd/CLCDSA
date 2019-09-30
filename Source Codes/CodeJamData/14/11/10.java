import java.util.*;
import java.io.*;

public class Rd1aa {

    public static void main (String[] args) {

		Scanner in = new Scanner(System.in);

		int count = in.nextInt();
		for (int l = 0; l < count; l++) {

			int n = in.nextInt();
			int len = in.nextInt();
			in.nextLine();

			String[] first = new String[n];
			String[] second = new String[n];
			String line_1 = in.nextLine();
			String line_2 = in.nextLine();
			for (int i = 0; i < n; i++) {
				first[i] = line_1.substring(i*(len+1), i*(len+1) + len);
				second[i] = line_2.substring(i*(len+1), i*(len+1) + len);
			}

			int best = len+1;
			for (int i = 0; i < n; i++) {
				String shift = find_shift(first[0], second[i], len);
				int score = find_match(first, second, shift, len);
				if (score < best && score != -1)
					best = score;
			}

			if (best > len)
				System.out.println("Case #" + (l+1) + ": NOT POSSIBLE");
			else
				System.out.println("Case #" + (l+1) + ": " + best);
		}	
	}

	public static int find_match(String[] first, String[] second, String shift, int length) {
		Boolean[] used = new Boolean[second.length];
		for (int i = 0; i < second.length; i++)
			used[i] = false;
		for (int i = 0; i < first.length; i++) {
			boolean outer_match = false;
			for (int j = 0; j < second.length; j++) {
				if (!used[j]) {
					boolean match = true;
					for (int k = 0; k < length; k++) {
						if (shift.charAt(k) == '0') {
							if (first[i].charAt(k) != second[j].charAt(k)) {
								match = false;
								k = k;
							}
						} else {
							if (first[i].charAt(k) == second[j].charAt(k)) {
								match = false;
								k = k;
							}
						}
					}
					if (match) {
						used[j] = true;
						outer_match = true;
						j = second.length;
					}
				}
			}
			if (!outer_match)
				return -1;
		}
		int score = 0;
		for (int i = 0; i < length; i++) {
			if (shift.charAt(i) == '1')
				score++;
		}
		return score;
	}

	public static String find_shift (String str_1, String str_2, int length) {
		String str_final = "";
		for (int i = 0; i < length; i++) {
			if (str_1.charAt(i) == str_2.charAt(i))
				str_final += "0";
			else
				str_final += "1";
		}
		return str_final;
	}

}
