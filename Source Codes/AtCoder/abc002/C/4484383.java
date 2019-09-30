import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double xa=sc.nextInt();
        double ya=sc.nextInt();
        double xb=sc.nextInt();
        double yb=sc.nextInt();
        double xc=sc.nextInt();
        double yc=sc.nextInt();
        System.out.println(Math.abs((xb-xa)*(yc-ya)-(xc-xa)*(yb-ya))/2);

    }

}