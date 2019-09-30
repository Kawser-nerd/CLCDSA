import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int N = scn.nextInt();
		int[] time = new int[N];
		for(int i = 0;i < N-1;i++) {
			int C = scn.nextInt();
			int S = scn.nextInt();
			int F = scn.nextInt();
			for(int j = 0;j <= i;j++) {
				if(time[j] < S) {
					time[j] = S;
				}
				if(time[j]%F!=0)time[j]+=F-time[j]%F;
				time[j]+= C;
			}
		}
		for(int i = 0;i < N;i++) {
			System.out.println(time[i]);
		}
	}

}