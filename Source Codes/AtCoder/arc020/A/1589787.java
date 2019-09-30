import java.awt.*;
import java.util.*;

public class Main {
    private static int A;
    private static int B;

    public static void input(){
        Scanner scan = new Scanner(System.in);

        A = scan.nextInt();
        B = scan.nextInt();
    }

    public static void main(String args[]) {
        //??
        input();

        if(Math.abs(A) - Math.abs(B) > 0) System.out.println("Bug");
        else if (Math.abs(A) - Math.abs(B) < 0) System.out.println("Ant");
        else System.out.println("Draw");
    }
}