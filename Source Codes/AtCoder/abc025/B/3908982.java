import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		int a=scan.nextInt();
		int A=scan.nextInt();
		int B=scan.nextInt();
		int ans=0;
		for(int i=0;i!=a;i++) {
			String str=scan.next();
			int b=scan.nextInt();
			if(str.charAt(0)=='E') {
				if(b<A) {
					ans+=A;
				}
				else if(b>=A&&b<=B) {
					ans+=b;
				}
				else {
					ans+=B;
				}
			}
			if(str.charAt(0)=='W') {
				if(b<A) {
					ans-=A;
				}
				else if(b>=A&&b<=B) {
					ans-=b;
				}
				else {
					ans-=B;
				}
			}
		}
		if(ans<0) {
			System.out.println("West "+(ans*-1));
		}
		else if(ans>0) {
			System.out.println("East "+ans);
		}
		else if(ans==0){
			System.out.println(0);
		}
	}
}