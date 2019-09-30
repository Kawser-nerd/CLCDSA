import java.util.*;

public class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);

        int m = sc.nextInt();

        int vv;
        if (m < 100)
            vv = 0;
        else if (m <= 5000)
            vv = m / 100;
        else if (m <= 30000)
            vv = m / 1000 + 50;
        else if (m <= 70000)
            vv = m / 5000 + 74;
        else
            vv = 89;

        String s = String.format("%02d", vv);
        System.out.println(s);
    }
}