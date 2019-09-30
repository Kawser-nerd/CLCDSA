import java.util.*;

public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		int l[] = new int[N];
		int r[] = new int[N];
		int s[] = new int[N];
		int point[] = new int[M];
		int sum = 0;
		
		for(int i = 0; i < N; i++) {
			l[i] = sc.nextInt() - 1;
			r[i] = sc.nextInt() - 1;
			s[i] = sc.nextInt();
			sum += s[i];
			point[l[i]] += s[i];
			if(r[i] != M - 1) {
				point[r[i] + 1] -= s[i];
			}
		}
		
		int min = Integer.MAX_VALUE;
		int temp = 0;
		for(int i = 0; i < M; i++) {
			temp += point[i];
			min = Math.min(min, temp);
		}
		System.out.println(sum - min);
	}
}