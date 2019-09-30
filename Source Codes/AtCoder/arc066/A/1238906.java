import java.util.Scanner;

public class Main{
	private static final Scanner s=new Scanner(System.in);
	public static void main(String[] args){
		int n=s.nextInt(),a[]=new int[n];
		for(int i=0;i<n;i++)
			a[s.nextInt()]++;
		
		if(n%2==0) {
			for(int i=1;i<n;i+=2) {
				if(a[i]!=2) {
					System.out.println(0);
					return;
				}
			}
			int r=1;
			for(int i=n/2;i>0;i--) {
				r*=2;
				r%=1000000007;
			}
			System.out.println(r);
		}else {
			if(a[0]!=1) {
				System.out.println(0);
				return;
			}
			for(int i=2;i<n;i+=2) {
				if(a[i]!=2) {
					System.out.println(0);
					return;
				}
			}
			int r=1;
			for(int i=n/2;i>0;i--) {
				r*=2;
				r%=1000000007;
			}
			System.out.println(r);
		}
	}
}