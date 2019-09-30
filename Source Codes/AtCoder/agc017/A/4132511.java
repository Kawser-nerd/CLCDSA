import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int p = sc.nextInt();
		long[] arrEV = new long[n + 1];
		long[] arrOD = new long[n + 1];
		arrEV[0] = 1;
		arrOD[0] = 0;
		for (int i = 1; i <= n; i++) {
			int a = sc.nextInt();
			arrEV[i] = arrEV[i - 1];
			arrOD[i] = arrOD[i - 1];
			if (a % 2 == 0) {
				arrEV[i] += arrEV[i - 1];
				arrOD[i] += arrOD[i - 1];
			} else {
				arrEV[i] += arrOD[i - 1];
				arrOD[i] += arrEV[i - 1];
			}
		}
		if (p == 0) {
			System.out.println(arrEV[n]);
		} else {
			System.out.println(arrOD[n]);
		}
	}
			
}