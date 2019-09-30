import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		char[] arr = sc.next().toCharArray();
		int[] counts = new int[6];
		for (char c : arr) {
			counts[c - 'A']++;
		}
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < counts.length; i++) {
			if (i != 0) {
				sb.append(" ");
			}
			sb.append(counts[i]);
		}
		System.out.println(sb);
	}
}