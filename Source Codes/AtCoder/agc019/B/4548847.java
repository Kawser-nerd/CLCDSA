import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		char[] arr = sc.next().toCharArray();
		long[] chars = new long[26];
		for (char c : arr) {
			chars[c - 'a']++;
		}
		long length = arr.length;
		long total = length * (length - 1) / 2 + 1;
		for (long x : chars) {
			if (x > 1) {
				total -= x * (x - 1) / 2;
			}
		}
		System.out.println(total);
	}
}