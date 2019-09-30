import java.util.Scanner;
public class Main{
	public static void main(String[]args){
		Scanner sc = new Scanner(System.in);
		int x=sc.nextInt();
		int ans=(int)Math.pow(x, 1.0/4);
		System.out.println(ans);
		}
}