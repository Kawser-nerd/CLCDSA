import java.util.*;

public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		int X = sc.nextInt();
		int Y = sc.nextInt();
		int a[] = new int[N];
		int b[] = new int[M];
		for(int i = 0; i < N; i++) {
			a[i] = sc.nextInt();
		}
		for(int i = 0; i < M; i++) {
			b[i] = sc.nextInt();
		}
		
		int a_cnt = 0;
		int b_cnt = 0;
		int time = 0;
		int pos = 0;
		int ans = 0;
		while(true) {
			if(pos == 0) {
				for(int i = a_cnt; i < N; i++) {
					if(time <= a[i]) {
						time = a[i] + X;
						a_cnt = i;
						pos = 1;
						break;
					}
				}
				if(pos == 0) break;
			} else {
				for(int i = b_cnt; i < M; i++) {
					if(time <= b[i]) {
						time = b[i] + Y;
						b_cnt = i;
						pos = 0;
						ans++;
						break;
					}
				}
				if(pos == 1) break;
			}
		}
		System.out.println(ans);
 	}
}