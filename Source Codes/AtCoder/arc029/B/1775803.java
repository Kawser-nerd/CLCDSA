import java.util.*;

class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        double inA = sc.nextDouble();
        double inB = sc.nextDouble();

        double A = Math.min(inA, inB);
        double B = Math.max(inA, inB);
        double r = Math.sqrt(Math.pow(A, 2) + Math.pow(B, 2));
        double p = Math.atan(A / B);

        int N = sc.nextInt();
        for(int i = 0; i < N; i++) {
            double inC = sc.nextDouble();
            double inD = sc.nextDouble();

            double C = Math.min(inC, inD);
            double D = Math.max(inC, inD);

            if(C >= A && D >= B) {
                System.out.println("YES");
            }
            else if(C < A && D < B || r < D) {
                System.out.println("NO");
            }
            else if(C >= r * Math.cos(Math.asin(D / r) - 2*p)) {
                System.out.println("YES");
            }
            else {
                System.out.println("NO");
            }

        }
    }
}