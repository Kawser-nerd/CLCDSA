import java.util.Scanner;

public class Main {

	@SuppressWarnings("resource")
	public static void main(String args[]) {
		Scanner scanner = new Scanner(System.in);
		int n=scanner.nextInt();
		int b[]=new int[n];
		for(int i=1;i<n;i++) {
			b[i]=scanner.nextInt();
		}
		int sc[]=new int[n];
		for(int i=n-1;i>=0;i--) {
			int max=Integer.MIN_VALUE;
			int min=Integer.MAX_VALUE;
			int cnt=0;
			for(int j=n-1;j>=i;j--) {
				if(i==b[j]-1) {
					max=Math.max(max, sc[j]);
					min=Math.min(min, sc[j]);
					cnt++;
				}
			}
			if(cnt==1) {
				sc[i]=2*max+1;
			}else if(cnt==0) {
				sc[i]=1;
			}else {
				sc[i]=max+min+1;
			}
		}
		System.out.println(sc[0]);
	}
}