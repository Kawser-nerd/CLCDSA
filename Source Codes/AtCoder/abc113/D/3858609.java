import java.util.*;

public class Main {
	
	public static final long MOD = 1000000007L;

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int h = sc.nextInt();
		int w = sc.nextInt();
		int k = sc.nextInt();
		
		if (w == 1) {
			System.out.println(1);
			return;
		}
		
		ArrayList<boolean[]> list = new ArrayList<boolean[]>();
		list.add(new boolean[w-1]);
		boolean[] b = new boolean[w-1];
		for (int i = 0; i < w - 1; i++) {
			ArrayList<boolean[]> tlist = new ArrayList<boolean[]>();
			for (boolean[] arr : list) {
				if (i == 0 || !arr[i - 1]) {
					boolean[] tmp = arr.clone();
					tmp[i] = true;
					tlist.add(tmp);
				}
			}
			list.addAll(tlist);
		}
		
		long[][] count = new long[w][h+1];
		count[0][0] = 1;
		for (int i = 1; i < h + 1; i++) {
			for (int j = 0; j < w; j++) {
				int stay = 0;
				int left = 0;
				int right = 0;
				for (boolean[] arr : list) {
					if (j != 0 && arr[j - 1]) {
						left++;
					}
					if (j != w - 1 && arr[j]) {
						right++;
					}
					if (j != 0 && j != w - 1) {
						if (!arr[j - 1] && !arr[j]) {
							stay++;
						}
					} else if (j == 0) {
						if (!arr[j]) {
							stay++;
						}
					} else if (j == w - 1) {
						if (!arr[j - 1]) {
							stay++;
						}
					}
					
				}
				count[j][i] += count[j][i - 1] * stay;
				if (j != 0) {
					count[j][i] += count[j - 1][i - 1] * left;
				}
				if (j != w - 1) {
					count[j][i] += count[j + 1][i - 1] * right;
				}
				count[j][i] %= MOD;
			}
		}
		
		System.out.println(count[k - 1][h] % MOD);
	}
}