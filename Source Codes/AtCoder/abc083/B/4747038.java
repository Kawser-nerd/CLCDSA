import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int A = sc.nextInt();
		int B = sc.nextInt();
		int x = 0;
		for (int i = 1;i < N+1; i++) {
			int sum = 0;
			int n;
			int a = i;
			while(a != 0) {
				n = a % 10;
				sum += n;
				a = (a-n)/10;
			}
			if(sum >= A && sum <= B) {
				x = x + i;
			}
		}
		System.out.println(x);
	}
}