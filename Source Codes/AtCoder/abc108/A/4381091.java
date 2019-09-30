import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        
        Scanner sc = new Scanner(System.in);
        int K = sc.nextInt();
        
        if(K % 2 == 0){
            System.out.println(K / 2 * K / 2);
        }else{
            System.out.println(K / 2 * (K / 2 + 1));
        }
    }
}