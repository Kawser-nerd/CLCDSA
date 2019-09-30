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

		in.readLine();
		final String name = in.readLine();
		final String kit = in.readLine();

		int[] name_count = new int['Z' - 'A' + 1];
		int[] kit_count = new int[name_count.length];

		for (int i = 0; i < name.length(); ++i) {
			++name_count[name.charAt(i) - 'A'];
		}
		for (int i = 0; i < kit.length(); ++i) {
			++kit_count[kit.charAt(i) - 'A'];
		}

		int ans = 0;
		for (int i = 0; i < kit_count.length; ++i) {
			if (kit_count[i] == 0) {
				if (0 < name_count[i]) {
					ans = -1;
					break;
				}
			} else {
				ans = Math.max(ans, name_count[i] / kit_count[i] + (0 < name_count[i] % kit_count[i] ? 1 : 0));
			}
		}

		System.out.println(ans);
	}
}