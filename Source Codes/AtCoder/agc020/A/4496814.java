import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner stdIn=new Scanner(System.in);
		int N=stdIn.nextInt();
		int A=stdIn.nextInt();
		int B=stdIn.nextInt();
		if(N==2)
			System.out.println("Borys");
		else
			if((A-B-1)%2==0)
				System.out.println("Borys");
			else
				System.out.println("Alice");
	}

}