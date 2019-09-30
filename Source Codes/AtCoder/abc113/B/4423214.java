import java.util.Scanner;

public class Main{
	public static void main(String[]args){
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt();
		int t=sc.nextInt();
		int a=sc.nextInt();
		double min=999;
		int minidx=0;
		for(int i=0;i<n;i++) {
			double sa=Math.abs(a-(t-sc.nextInt()*0.006));
			if(min>sa) {
				min=sa;
				minidx=i;
			}
		}
		System.out.println(minidx+1);
	}
}