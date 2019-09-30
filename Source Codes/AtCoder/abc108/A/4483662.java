import java.util.*;
public class Main {
	public static void main(String[] args){
      	//???????
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
      	
      	
		if(A%2==0){
        	System.out.println((A/2)*(A/2));
        }else{
        	System.out.println((A/2)*(A/2+1));
        }
      
    }
}