import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.close();
			//105 135 165 195
			if(n>=195)System.out.println(5);
			else if(n>=189)System.out.println(4);
			else if(n>=165)System.out.println(3);
			else if(n>=135)System.out.println(2);
			else if(n>=105)System.out.println(1);
			else System.out.println(0);
	}
}