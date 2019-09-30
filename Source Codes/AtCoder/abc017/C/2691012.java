import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int N = scan.nextInt();
		int M = scan.nextInt();
		int []l = new int[N];
		int []r = new int[N];
		int []s = new int[N];
		for(int i = 0; i < N; i++) {
			l[i] = scan.nextInt();
			r[i] = scan.nextInt();
			s[i] = scan.nextInt();
		}
		scan.close();
		int ary[] = new int[M + 2];
		Arrays.fill(ary, 0);
		int sum = 0;
		for(int i = 0; i < N; i++) {
			ary[l[i]] += s[i];
			ary[r[i] + 1] -= s[i];
			sum += s[i];
		}
		for(int i = 0; i < M + 1; i++) {
			ary[i + 1] += ary[i];
		}
		int min = ary[1];
		for(int i = 2; i <= M; i++) {
			int temp = ary[i];
			if(min > temp) {
				min = temp;
			}
		}
		System.out.println(sum - min);

	}
}