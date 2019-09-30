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

		String[] e = in.readLine().split(" ");
		char b = in.readLine().charAt(0);
		String l = in.readLine();

		int n = 0;
		for (int i = 0; i < e.length; ++i) {
			if (0 <= l.indexOf(e[i])) {
				++n;
			}
		}
		boolean f = 0 <= l.indexOf(b);

		switch (n) {
			case 6:
				System.out.println(1);
				break;
			case 5:
				System.out.println(f ? 2 : 3);
				break;
			case 4:
				System.out.println(4);
				break;
			case 3:
				System.out.println(5);
				break;
			default:
				System.out.println(0);
				break;
		}
	}
}