import java.util.*;

public class Main {
	static int count = 0;
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		char[] arr = sc.next().toCharArray();
		int[] counts = new int[26];
		for (char c : arr) {
			counts[c - 'a']++;
		}
		int odd = 0;
		int ev = 0;
		for (int i = 0; i <26; i++) {
			int x = counts[i];
			odd += x % 2;
			ev += x / 2;
		}
		if (odd == 0) {
			System.out.println(ev * 2);
		} else {
			System.out.println((ev / odd) * 2 + 1);
		}
	}
}