import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] input = sc.next().split("/");
        int y = Integer.parseInt(input[0]);
        int m = Integer.parseInt(input[1]);
        int d = Integer.parseInt(input[2]);

        if (y%m == 0 && y/m%d == 0)
            System.out.println(String.format("%04d/%02d/%02d", y,m,d));

        else {
            Calendar c = Calendar.getInstance();
            c.set(y,m-1,d);
            outer:
            while (true) {
                c.add(Calendar.DAY_OF_MONTH, 1);
                y = c.get(Calendar.YEAR);
                m = c.get(Calendar.MONTH)+1;
                d = c.get(Calendar.DATE);
                if (y%m == 0 && y/m%d == 0) {
                    System.out.println(String.format("%04d/%02d/%02d", y,m,d));
                    break outer;
                }
            }
        }
    }
}