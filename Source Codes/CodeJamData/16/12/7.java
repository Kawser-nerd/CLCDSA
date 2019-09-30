import java.io.*;
import java.util.*;

public class B {

	String solveOne(Scanner in) {
		boolean odd[] = new boolean[2501];
		int n = in.nextInt();
		for (int i = 0; i < 2 * n - 1; i++) {
			for (int j = 0; j < n; j++) {
				int value = in.nextInt();
				odd[value] = !odd[value];
			}
		}
		String res = "";
		for (int i = 0; i < odd.length; i++) {
			if (odd[i]) {
				res += " " + i;
			}
		}
		return res;
	}

	void solve(Scanner in, PrintWriter out) {
		int nTests = in.nextInt();
		for (int iTest = 1; iTest <= nTests; iTest++) {
			out.printf("Case #%d:%s%n", iTest, solveOne(in));
		}
	}
	
	void run() {
		try (
			Scanner in = new Scanner(System.in);
			PrintWriter out = new PrintWriter(System.out);
	   	) {
	   		solve(in, out);
	   	}
	}


	public static void main(String args[]) {
		new B().run();
	}
}
