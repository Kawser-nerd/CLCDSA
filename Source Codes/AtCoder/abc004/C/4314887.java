import java.util.*;
public class Main {
	static int num[] = {1, 2, 3, 4, 5, 6};
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int count = sc.nextInt() % 30;
		for(int i = 0; i < count; i ++) {
			replace(i);
		}
		for(int i = 0; i < 6; i ++) {
			System.out.print(num[i]);
		}
		System.out.println();
	}

	public static void replace(int a) {
		a %= 5;
		int tmp = num[a];
		num[a] = num[a + 1];
		num[a + 1] = tmp;
	}
}