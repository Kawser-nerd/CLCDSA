import java.util.Scanner;

public class Main{
    public static void main(String[] args){
	Scanner scan = new Scanner(System.in);

	int A = scan.nextInt();
	int B = scan.nextInt();
	int C = scan.nextInt();
	int X = scan.nextInt();
	int Y = scan.nextInt();

	if((A+B)/2.0 > C && X >= Y && A >= C*2){
	    System.out.println(C*X*2);
	}else if((A+B)/2.0 > C && Y > X && B >= C*2){
	    System.out.println(C*Y*2);
	}else if((A+B)/2.0 > C && X >= Y){
	    System.out.println(C*2*Y+A*(X-Y));
	}else if((A+B)/2.0 > C && Y > X){
	    System.out.println(C*2*X+B*(Y-X));
	}else{
	    System.out.println(A*X+B*Y);
	}
    }
}