import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int ABCD = scn.nextInt();
		int A = ABCD/1000;
		int B = (ABCD%1000)/100;
		int C = (ABCD%100)/10;
		int D = ABCD%10;
		
		
		if(A+B+C+D==7) {
			System.out.println(A+"+" + B + "+" + C + "+" + D + "=" + 7);
			return;
		}
		if(A+B+C-D==7) {
			System.out.println(A+"+" + B + "+" + C + "-" + D + "=" + 7);
			return;
		}
		if(A+B-C+D==7) {
			System.out.println(A+"+" + B + "-" + C + "+" + D + "=" + 7);
			return;
		}
		if(A+B-C-D==7) {
			System.out.println(A+"+" + B + "-" + C + "-" + D + "=" + 7);
			return;
		}
		if(A-B+C+D==7) {
			System.out.println(A+"-" + B + "+" + C + "+" + D + "=" + 7);
			return;
		}
		if(A-B+C-D==7) {
			System.out.println(A+"-" + B + "+" + C + "-" + D + "=" + 7);
			return;
		}
		if(A-B-C+D==7) {
			System.out.println(A+"-" + B + "-" + C + "+" + D + "=" + 7);
			return;
		}
		if(A-B-C-D==7) {
			System.out.println(A+"-" + B + "-" + C + "-" + D + "=" + 7);
			return;
		}
	}

}