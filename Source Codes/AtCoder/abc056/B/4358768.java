import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        
        int W = sc.nextInt();
        int a = sc.nextInt();
        int b = sc.nextInt();
        int ans;
        
        if(a < b){
            ans = b - a - W;
        }else{
            ans = a - b - W;
        }
        System.out.println( ans > 0  ?  ans : 0 );
    }
}