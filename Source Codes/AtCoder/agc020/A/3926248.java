import java.util.Scanner;

public class Main{
    public static void main(String[] args){
	Scanner scan = new Scanner(System.in);

	int N = scan.nextInt();
	int A = scan.nextInt();
	int B = scan.nextInt();

	if(Math.abs(B-A)%2 == 0){
	    System.out.println("Alice");
	}else{
	    System.out.println("Borys");
	}
    }
}