import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		final Scanner sc = new Scanner(System.in);
		String s = sc.next();
		String s1 = sc.next();
		System.out.println(s.toLowerCase().equals(s1.toLowerCase()) ? "Yes" : "No");
	}
}