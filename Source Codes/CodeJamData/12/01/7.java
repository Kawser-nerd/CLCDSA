import java.util.Scanner;

public class Googlereese {
	private static final String s1 = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up aoz";
	private static final String s2 = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv yeq";
	private static char missingChar;
	private static char missingTranslate;

	public static void main(String[] args) {
		int c1 = 0, c2 = 0;
		for (char a = 'a'; a <= 'z'; a++) {
			if (s2.indexOf(a) == -1) {
				missingChar = a;
				c2++;
			}
			if (s1.indexOf(a) == -1) {
				missingTranslate = a;
				c1++;
			}
		}
		assert c1 == c2 && c1 <= 1;
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		scan.nextLine();
		for (int i = 1; i <= n; i++) {
			System.out.print("Case #" + i + ": ");
			String line = scan.nextLine();
			char[] chars = line.toCharArray();
			char[] out = new char[chars.length];
			for (int j = 0; j < chars.length; j++) {
				out[j] = map(chars[j]);
			}
			System.out.println(out);
		}
	}

	private static char map(char c) {
		if (c == missingChar)
			return missingTranslate;
		else
			return s1.charAt(s2.indexOf(c));
	}
}
