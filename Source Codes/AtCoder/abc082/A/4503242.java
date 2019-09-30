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

		if((A+B)%2==0){
			System.out.println((A+B)/2);
		}else{
			System.out.println((A+B)/2+1);
		}
	}
}