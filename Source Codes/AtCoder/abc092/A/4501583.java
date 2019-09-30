import java.util.*;
public class Main {
	public static void main(String[] args){
      	//???????
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
      	int B = sc.nextInt();
      	int C = sc.nextInt();
      	int D = sc.nextInt();
      	int ab = 0;
      	int cd = 0;
        if(A<B){
        	ab = A;
        }else{
        	ab = B;
        }
      	if(C<D){
        	cd = C;
        }else{
        	cd = D;
        }
      
      	System.out.println(ab+cd);
    }
}