import java.util.*;
public class Main {
	public static void main(String[] args){
      	//???????
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
    	//int M = sc.nextInt();
      	if(N<1200){
        	System.out.println("ABC");
        }else if(N<2800){
        	System.out.println("ARC");
        }else{
        	System.out.println("AGC");
        }
    }
}