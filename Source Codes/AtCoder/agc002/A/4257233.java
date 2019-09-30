import java.util.Scanner;
public class Main {
public static void main(String[]srgs) {
	Scanner scan=new Scanner(System.in);
	int a=scan.nextInt();
	int b=scan.nextInt();
	if(a<=0&&b>=0) {
		System.out.println("Zero");
	}
	else if(a<0&&Math.abs((a-b+1))%2==1){
		System.out.println("Negative");
	}
	else {
		System.out.println("Positive");
	}
	scan.close();
	}
}