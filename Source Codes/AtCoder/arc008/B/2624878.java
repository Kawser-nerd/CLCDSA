import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	static boolean debug = false;
	static boolean debug2 = false;

	public static void main(String[] args) throws java.io.IOException {
		debug = 1 <= args.length;
		debug2 = 2 <= args.length;

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

		String[] ia = in.readLine().split(" ");
		final int N = Integer.parseInt(ia[0]);
		final int M = Integer.parseInt(ia[1]);
		final String name = in.readLine();
		final String kit = in.readLine();

		LinkedList<Character> ll = new LinkedList<>();
		for (int i = 0; i < name.length(); ++i) {
			if (kit.indexOf(name.charAt(i)) < 0) {
				System.out.println(-1);
				return;
			} else {
				ll.addLast(name.charAt(i));
			}
		}

		for (int c = 1; ; ++c) {
			for (int i = 0; i < kit.length(); ++i) {
				ll.remove(Character.valueOf(kit.charAt(i)));
			}
			if (ll.isEmpty()) {
				System.out.println(c);
				return;
			}
		}
	}
}