import java.util.*;


public class Main{
	public static void main(String[] args){
    	Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        int a = in.nextInt();
        int b = in.nextInt();
      	for(int i = 0; i < m; i++){
            if(n <= a)
                n += b;
            n -= in.nextInt();
            if(n < 0){
                System.out.println(++i);
                return;
            }
        }
        System.out.println("complete");
    }
}