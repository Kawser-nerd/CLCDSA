import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[] arr = new int[n + 1];
		int[] arrS = new int[m + 1];
		int[] arrT = new int[m + 1];
		for (int i = 1; i <= m; i++) {
			arrS[i] = sc.nextInt();
			arrT[i] = sc.nextInt();
			arr[arrS[i]]++;
			if (arrT[i] != n) {
				arr[arrT[i] + 1]--;
			}
		}
		int[] arrX = new int[n + 1];
		for (int i = 1; i <= n; i++) {
			arr[i] += arr[i - 1];
			arrX[i] += arrX[i - 1];
			if (arr[i] < 2) {
				arrX[i]++;
			}
		}
		int count = 0;
		ArrayList<Integer> list = new ArrayList<>();
		for (int i = 1; i <= m; i++) {
			if (arrX[arrT[i]] - arrX[arrS[i] - 1] == 0) {
				count++;
				list.add(i);
			}
		}
		StringBuilder sb = new StringBuilder();
		sb.append(count).append("\n");
		for (int x : list) {
			sb.append(x).append("\n");
		}
		System.out.print(sb);
	}
}