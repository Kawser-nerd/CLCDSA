import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int x = n;
		int sum = 0;
		while(x > 2) {
			x=x-3;
			sum++;
		}
		System.out.println(sum);
		sc.close();
	}
}