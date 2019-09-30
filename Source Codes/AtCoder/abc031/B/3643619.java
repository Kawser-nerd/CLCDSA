import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int L=sc.nextInt();
		int H=sc.nextInt();
		int N=sc.nextInt();
		for(int i=0; i<N; i++) {
			int time=sc.nextInt();
			if(time<=L) {
				System.out.println(L-time);
			}
			else if(L<time && time<=H) {
				System.out.println(0);
			}
			else {
				System.out.println(-1);
			}
		}
	}
}