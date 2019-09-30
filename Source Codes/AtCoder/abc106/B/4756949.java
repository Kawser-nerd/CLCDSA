import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n;
		n=sc.nextInt();
		int c=0;
		for(int i=1;i<=n;i++) {
			if(i%2==0)
				continue;
			if(div(i)==8)
				c++;
		}
		System.out.println(c);
	}
	
	public static int div(int n) {
		int cnt=0;
		for(int i=1;i<=n;i++) {
			if(n%i==0)
				cnt++;
		}
		return cnt;
	}
}