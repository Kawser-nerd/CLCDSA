import java.util.ArrayList;
import java.util.Scanner;

public class A {

	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int T = sc.nextInt();
		for (int i = 1; i <= T; ++i) {
			System.out.println("Case #" + i + ": " + solve());
		}
	}

	static int solve() {
		char[] S = sc.next().toCharArray();
		int score = 0;
		ArrayList<Character> stack = new ArrayList<>();
		for (int i = 0; i < S.length; ++i) {
			if (!stack.isEmpty() && stack.get(stack.size() - 1) == S[i]) {
				score += 10;
				stack.remove(stack.size() - 1);
			} else {
				stack.add(S[i]);
			}
		}
		return score + stack.size() / 2 * 5;
	}

}
