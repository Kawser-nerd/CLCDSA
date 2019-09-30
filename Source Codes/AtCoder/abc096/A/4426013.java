import java.util.Scanner;
public class Main{
	public static void main(String[]args){
		Scanner sc = new Scanner(System.in);
		int a=sc.nextInt();
		if(a>sc.nextInt()) {
			a--;
		}
		System.out.println(a);
	}
}