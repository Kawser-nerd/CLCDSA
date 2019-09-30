import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int N=sc.nextInt();
		int M=sc.nextInt();
		boolean[] balls=new boolean[N];
		balls[0]=true;
		int[] ballvol=new int[N];
		for(int i=0; i<N; i++) {
			ballvol[i]=1;
		}
		for(int i=0; i<M; i++) {
			int s=sc.nextInt();
			int g=sc.nextInt();
			if(balls[s-1]) {
				if(ballvol[s-1]>1) {
					balls[g-1]=true;
					ballvol[s-1]--;
					ballvol[g-1]++;
					/*for(int j=0; j<N; j++) {
						System.out.print(ballvol[j]+" ");
					}*/
				}
				else if(ballvol[s-1]==1) {
					balls[s-1]=false;
					balls[g-1]=true;
					ballvol[s-1]--;
					ballvol[g-1]++;
					/*for(int j=0; j<N; j++) {
						System.out.print(ballvol[j]+" ");
					}*/
				}
			}
			else {
				ballvol[s-1]--;
				ballvol[g-1]++;
				/*for(int j=0; j<N; j++) {
					System.out.print(ballvol[j]+" ");
				}*/
			}
		}
		int count=0;
		for(int i=0; i<N; i++) {
			if(balls[i]) {
				count++;
			}
		}
		System.out.println(count);
	}
}