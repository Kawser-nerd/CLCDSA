import java.util.*;
public class Main {
	public static void main(String[] args){
    //???????
		Scanner sc = new Scanner(System.in);
		//String S = sc.next();
    //int B = sc.nextInt();
    //System.out.println();
		int A = sc.nextInt();
		int B = sc.nextInt();
		int C = sc.nextInt();
		int D = sc.nextInt();
		if(A+B>C+D){
			System.out.println("Left");
		}else if(A+B<C+D){
			System.out.println("Right");
		}else{
			System.out.println("Balanced");
		}
	}
}