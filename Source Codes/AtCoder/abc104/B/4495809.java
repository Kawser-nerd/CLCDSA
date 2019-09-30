import java.util.*;
public class Main {
	public static void main(String[] args){
      	//???????
		Scanner sc = new Scanner(System.in);
		//int N = sc.nextInt();
    	//int M = sc.nextInt();
      	String S = sc.next();
      System.out.println(S.matches("A[a-z]+C[a-z]+") ? "AC" : "WA");
    }
}