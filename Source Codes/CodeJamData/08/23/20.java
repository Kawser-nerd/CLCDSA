import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class R1B_C {
	public static void main(String[] args) {
		Scanner scin = new Scanner(System.in);
		int N = scin.nextInt();
		for (int z = 1; z <= N; ++z) {
			int K = scin.nextInt();
			int n = scin.nextInt();
			int[] inds = new int[n];
			int[] ans = new int[K];
			for (int i = 0; i < n; ++i) inds[i] = scin.nextInt();
			List<Integer> list = new ArrayList<Integer>();
			for (int i = 0; i < K; ++i) list.add(i);
			int curr = 0;
			for (int i = 0; i < K; ++i) {
				curr = (curr+i)%list.size();
				int ind = list.remove(curr);
				ans[ind] = i;
			}
			System.out.print("Case #" + z + ":");
			for (int ind : inds) {
				System.out.print(" " + (ans[ind-1]+1));
			}
			System.out.println();
		}
	}
}
