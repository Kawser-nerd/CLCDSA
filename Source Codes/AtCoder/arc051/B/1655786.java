import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		new Main().solve();
	}

	void solve() {
		Scanner sc = new Scanner(System.in);
		long k=sc.nextInt();
		long a=2;
		long b=1;
		if(k==1) {
			a=1;b=1;
		}else {
			for(int i=0;i<k-1;i++) {
				long temp=a;
				a=a+b;
				b=temp;
			}	
		}
		System.out.println(a+" "+b);
	}
}