import java.util.Scanner;

public class Main {
	static int N;
	static long ans;
	public static void main(String[] args) {
    	Scanner sc = new Scanner(System.in);
    	N=sc.nextInt();
    	luca(2,1,0);
    	System.out.println(ans);

	}
	public static void luca(long a,long b,int n) {
		if(n>=N) {
			ans=a;
			return;
		}
		luca(b,a+b,n+1);
	}
}