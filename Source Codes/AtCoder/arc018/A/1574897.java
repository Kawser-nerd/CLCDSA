import java.util.*;

public class Main {
    private static double h;
    private static double bmi;
    
    public static void input(){
        Scanner scan = new Scanner(System.in);

        h = scan.nextDouble();
        bmi = scan.nextDouble();
    }

    public static void main(String args[]) {
        //??
        input();
        
        System.out.println(bmi * Math.pow(h/100 , 2));
    }
}