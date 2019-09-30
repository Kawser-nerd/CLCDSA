import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a[] = new int[3];
		for(int i = 0; i < 3; i ++) {
			a[i] = sc.nextInt();
		}
		int max = 0;
		int sum = 0;
		for(int i = 0; i < 3; i ++) {
			max = Math.max(max, a[i]);
			sum += a[i];
		}
		System.out.println(sum - max);
	}
}