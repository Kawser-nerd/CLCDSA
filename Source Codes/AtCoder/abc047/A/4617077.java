import java.util.Scanner;
public class Main{

    
   public static void main(String[] args)throws Exception{
     	Scanner sc = new Scanner(System.in);
     	int A = sc.nextInt();
     	int B = sc.nextInt();
     	int C = sc.nextInt();
     	if(A == B + C){
        	System.out.println("Yes");
        }	else if(B == A + C){
        		System.out.println("Yes");
        	 }else if(C == A + B){
          		System.out.println("Yes");
          	}else{
				System.out.println("No");
        	 }
  
   }
 }