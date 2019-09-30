import java.util.*;

public class Main {

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] arrC = new int[n];
		int[] arrS = new int[n];
		int[] arrF = new int[n];
		for (int i = 0; i < n - 1; i++) {
			arrC[i] = sc.nextInt();
			arrS[i] = sc.nextInt();
			arrF[i] = sc.nextInt();
		}
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < n - 1; i++) {
			int total = 0;
			for (int j = i; j < n - 1; j++) {
				if (total < arrS[j]) {
					total = arrS[j];
				}
				if (total % arrF[j] != 0) {
					total += arrF[j] - total % arrF[j];
				}
				total += arrC[j];
			}
			sb.append(total).append("\n");
		}
		sb.append(0).append("\n");
		System.out.print(sb);
	}
}