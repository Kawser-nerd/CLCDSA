import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long a = sc.nextLong();
		boolean plus = sc.next().equals("+");
		long b = sc.nextLong();
		System.out.println(plus ? a + b : a - b);
	}
}