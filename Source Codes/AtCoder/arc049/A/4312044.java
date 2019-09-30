import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder(sc.next());
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		int d = sc.nextInt();
		sb.insert(d, '\"');
		sb.insert(c, '\"');
		sb.insert(b, '\"');
		sb.insert(a, '\"');
		System.out.println(sb);
	}
}