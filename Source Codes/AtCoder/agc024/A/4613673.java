import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println(((sc.nextLong() - sc.nextLong()) + sc.nextLong() * 0) * (sc.nextLong() % 2 == 1 ? -1 : 1));
	}
}