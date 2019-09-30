import java.util.*;

public class Main {
	static StringBuilder out = new StringBuilder();
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		add(new StringBuilder(), n);
		System.out.print(out);
	}
	
	static void add(StringBuilder sb, int count) {
		if (count == 0) {
			out.append(sb).append("\n");
			return;
		}
		final char[] arr = new char[]{'a', 'b', 'c'};
		for (char c : arr) {
			add(new StringBuilder(sb).append(c), count - 1);
		}
	}
}