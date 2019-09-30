package qualification;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {

	public static void main(String[] args) throws IOException {
		String file = "A-large";
		Scanner sc = new Scanner(new FileReader(file + ".in"));
		PrintWriter out = new PrintWriter(new FileWriter(file + ".out"));

		int cases = sc.nextInt(); sc.nextLine();
		for(int cas = 1; cas <= cases; cas++) {
			int n = sc.nextInt(), k = sc.nextInt() % (1<<n);
			out.printf("Case #%d: %s%n", cas, k == (1<<n)-1 ? "ON" : "OFF");
		}
		
		out.close();
	}
}
