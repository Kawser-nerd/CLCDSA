import java.util.Scanner;
import java.util.TreeSet;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		int d = sc.nextInt();
		int e = sc.nextInt();
		sc.close();

		TreeSet<Integer> set = new TreeSet<Integer>();
		set.add(a + b + c);
		set.add(a + b + d);
		set.add(a + b + e);
		set.add(a + c + d);
		set.add(a + c + e);
		set.add(a + d + e);
		set.add(b + c + d);
		set.add(b + c + e);
		set.add(b + d + e);
		set.add(c + d + e);

		set.pollLast();
		set.pollLast();
		System.out.println(set.pollLast());
	}
}