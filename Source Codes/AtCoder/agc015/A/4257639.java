import java.util.Scanner;
public class Main {
public static void main(String[]srgs) {
	Scanner scan=new Scanner(System.in);
	long a=scan.nextInt();
	long b=scan.nextInt();
	long c=scan.nextInt();
	long st=1;
		if(b>c) {
			st=0;
		}
		else if(a==1&&b==c) {
			st=1;
		}
		else if(a==1) {
			st=0;
		}
		else {
			st=(c-b)*(a-2)+1;
		}
	System.out.println(st);
	}
}