import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long num = sc.nextLong();
		long ans = 0;
		long prv = -1;
		long tmp = -1;
		for(int i = 0; i < num; i ++) {
			prv = tmp;
			tmp = sc.nextLong();
			if(prv == tmp) {
				tmp = -1;
				ans ++;
			}
		}
		System.out.println(ans);
	}
}