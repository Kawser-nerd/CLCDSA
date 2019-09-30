import java.util.*;
public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int X = sc.nextInt();
		int t = sc.nextInt();
		System.out.println(Math.max(X - t, 0));
	}
}