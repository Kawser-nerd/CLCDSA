import java.util.Scanner;
public class Main {
public static void main(String[]srgs) {
	Scanner scan=new Scanner(System.in);
	int a=scan.nextInt();
	int b=scan.nextInt();
	int c=scan.nextInt();
	int d=scan.nextInt();
	int h=d-b;
	int w=c-a;
	System.out.println((c-h)+" "+(d+w)+" "+(a-h)+" "+(b+w));
	scan.close();
}
}