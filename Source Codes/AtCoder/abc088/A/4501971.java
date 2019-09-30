import java.util.*;
public class Main {
	public static void main(String[] args){
    //???????
		Scanner sc = new Scanner(System.in);
		//String S = sc.next();
    //int B = sc.nextInt();
    //System.out.println();
		int N = sc.nextInt();
		int M = sc.nextInt();
		if(N%500 ==0 || N%500<=M){
			System.out.println("Yes");
		}else{
			System.out.println("No");	
		}
	}
}