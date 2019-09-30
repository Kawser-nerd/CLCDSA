import java.util.*;

public class Main {
	static int count = 0;
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		char[] arr = new char[n - 1];
		Arrays.fill(arr, '0');
		System.out.println("1" + new String(arr) + "7");
	}
}