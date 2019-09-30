import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] num = new int[n];
		for (int i = 0; i < num.length; i++) {
			num[i] = sc.nextInt();
		}
		int max = 0;
		for (int i = 0; i < num.length; i++) {
			max+=(num[i]-1);
		}
		System.out.println(max);

	}

}