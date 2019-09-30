import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String[] s = sc.next().split("");
		String[] t = sc.next().split("");
		Arrays.sort(s, Comparator.naturalOrder());
		Arrays.sort(t, Comparator.reverseOrder());
		String[] ss = new String[100];
		String[] tt = new String[100];
		for (int i = 0; i < 100; i++) {
			ss[i] = "a";
			tt[i] = "a";
		}
		for (int i = 0; i < s.length; i++) {
			ss[i] = s[i];
		}
		for (int i = 0; i < t.length; i++) {
			tt[i] = t[i];
		}
		for (int i = 0; i < 100; i++) {
			if (ss[i].compareTo(tt[i]) < 0) {
				System.out.println("Yes");
				return;
			} else if (ss[i].compareTo(tt[i]) > 0) {
				System.out.println("No");
				return;
			}
		}
		System.out.println("No");

	}

}