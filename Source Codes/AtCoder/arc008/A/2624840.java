import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	static boolean debug  = false;
	static boolean debug2 = false;

	public static void main(String[] args) throws java.io.IOException {
		debug  = 1 <= args.length;
		debug2 = 2 <= args.length;

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

		final int N = Integer.parseInt(in.readLine());

		System.out.println(100 * (N / 10) + Math.min(100, 15 * (N % 10)));
	}
}