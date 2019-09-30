import java.util.Scanner;
public class Main{
	public static void main(String[]args){
		Scanner sc = new Scanner(System.in);
		int a=sc.nextInt();
		int b=sc.nextInt();
		int n=sc.nextInt();
		for(int i=n;true;i++) {
			if(i%a==0&&i%b==0) {
				System.out.println(i);
				break;
			}
		}
	}
}