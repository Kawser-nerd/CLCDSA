import java.util.*;
import java.awt.*;
import java.awt.geom.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int n= sc.nextInt();
        double ans=0;
        for (int i = 0; i < n; i++) {
            double score=0;
            for (int j = 0; j < 5; j++) {
                double s=sc.nextDouble();
                score+=j!=4?s:s*11/90;
            }
            ans=max(score,ans);
        }
        out.println(ans);
    }
}