import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		Set<Integer> set = new HashSet<>();
		for (int i = 0; i < 3; i++) {
			set.add(sc.nextInt());
		}
		System.out.println(set.size());
	}
}