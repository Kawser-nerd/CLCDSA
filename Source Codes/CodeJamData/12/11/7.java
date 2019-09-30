import java.util.*;
import java.math.*;

public class Main {
    
    public static void main(String[] args) throws Exception {
        Scanner scan = new Scanner(System.in);
        int task = scan.nextInt();
        int current = 1;
        while(task-- > 0)
        {
            int A = scan.nextInt();
            int B = scan.nextInt();
            double[] arr = new double[A];
            arr[0] = scan.nextDouble();
            for (int i = 1; i < A; i++) {
                arr[i] = arr[i - 1] * scan.nextDouble();
            }
            double result = Double.MAX_VALUE;
            for (int i = 0; i < A; i++) {
                result = Math.min(result, (B - A + 1 + 2 * (A - i - 1)) * arr[i] + (2 * B - A + 2 + 2 * (A - i - 1)) * (1 - arr[i]));
            }
            result = Math.min(result, B + 2);
            
            System.out.println("Case #" + current + ": " + result);
            current++;
        }
    }
}