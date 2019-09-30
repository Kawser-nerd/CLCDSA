import java.util.Scanner;
public class Main {
public static void main(String[]srgs) {
	Scanner scan=new Scanner(System.in);
	int a=scan.nextInt();
	int b=scan.nextInt();
	int ans=1;
	for(int i=0;i!=a;i++) {
		if(ans<b) {
			ans*=2;
		}
		else {
			ans+=b;
		}
	}
	System.out.println(ans);
	scan.close();
}
}