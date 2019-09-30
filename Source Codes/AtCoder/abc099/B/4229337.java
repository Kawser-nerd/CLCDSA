import java.util.Scanner;
public class Main {
public static void main(String[]srgs) {
	Scanner scan=new Scanner(System.in);
	int a=scan.nextInt();
	int b=scan.nextInt();
	int sa=b-a;
	int s=0;
	for(int i=0;i<=999;i++) {
		s+=i;
		if(i==sa) {
			System.out.println(s-b);
			return;
		}
	}
	scan.close();
}
}