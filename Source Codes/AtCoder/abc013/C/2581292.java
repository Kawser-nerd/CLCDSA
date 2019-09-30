import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        double N = Double.parseDouble(in.next());
        double H = Double.parseDouble(in.next());
        double A = Double.parseDouble(in.next());
        double B = Double.parseDouble(in.next());
        double C = Double.parseDouble(in.next());
        double D = Double.parseDouble(in.next());
        double E = Double.parseDouble(in.next());

        double cost = Long.MAX_VALUE;
        for(int i = 0; i < N+1; i++) {
           double Y = Math.max(0, Math.floor(((N-i)*E-B*i-H) / (D+E))+1);
           cost = Math.min(cost, i*A+Y*C);
        }

        System.out.println((long)cost);
    }
}