import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] li = new int[3];
		li[0] = sc.nextInt();
		li[1] = sc.nextInt();
		li[2] = sc.nextInt();
		Arrays.sort(li);
		int i = (li[2] - li[1]) + (li[1] - li[0]);
		System.out.println(i);
	}
}