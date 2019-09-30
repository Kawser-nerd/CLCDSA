package gcj2009.qualification;

import java.io.File;
import java.io.PrintWriter;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;
import java.util.regex.Pattern;

public class A_Alien_Language {

	private static boolean SMALL = false;
	private static String PROBLEM = "A";

	public static void main(String[] args) {
		try {
			Scanner scan = new Scanner(new File(String.format("%s-%s.in", PROBLEM, (SMALL ? "small" : "large"))));
			PrintWriter pw = new PrintWriter(new File(String.format("%s-%s.out", PROBLEM, (SMALL ? "small" : "large"))));

			int L = scan.nextInt(), D = scan.nextInt(), N = scan.nextInt();
			scan.nextLine();
			String[] dictionary = new String[D];
			for (int i = 0; i < D; ++i)
				dictionary[i] = scan.nextLine();
			System.out.println(String.format("%d test cases:", N));
			long start = System.currentTimeMillis(), t1, left;
			for (int CASE = 1; CASE <= N; ++CASE) {
				t1 = System.currentTimeMillis();
				System.out.print(String.format("%d.[%s] ", CASE, new SimpleDateFormat("HH:mm:ss.SSS").format(new Date(t1))));

				String pattern = scan.nextLine();
				pattern = pattern.replace('(', '[').replace(')', ']');
				Pattern p = Pattern.compile(pattern);
				int cnt = 0;
				for (int i = 0; i < D; ++i)
					if (p.matcher(dictionary[i]).matches())
						cnt++;

				String res = String.valueOf(cnt);
				pw.println(String.format("Case #%d: %s", CASE, res));
				left = (System.currentTimeMillis() - start) * (N - CASE) / CASE;
				System.out.println(String.format("%s (%dms, ~%dms left)", res, (System.currentTimeMillis() - t1), left));
			}
			pw.close();
			scan.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
