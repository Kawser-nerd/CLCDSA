import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long x = sc.nextLong();
		long a = sc.nextLong();
		long b = sc.nextLong();
		System.out.println(b <= a ? "delicious" : b <= x + a ? "safe" : "dangerous");
	}
}