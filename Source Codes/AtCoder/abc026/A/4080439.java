import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int half = n / 2;
		System.out.println(half * (n - half));
	}
}