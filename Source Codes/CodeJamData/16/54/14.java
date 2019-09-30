import java.io.*;
import java.util.*;

public class D {

	String solveOne(Scanner in) {
		int size = in.nextInt();
		int len = in.nextInt();
		String g[] = new String[size];
		for (int i = 0; i < size; i++) {
			g[i] = in.next();
		}
		String bad = in.next();
		if (bad.contains("0")) {
			throw new Error();
		}
		for (String s : g) {
			if (!s.contains("0")) {
				return "IMPOSSIBLE";
			}
		}
		String ans = "0";
		for (int i = 1; i < len; i++) {
			ans += "1";
		}
		ans += " ";
		for (int i = 0; i < len; i++) {
			ans += "0?";
		}
		return ans;
	}

	void solve(Scanner in, PrintWriter out) {
		int nTests = in.nextInt();
		for (int iTest = 1; iTest <= nTests; iTest++) {
			out.printf("Case #%d: %s%n", iTest, solveOne(in));
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
		new D().run();
	}
}
