import java.util.*;
import java.awt.*;
import java.awt.geom.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int n=sc.nextInt();
        n=2025-n;
        for (int i = 1; i < 10; i++) {
            for (int j = 1; j < 10; j++) {
                if(i*j==n)out.println(i+" x "+j);
            }
        }
    }
}