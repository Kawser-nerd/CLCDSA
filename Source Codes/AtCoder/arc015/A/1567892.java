import java.util.*;

public class Main {
    private static int n;
    private static double ans;

    public static void input(){
        Scanner scan = new Scanner(System.in);

        n = scan.nextInt();
    }

    public static void main(String args[]) {
        //??
        input();

        ans =  ((double) 9/5*n)+32;
        System.out.println(ans);
    }
}