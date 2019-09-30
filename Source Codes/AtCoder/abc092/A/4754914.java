import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int a = Integer.parseInt(sc.next());
		int b = Integer.parseInt(sc.next());
		int c = Integer.parseInt(sc.next());
		int d = Integer.parseInt(sc.next());
		int sum =0;
		if(a>b){
			sum+=b;
		}else {
			sum+=a;
		}
		if(c>d){
			sum+=d;
		}else {
			sum+=c;
		}
		System.out.println(sum);
	}
}