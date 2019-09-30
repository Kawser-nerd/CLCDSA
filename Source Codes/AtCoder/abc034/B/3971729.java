import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
Scanner scan=new Scanner(System.in);
int a=scan.nextInt();
if(a%2==1) {
	System.out.println(a+1);
}
else {
	System.out.println(a-1);
}
	}
}