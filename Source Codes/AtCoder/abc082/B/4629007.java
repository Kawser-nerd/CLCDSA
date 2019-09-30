import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {

	static void exec(Scanner in, PrintStream out) {
		String s = in.next();
		String t = in.next();
		List<Character> sl = new ArrayList<>(s.length());
		for (int i = 0; i < s.length(); i += 1) {
			sl.add(s.charAt(i));
		}
		List<Character> tl = new ArrayList<>(t.length());
		for (int i = 0; i < t.length(); i += 1) {
			tl.add(t.charAt(i));
		}
		sl.sort(null);
		tl.sort(Collections.reverseOrder());
		for (int i = 0, n = Math.min(sl.size(), tl.size()); i < n; i += 1) {
			if (sl.get(i).charValue() < tl.get(i).charValue()) {
				out.println("Yes");
				return;
			}
			if (sl.get(i).charValue() > tl.get(i).charValue()) {
				out.println("No");
				return;
			}
		}
		out.println(s.length() < t.length() ? "Yes" : "No");
	}

	public static void main(String[] args) {
		exec(new Scanner(System.in), System.out);
	}

}