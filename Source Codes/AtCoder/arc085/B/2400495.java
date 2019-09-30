import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] cards = new int[n+2];
		for (int i=0;i<n+2;i++) {
			cards[i]=sc.nextInt();
		}

		int [][] mainTable= new int[n+2][n+2];
		int [][] subTable = new int[n+2][n+2];

		for (int j=0;j<n+1;j++) {
			mainTable[j][n+1] = Math.abs(cards[j]-cards[n+1]);
			mainTable[n+1][j] = Math.abs(cards[j]-cards[n+1]);
			subTable[j][n+1] = Math.abs(cards[j]-cards[n+1]);
			subTable[n+1][j] = Math.abs(cards[j]-cards[n+1]);
		}

		for (int i=n;i>=1;i--) {
			for (int j=0;j<i;j++) {
				mainTable[i][j] = subTable[i][i+1];
				subTable[i][j] = Math.max(mainTable[i][j], subTable[i+1][j]);

				mainTable[j][i] = subTable[i+1][i];
				subTable[j][i] = Math.min(mainTable[j][i], subTable[j][i+1]);
			}
		}

		System.out.println(mainTable[0][1]);

	}

}