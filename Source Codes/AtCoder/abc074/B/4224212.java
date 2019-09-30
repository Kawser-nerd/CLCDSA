import java.util.Scanner;
public class Main {
public static void main(String[]srgs) {
	Scanner scan=new Scanner(System.in);
	int a=scan.nextInt();
	int b=scan.nextInt();
	int ans=0;
	for(int i=0;i!=a;i++) {
		int c=scan.nextInt();
		if(Math.abs(c)<Math.abs(c-b)) {
			ans+=c*2;
		}
		else {
			ans+=Math.abs(c-b)*2;
		}
	}
	System.out.println(ans);
	scan.close();
}
}