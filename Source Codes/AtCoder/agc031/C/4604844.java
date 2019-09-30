import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		int first = sc.nextInt();
		int last = sc.nextInt();
		boolean bit[] = new boolean[num];
		int index[] = new int[num];
		int sum = 0;
		for(int i = 0; i < num; i ++) {
			bit[i] = (first & (1 << i)) != (last & (1 << i));
			sum += bit[i] ? 1 : 0;
			index[bit[i] ? sum - 1 : num - (i - sum) - 1] = i;
		}
		if(sum % 2 == 0) {
			System.out.println("NO");
		}else {
			System.out.println("YES");
			int max = (int)Math.pow(2, num);
			int tmp = first;
			int change[] = new int[num];
			System.out.print(tmp+" ");
			for(int i = 1; i < max; i ++) {
				int crtIndex = 0;
				for(; crtIndex < num; crtIndex ++) {
					if((i & (1 << crtIndex)) != 0) {
						break;
					}
				}
				crtIndex = num - crtIndex - 1;
				if(bit[index[crtIndex]] && crtIndex != 0) {
					if(crtIndex % 2 == 0) {
						if(change[crtIndex] < 2) {
							change[crtIndex] ++;
							crtIndex --;
						}
					}else {
						if(change[crtIndex] < 1) {
							change[crtIndex] ++;
							crtIndex ++;
						}
					}
				}
				int crtDigit = 1 << index[crtIndex];
				tmp = (tmp & crtDigit) != 0 ? tmp - crtDigit : tmp + crtDigit;
				System.out.print(tmp+" ");
			}
		}
		System.out.println();
	}
}