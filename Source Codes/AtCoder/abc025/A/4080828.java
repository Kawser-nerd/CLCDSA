import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		char[] arr = sc.next().toCharArray();
		int n = sc.nextInt();
		System.out.println("" + arr[(n - 1) / 5 % 5] + arr[(n - 1) % 5]);
	}
}