import java.util.*;

public class Main{
	public static void main(String[] args){
    Scanner scn = new Scanner(System.in);
      
    int A = scn.nextInt();
    int B = scn.nextInt(); 
    int C = 0;
      
    if(B%A==0){
    C=A+B;
    }else{
    C=B-A;
    }
      System.out.print(C);
    }
}