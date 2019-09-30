import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int a=scan.nextInt();
		String b=scan.next();
		int ans=0;
		if(a%2==0) {ans=-1;}
		else {
		if(b.charAt(b.length()/2)!='b') {
			ans=-1;
		}
		else {
			for(int i=0;i!=b.length()/2;i++) {
				if(b.charAt(b.length()/2+i)=='c'
						&&b.charAt(b.length()/2-i)=='a') {}

				else if(b.charAt(b.length()/2+i)=='a'
						&&b.charAt(b.length()/2-i)=='c') {}

				else if(b.charAt(b.length()/2+i)=='b'
						&&b.charAt(b.length()/2-i)=='b') {}
				else {ans=-1;break;}
				ans++;
			}
		}
		}
		System.out.println(ans);
		
	}
}