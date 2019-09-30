import java.util.*;

public class Main {
    private static int N;
    private static int a;
    private static int b;

    public static void input(){
        Scanner scan = new Scanner(System.in);

        N = scan.nextInt();
        a = scan.nextInt();
        b = scan.nextInt();
    }

    public static void main(String args[]) {
        //??
        input();

        if (N >= 5)System.out.println((N-5)*a + 5*b);
        else System.out.println(N*b);
    }
}