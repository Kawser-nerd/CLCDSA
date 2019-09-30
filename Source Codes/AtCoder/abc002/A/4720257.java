import java.util.*;

public class Main {

    public static void main(String[] args) {
        
        Scanner sn = new Scanner(System.in);
        int a = sn.nextInt();
        int b = sn.nextInt();
        
        if(a > b){
            System.out.println(a);
        } else {
            System.out.println(b);
        }
    }
}