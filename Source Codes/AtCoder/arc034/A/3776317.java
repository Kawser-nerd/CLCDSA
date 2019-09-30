import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int N=sc.nextInt();
		double max=0;
		for(int i=0; i<N; i++) {
			double tmp=0;
			for(int j=0; j<4; j++) {
				tmp+=sc.nextInt();
			}
			tmp+=(sc.nextDouble()*11/90);
			max=Math.max(tmp,max);
		}
		System.out.println(max);
	}
}