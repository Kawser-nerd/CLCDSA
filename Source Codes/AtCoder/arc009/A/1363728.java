import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) {
        try {
            // ????
            InputStreamReader isr = new InputStreamReader(System.in);
            BufferedReader br = new BufferedReader(isr);
            int n = Integer.parseInt(br.readLine());
            int sum = 0;
            for (int i = 0; i < n; i++) {
                String strArr[] = br.readLine().split(" ");
                int a = Integer.parseInt(strArr[0]);
                int b = Integer.parseInt(strArr[1]);
                sum += a * b;
            }
            double ans = sum * 1.05;
            System.out.println((int)Math.floor(ans));
        } catch (IOException e) {
            e.printStackTrace();
           }
    }
}