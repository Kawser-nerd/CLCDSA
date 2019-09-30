import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int N=sc.nextInt();
		int[]x=new int[N];
		int max=0;int sum=0;
		for(int i=0;i<N;i++) {
			int p=sc.nextInt();
			x[i]=p;
			sum+=x[i];
		}
		max=x[0];
		for(int j=1;j<N;j++) {
			if(x[j]>max) {
				max=x[j];
			}
		}
		System.out.print(sum-max+max/2);

		sc.close();
	}

}