import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String a = sc.next();
		System.out.println(a.charAt(a.length() - 1) == 'T' ? "YES" : "NO");
	}
}