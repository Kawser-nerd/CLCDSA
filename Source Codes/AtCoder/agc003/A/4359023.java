import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		char[] arr = sc.next().toCharArray();
		int[] counts = new int[26];
		for (char c : arr) {
			counts[c - 'A']++;
		}
		if (((counts['N' - 'A'] != 0 && counts['S' - 'A'] != 0) ||
			(counts['N' - 'A'] == 0 && counts['S' - 'A'] == 0)) &&
			((counts['E' - 'A'] != 0 && counts['W' - 'A'] != 0) ||
			(counts['E' - 'A'] == 0 && counts['W' - 'A'] == 0))) {
			System.out.print("Yes");
		} else {
			System.out.print("No");
		}
	}
}