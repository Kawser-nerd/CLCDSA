import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		int a=scan.nextInt(),b=scan.nextInt(),c=scan.nextInt(),d=scan.nextInt();
		if(a==c||a==d||b==c||b==d) {
			System.out.println("YES");
		}
		else {
			System.out.println("NO");
		}
	}
}