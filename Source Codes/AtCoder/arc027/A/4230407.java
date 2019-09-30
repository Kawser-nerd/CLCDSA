import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int h = sc.nextInt();
		int m = sc.nextInt();
		int ans = (17 - h) * 60 + (60 - m);
		System.out.println(ans);
	}
}