import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		String x = sc.next();
		int ss = 0;
		int ts = 0;
		for (int i = 0; i < x.length(); i++) {
			if (x.charAt(i) == 'S') {
				ss++;
			} else {
				if (ss == 0) {
					ts++;
				} else {
					ss--;
				}
			}
		}
		System.out.println(ss + ts);
	}
}