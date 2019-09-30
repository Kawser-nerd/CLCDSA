import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int ans;

        if(N % 2 == 0){
            System.out.println(N);
        }else{
            System.out.println(2 * N);
        }
    }
}