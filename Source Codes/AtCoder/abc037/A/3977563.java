import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		int a=scan.nextInt(),b=scan.nextInt(),c=scan.nextInt();
		if(a>=b) {
			System.out.println(c/b);
		}else{
			System.out.println(c/a);
		}
	}
}