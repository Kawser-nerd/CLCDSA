import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a=sc.nextInt();
		int b=sc.nextInt();
		int c=sc.nextInt();
		int x=sc.nextInt();
		int y=sc.nextInt();
		
		if(x>y){
			int tmp=a; a=b; b=tmp;
			tmp=x; x=y; y=tmp;
		}

		if(a+b<=2*c){
			System.out.println(a*x+b*y);
		}else{
			System.out.println(2*c*x + Math.min(b,2*c)*(y-x));
		}
	}
}