import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int x = sc.nextInt();
		System.out.println(Math.abs(sc.nextInt() - x) < Math.abs(sc.nextInt() - x) ? "A" : "B");
	}
}