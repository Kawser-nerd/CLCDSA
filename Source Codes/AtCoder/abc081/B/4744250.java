import java.util.Scanner;
public class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int min = 100;
		for (int i = 0;i < N; i++) {
			int sum = 0;
			int a = sc.nextInt();
			while(a % 2 == 0) {
				a = a/2;
				sum = sum + 1;
			}
			if(min > sum) {
				min = sum;
			}
		}
		System.out.println(min);
		sc.close();
	}
}