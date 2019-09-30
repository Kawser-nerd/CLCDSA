import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double t=1/(sc.nextDouble()/sc.nextDouble());
        double a=1/(sc.nextDouble()/sc.nextDouble());
        if(t==a){
            System.out.println("DRAW");
        }else if(t>a){
            System.out.println("TAKAHASHI");
        }else{
            System.out.println("AOKI");
        }
        
    }
}