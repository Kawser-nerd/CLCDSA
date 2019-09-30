import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] a = new int[N];

		for(int i = 0; i < N; i++) {
			a[i] = sc.nextInt();
		}
		sc.close();
		int flag = -1;
		int k = a[0];
		int cnt = 0;
		for(int i = 1; i < N; i++) {
			if(a[i] == k) continue;
			if(flag == -1) {
				if(a[i] > k) {
					flag = 0;
				}else {
					flag = 1;
				}
			}else {
				if(flag == 0) {
					if(a[i] < k) {
						cnt++;
						flag = -1;
					}
				}else if(flag == 1){
					if(a[i] > k) {
						cnt++;
						flag = -1;
					}
				}
			}
			k = a[i];
		}
		System.out.println(cnt + 1);

	}
}