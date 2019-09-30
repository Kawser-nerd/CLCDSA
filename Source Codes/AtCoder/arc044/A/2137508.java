import java.util.*;
public class Main{
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
                if(N==1){
                       System.out.println("Not Prime");
                       return;
                 }
                 if(N==2||N==5||N==3){
                       System.out.println("Prime");
                 }else if(N%2==0||N%5==0||N%3==0){
			System.out.println("Not Prime");
		}else{
			System.out.println("Prime");
		}		
	}
}