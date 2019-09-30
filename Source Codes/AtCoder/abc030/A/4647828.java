import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double a = sc.nextDouble()/sc.nextDouble();
        double b = sc.nextDouble()/sc.nextDouble();

        if(a<b) System.out.println("TAKAHASHI");
        else if(a>b) System.out.println("AOKI");
        else System.out.println("DRAW");
    }
}