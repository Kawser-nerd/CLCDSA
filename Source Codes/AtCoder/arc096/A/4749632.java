import java.util.Scanner;

public class Main {
	//half and half


	public static void main(String[] args){
		int A,B,C,X,Y;
		Scanner sc = new Scanner(System.in);
		A= sc.nextInt();
		B= sc.nextInt();
		C= sc.nextInt();
		X= sc.nextInt();
		Y= sc.nextInt();
		int v0=C*2*X+Math.max(0, B*(Y-X));
		int v1=C*2*Y+Math.max(0, A*(X-Y));
		int v2=X*A+Y*B;
		int v=Math.min(v0, v1);
		v=Math.min(v, v2);
		System.out.println(v);
	}
}