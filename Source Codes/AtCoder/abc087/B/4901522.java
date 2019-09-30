import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args)throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int a = Integer.parseInt(input.readLine());
        int b = Integer.parseInt(input.readLine());
        int c = Integer.parseInt(input.readLine());
        int target = Integer.parseInt(input.readLine());
        int count = 0;
        for (int i = 0; i <= a; i++) {
            for (int j = 0; j <= b; j++) {
                for (int k = 0; k <= c; k++) {
                    if ((i * 500)+(j * 100) + (k * 50) == target)
                        count++;
                }
            }
        }
        System.out.println(count);
    }
}