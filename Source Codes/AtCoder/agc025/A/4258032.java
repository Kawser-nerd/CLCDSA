import java.util.Scanner;
public class Main {
public static void main(String[]srgs) {
	Scanner scan=new Scanner(System.in);
	int a=scan.nextInt();
	if(a%10==0) {
		System.out.println(10);
	}
	else {
		int ans=0;
		for(int i=0;i!=10;i++) {
			ans+=a%10;
			a/=10;
		}
		System.out.println(ans);
	}
	}
}