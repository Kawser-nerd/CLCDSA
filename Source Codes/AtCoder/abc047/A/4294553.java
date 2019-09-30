import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a[] = {sc.nextInt(), sc.nextInt(), sc.nextInt()};
		Arrays.sort(a);
		System.out.println(a[2] == a[1] + a[0] ? "Yes" : "No");
	}
}