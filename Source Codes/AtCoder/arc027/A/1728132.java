import java.util.*;

public class Main {
    private static int h;
    private static int m;

    public static void input(){
        Scanner scan = new Scanner(System.in);

        h = scan.nextInt();
        m = scan.nextInt();

    }

    public static void main(String args[]) {
        //??
        input();

        System.out.println(18*60-h*60-m);
    }
}