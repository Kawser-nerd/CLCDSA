import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		long sum[] = new long[num + 2];
		sum[0] = 0;
		for(int i = 1; i <= num; i ++) {
			sum[i] = sum[i - 1] + sc.nextLong();
		}
		sum[num + 1] = Long.MAX_VALUE;
		Arrays.sort(sum);
		long ans = 0;
		long tmp = 1;
		for(int i = 0; i <= num; i ++) {
			if(sum[i] == sum[i + 1]) {
				tmp ++;
			}else {
				ans += tmp * (tmp - 1) / 2;
				tmp = 1;
			}
		}
		System.out.println(ans);
	}
}