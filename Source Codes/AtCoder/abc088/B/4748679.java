import java.util.Arrays;
import java.util.Scanner;
public class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int data[] = new int[N];
		for(int i = 0; i < N; i++) {
			data[i] = sc.nextInt();
		}
		Arrays.sort(data);
		int sum = 0;
		int n = 2;
		for(int i = N-1; i >= 0; i--) {
			if(n % 2 == 0) {
				sum = sum+data[i];
			}else {
				sum = sum-data[i];
			}
			n++;
		}
		System.out.println(sum);
		sc.close();
	}
}