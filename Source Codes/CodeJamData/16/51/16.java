import java.io.*;
import java.util.*;

public class A {

	int solveOne(String s) {
		int score = 0;
		Stack<Character> stack = new Stack<>();
		for (char c : s.toCharArray()) {
			if (stack.empty()) {
				stack.push(c);
			} else if (stack.peek() == c) {
				score += 10;
				stack.pop();
			} else {
				stack.push(c);
			}
		}
		return score + 5 * (stack.size() / 2);
	}
	
	void solve(Scanner in, PrintWriter out) {
		int nTests = in.nextInt();
		for (int iTest = 1; iTest <= nTests; iTest++) {
			out.printf("Case #%d: %d%n", iTest, solveOne(in.next()));
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
