import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next().toUpperCase();
		if (s.matches(".*I.*C.*T.*")) {
			System.out.println("YES");
		} else {
			System.out.println("NO");
		}
	}
}