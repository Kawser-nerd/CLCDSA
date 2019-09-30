import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int l = sc.nextInt();
		int r = sc.nextInt();
		int[] arrL = new int[41];
		int[] arrR = new int[41];
		for (int i = 0; i < l; i++) {
			arrL[sc.nextInt()]++;
		}
		for (int i = 0; i < r; i++) {
			arrR[sc.nextInt()]++;
		}
		int sum = 0;
		for (int i = 10; i <= 40; i++) {
			sum += Math.min(arrL[i], arrR[i]);
		}
		System.out.println(sum);
	}
}