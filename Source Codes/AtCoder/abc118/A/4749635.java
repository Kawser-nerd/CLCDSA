import java.util.Scanner;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		int x =0;
		if((1<=A&&A<=20)&&(1<=B&&B<=20)&&(A<=B)) {
	if(B%A == 0) {
		x=A+B;
	}
	else {
		x=B-A;
	}
	System.out.println(x);
		}
	}
}