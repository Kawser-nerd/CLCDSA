import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int N = scn.nextInt();
		int[] C = new int[9];
		for(int i = 0;i < N;i++) {
			int r = scn.nextInt();
			if(r >3200) {
				C[8]++;
			}else {
				C[r/400]++;
			}

		}
		int min = 0, max = 0;

		for(int i = 0;i < 8;i++) {
			if(C[i]>0)min++;
		}

		max = min + C[8];
		if(min==0)min++;
		System.out.println(min + " " + max);
	}

}