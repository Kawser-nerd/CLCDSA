import java.util.*;

public class Main {

    public static void main(String[] args) {
        
        Scanner sn = new Scanner(System.in);
        int xa = sn.nextInt();
        int ya = sn.nextInt();
        int xb = sn.nextInt();
        int yb = sn.nextInt();
        int xc = sn.nextInt();
        int yc = sn.nextInt();
        
        System.out.println(Math.abs(((xb - xa) * (yc - yb) - (xb - xc) * (ya - yb)) /2.0 ));
        
    }
}