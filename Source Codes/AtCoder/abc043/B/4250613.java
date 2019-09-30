import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		String s = sc.next();
		Deque<String> deq = new ArrayDeque<>();
		for (int i = 0; i < s.length(); i++) {
			char c = s.charAt(i);
			if (c == '0') {
				deq.addLast("0");
			} else if (c == '1') {
				deq.addLast("1");
			} else {
				deq.pollLast();
			}
		}
		StringBuilder sb = new StringBuilder();
		while (deq.size() != 0) {
			sb.append(deq.pollFirst());
		}
		System.out.println(sb);
	}
}