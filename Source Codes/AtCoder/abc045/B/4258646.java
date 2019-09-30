import java.util.ArrayDeque;
import java.util.Deque;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		Map<String, Deque<String>> deq = new HashMap<>();
		String[] participants = new String[] {"a", "b", "c"};
		for (int i = 0; i < 3; i++) {
			String s = sc.next();
			deq.put(participants[i], new ArrayDeque<>());
			for (int j = 0; j < s.length(); j++) {
				deq.get(participants[i]).addLast(s.charAt(j) + "");
			}
		}
		String prev = participants[0];
		while (true) {
			if (deq.get(prev).size() == 0) {
				System.out.println(prev.toUpperCase());
				return;
			}
			prev = deq.get(prev).pollFirst();
		}
	}
}