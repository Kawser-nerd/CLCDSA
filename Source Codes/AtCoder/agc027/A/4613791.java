import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		long have = sc.nextLong();
		long want[] = new long[num];
		for(int i = 0; i < num; i ++) {
			want[i] = sc.nextLong();
		}
		Arrays.sort(want);
		int ans = 0;
		long tmp = 0;
		for(int i = 0; i < num; i ++) {
			tmp += want[i];
			if(tmp <= have) {
				ans ++;
			}else {
				break;
			}
			if(i == num - 1 && tmp < have) {
				ans --;
				break;
			}
		}
		System.out.println(ans);
	}
}