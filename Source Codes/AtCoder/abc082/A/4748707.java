import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double a, b;
        a = Double.parseDouble(sc.next());
        b = Double.parseDouble(sc.next());

        int ans = (int)Math.ceil((a + b) / 2);
        System.out.println(ans);

        sc.close();
    }
}