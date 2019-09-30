import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        Scanner sc = new Scanner(System.in);
        int v = Integer.parseInt(sc.next());
        double m =  (double)v/1000;
        //System.out.println(m);
        int vv=00;

        if (0 <= m && m <= 5) vv = (int)(m*10);
        else if (6 <= m && m <= 30 ) vv = (int)(m+50);
        else if (6 <= m && m <= 30 ) vv = (int)(m+10);
        else if (35 <= m && m <= 70 ) vv = (int)((m-30)/5 + 80);
        else vv = 89;

        System.out.printf("%02d\n", vv);
    }
}