import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int R = sc.nextInt();
		int C = sc.nextInt();
		int K = sc.nextInt();
		int N = sc.nextInt();
		int[] r = new int[N];
		int[] c = new int[N];
		//????????????????????????
		int[] rowSum = new int[R];
		int[] colSum = new int[C];
		for(int i = 0 ; i < N ; i++) {
			r[i] = sc.nextInt() - 1;
			c[i] = sc.nextInt() - 1;
			rowSum[r[i]]++;
			colSum[c[i]]++;
		}
//		System.out.println(Arrays.toString(rowSum));
//		System.out.println(Arrays.toString(colSum));
		// ??x??????????????????????
		int[] rowNum = new int[100010];
		int[] colNum = new int[100010];
		for(int i = 0 ; i < R ; i++) rowNum[rowSum[i]]++;
		for(int i = 0 ; i < C ; i++) colNum[colSum[i]]++;
//		System.out.println(Arrays.toString(rowNum));
//		System.out.println(Arrays.toString(colNum));
		long ans = 0;
		for(int i = 0 ; i <= K ; i++) ans += rowNum[i] * colNum[K - i];
//		System.out.println(ans);
		// ?????????????
		for(int i = 0 ; i < N ; i++) {
			if(rowSum[r[i]] + colSum[c[i]] == K) ans--;
			if(rowSum[r[i]] + colSum[c[i]] == K + 1) ans++;
		}
		System.out.println(ans);

	}
}