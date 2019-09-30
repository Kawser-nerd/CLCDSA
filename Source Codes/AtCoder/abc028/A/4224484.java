import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long a = sc.nextLong();
		System.out.println(a < 60 ? "Bad" : a < 90 ? "Good" : a < 100 ? "Great" : "Perfect");
	}
}