import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        
        int a = sc.nextInt();
        int b = sc.nextInt();
        
        if(a > b){
            System.out.println(a - 1);
        }else{
            System.out.println(a);
        }
    }
}