import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long a = (sc.nextLong() + 11) % 13;
		long b = (sc.nextLong() + 11) % 13;
		System.out.println(a > b ? "Alice" : a < b ? "Bob" : "Draw");
	}
}