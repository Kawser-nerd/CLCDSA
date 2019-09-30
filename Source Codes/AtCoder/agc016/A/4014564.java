import java.util.*;
import java.lang.*;


public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		int[] alp = new int[26];
		for (int i = 0; i < s.length(); i++) {
			alp[s.charAt(i) - 'a']++;
		}
		int count = 10000;
		for (int i = 0; i < 26; i++) {
			String ss = s;
			if (alp[i] != 0) {
				int cou = 0;
				while (contain(ss, (char) ('a' + i))) {
					ss = change(ss, (char) ('a' + i));
					cou++;
				}
				count = Math.min(cou, count);
			}
		}
		System.out.println(count);
	}
	static String change(String s, char a) {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < s.length() - 1; i++) {
			if (s.charAt(i) == a || s.charAt(i + 1) == a) {
				sb.append(a);
			} else {
				sb.append(s.charAt(i));
			}
		}
		return sb.toString();
	}
	static boolean contain(String s, char a) {
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) != a) {
				return true;
			}
		}
		return false;
	}
}