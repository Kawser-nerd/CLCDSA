import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String ans;
		if (n <= 59) {
			ans = "Bad";
		} else if (n <= 89) {
			ans = "Good";
		} else if (n <= 99) {
			ans = "Great";
		} else {
			ans = "Perfect";
		}
		System.out.println(ans);
	}
}