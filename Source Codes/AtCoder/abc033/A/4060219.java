import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		char[] arr = sc.next().toCharArray();
		for (int i = 1; i < 4; i++) {
			if (arr[0] != arr[i]) {
				System.out.println("DIFFERENT");
				return;
			}
		}
		System.out.println("SAME");
	}
}