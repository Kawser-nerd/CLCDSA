import java.util.Scanner;

public class Main {

	@SuppressWarnings("resource")
	public static void main(String args[]) {
		Scanner scanner = new Scanner(System.in);
		int n=scanner.nextInt();
		int x=scanner.nextInt();
		int a[]=new int [n];
		
		for(int i=0;i<n;i++) {
			a[i]=scanner.nextInt();
		}
		
		int ans=0;
		int ind=0;
		for(int i=x;i>0;i/=2) {
			if(i%2==1)ans+=a[ind];
			ind++;
		}
		System.out.println(ans);
	}
}