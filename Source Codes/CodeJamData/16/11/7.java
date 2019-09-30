import java.io.*;
import java.util.*;

public class A {

	String solveOne(String s) {
		String res = "";
		for (char c : s.toCharArray()) {
			String r1 = res + c;
			String r2 = c + res;
			if (r1.compareTo(r2) > 0) {
				res = r1;
			} else {
				res = r2;
			}
		}
		return res;
	}

	void solve(Scanner in, PrintWriter out) {
		int nTests = in.nextInt();
		for (int iTest = 1; iTest <= nTests; iTest++) {
			out.printf("Case #%d: %s%n", iTest, solveOne(in.next()));
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
		new A().run();
	}
}
