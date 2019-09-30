import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int N=sc.nextInt();
		int[][] sw=new int[N][2];
		long cnt=0;
		for(int i=0; i<N; i++) {
			sw[i][0]=sc.nextInt();
			sw[i][1]=sc.nextInt();
		}
		for(int i=N-1; i>=0; i--) {
			if((cnt+sw[i][0])%sw[i][1]==0) {
				//
			}
			else {
				cnt+=sw[i][1]-(cnt+sw[i][0])%sw[i][1];
			}
		}
		System.out.println(cnt);
		sc.close();
	}
}