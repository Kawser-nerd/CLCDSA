import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		String t = sc.next();
		sc.close();

		String ans = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
		int n = s.length() - t.length() + 1;
		for (int i = 0; i < n; i++) {
			if (match(s, t, i)) {
				String str = s.substring(0, i) + t + s.substring(i + t.length(), s.length());
				str = str.replaceAll("\\?", "a");
				if (str.compareTo(ans) < 0) {
					ans = str;
				}
			}
		}
		if ("zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz".equals(ans)) {
			System.out.println("UNRESTORABLE");
		} else {
			System.out.println(ans);
		}
	}

	static boolean match(String s, String t, int idx) {
		for (int i = 0; i < t.length(); i++) {
			char ch = s.charAt(idx + i);
			if (ch != '?' && ch != t.charAt(i)) {
				return false;
			}
		}
		return true;
	}
}