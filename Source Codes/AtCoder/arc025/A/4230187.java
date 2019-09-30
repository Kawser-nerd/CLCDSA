import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] arrD = new int[7];
		int[] arrJ = new int[7];
		for (int i = 0; i < 7; i++) {
			arrD[i] = sc.nextInt();
		}
		for (int i = 0; i < 7; i++) {
			arrJ[i] = sc.nextInt();
		}
		int sum = 0;
		for (int i = 0; i < 7; i++) {
			sum += Math.max(arrD[i], arrJ[i]);
		}
		System.out.println(sum);
	}
}