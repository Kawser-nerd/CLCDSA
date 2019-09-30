import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	static boolean debug = false;
	static boolean debug2 = false;

	public static void main(String[] args) throws java.io.IOException {
		debug = 1 <= args.length;
		debug2 = 2 <= args.length;

		Scanner sc = new Scanner(System.in);

		final int N = sc.nextInt();

		int ans = 0;
		for (int i = 0; i < N; ++i) {
			String is = sc.next();
			if (is.endsWith(".")) {
				is = is.replaceFirst("\\.$", "");
			}
			switch (is) {
				case "TAKAHASHIKUN":
				case "Takahashikun":
				case "takahashikun":
					++ans;
					break;
				default:
					break;
			}
		}

		System.out.println(ans);
	}
}