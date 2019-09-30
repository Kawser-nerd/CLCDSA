import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a[] = {0, 0, 2, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0};
		System.out.println(a[sc.nextInt()] == a[sc.nextInt()] ? "Yes" : "No");
	}
}