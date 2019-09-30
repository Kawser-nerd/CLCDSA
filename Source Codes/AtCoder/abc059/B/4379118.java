import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        
        double A = Math.log10(sc.nextDouble());
        double B = Math.log10(sc.nextDouble());

        if(A > B){
            System.out.println("GREATER");
        }else if(A < B){
            System.out.println("LESS");
        }else{
            System.out.println("EQUAL");
        }
    }
}