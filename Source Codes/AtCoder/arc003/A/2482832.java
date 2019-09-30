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

		final int N = Integer.parseInt(in.readLine());

		int sum = 0;
		char[] grades = in.readLine().toCharArray();
		for (int i = 0; i < N; ++i) {
			if (grades[i] != 'F') {
				sum += 'E' - grades[i];
			}
		}

		System.out.println(1.0 * sum / N);
	}
}