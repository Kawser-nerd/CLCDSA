import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		int ret = Integer.valueOf(s.replaceAll("[a-zA-z]", ""));
		System.out.println(ret);
	}
}