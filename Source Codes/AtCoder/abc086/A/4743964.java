import java.util.*;
public class Main {
	public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
      	int a = scan.nextInt();
      	int b = scan.nextInt();
      	int product = a * b;
      	if(product % 2 == 1){
        	System.out.print("Odd");
      	}else{
      		System.out.print("Even");
      	}
    }
}