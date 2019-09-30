import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
Scanner scan=new Scanner(System.in);
int a=scan.nextInt();
int b=scan.nextInt();
if(a%16==0&&b%9==0) {
	System.out.println("16:9");
}
else {
	System.out.println("4:3");
}
	}
}