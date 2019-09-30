import java.util.Scanner;
public class Main {
public static void main(String[]srgs) {
	Scanner scan=new Scanner(System.in);
	int a=scan.nextInt();
	int c=0;
	for(int i=1;;i++) {
		c+=i;
		if(c>=a) {
			System.out.println(i);
			break;
		}
	}
	scan.close();
	}
}