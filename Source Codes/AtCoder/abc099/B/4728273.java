import java.util.*;
import java.util.stream.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int l1 = sc.nextInt();
		int l2 = sc.nextInt();
		int d = l2 - l1;
		int h = IntStream.rangeClosed(1, d).sum();
		System.out.println(h - l2);
	}
}