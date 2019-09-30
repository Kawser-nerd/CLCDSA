import java.util.*;
import java.lang.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String[] s = new String[n];
		for (int i = 0; i < n; i++) {
			StringBuffer sb = new StringBuffer(sc.next());
			s[i] = sb.reverse().toString();
		}
		Arrays.sort(s);
		for (int i = 0; i < n; i++) {
			StringBuffer sb = new StringBuffer(s[i]);
			System.out.println(sb.reverse());
		}
	}
}