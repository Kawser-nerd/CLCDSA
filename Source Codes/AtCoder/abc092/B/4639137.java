import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int D = sc.nextInt();
        int X = sc.nextInt();
        int count=0;
 
        for(int i=0;i<N;i++) {
        	int A = sc.nextInt();
        	int x=0;
        	while(x*A+1<=D){
        		count++;
        		x++;
        	}
        	}
        System.out.println(X+count);
        }
}