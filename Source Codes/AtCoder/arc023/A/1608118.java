import java.util.*;

public class Main {
    private static int y;
    private static int m;
    private static int d;

    public static void input(){
        Scanner scan = new Scanner(System.in);

        y = scan.nextInt();
        m = scan.nextInt();
        d = scan.nextInt();
    }

    public static void main(String args[]) {
        //??
        input();

        int Y = 2014;
        int M = 5;
        int D = 17;

        if (m == 1) {
            y = y - 1;
            m = 13;
        }
        if (m == 2){
            y = y - 1;
            m = 14;
        }

        int diffFrom = 365 * y + y/4 - y/100 + y/400 + 306*(m+1)/10 + d - 429;//System.out.println(diffFrom);
        int diffTo = 365 * Y + Y/4 - Y/100 + Y/400 + 306*(M+1)/10 + D - 429;//System.out.println(diffTo);

        //if (y == 1) System.out.println(diffTo - diffFrom - 2);
        //else
        System.out.println(diffTo - diffFrom);
    }
}