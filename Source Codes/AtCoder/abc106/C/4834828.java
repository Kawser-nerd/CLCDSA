import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s=sc.next(),ans="1";
		long n=sc.nextLong();
		for(int i=0;i<n;i++) {
			if(!s.substring(i, i+1).equals("1")) {
				ans=s.substring(i,i+1);
				break;
			}
		}
		System.out.println(ans);
	}
}