import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double n=sc.nextInt()%12;
        double m=sc.nextInt();
        n=360/12*n+0.5*m;
        m*=6;
        System.out.println(Math.min((n+360-m)%360, 360-(n+360-m)%360));
    }
}