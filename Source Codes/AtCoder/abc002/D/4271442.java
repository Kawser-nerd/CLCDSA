import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		int numC = sc.nextInt();
		boolean connect[][] = new boolean[num + 1][num + 1];
		for(int i = 0; i < numC; i ++) {
			connect[sc.nextInt()][sc.nextInt()] = true;
		}
		int max = 1;
		for(int i = 1; i <= Math.pow(2, num); i ++) {
			boolean group[] = new boolean[num + 1];
			int count = 0;
			for(int j = 1; j <= num; j ++) {
				group[j] = (i & (1 << (j - 1))) != 0;
				count += group[j] ? 1 : 0;
			}
			boolean canBe = true;
			for(int j = 1; j <= num; j ++) {
				for(int k = 1; k <= num; k ++) {
					if(j == k) {
					}else if(!group[j] || !group[k]) {
					}else if(connect[j][k] || connect[k][j]) {
					}else {
						canBe = false;
						break;
					}
				}
			}
			if(canBe) {
				max = Math.max(max, count);
			}
		}
		System.out.println(max);
	}
}