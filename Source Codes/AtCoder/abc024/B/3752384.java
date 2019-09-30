import java.util.Scanner;
class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int N=sc.nextInt();
		int T=sc.nextInt();
		int sum=0;
		int s=sc.nextInt();
		int g=s+T;
		for(int i=1; i<N; i++) {
			int tmp=sc.nextInt();
			if(tmp>g) {		//???????
				sum+=g-s;
				s=tmp;
				g=tmp+T;
			}
			else if(tmp<=g){		//??????
				g=tmp+T;
			}
		}
		sum+=g-s;
		System.out.println(sum);
	}
}