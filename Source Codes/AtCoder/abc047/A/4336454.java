import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        
        Scanner sc = new Scanner(System.in);

        int a = sc.nextInt();  
        int b = sc.nextInt();  
        int c = sc.nextInt();  

        if(a + b == c || b + c == a || c + a == b ){
            System.out.println("Yes");
        }else{
            System.out.println("No");
        }
    }
}