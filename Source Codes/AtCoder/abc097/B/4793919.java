import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int max = 1;
        
        for(int i = 2; i < x; i++){
            int exp = i * i;
            
            while(exp <= x){
                max = Math.max(exp,max);
                exp = exp * i;
            }
        }
        System.out.println(max);
    }
}