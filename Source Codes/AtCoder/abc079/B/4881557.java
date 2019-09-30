import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(input.readLine());
        long [] nValues = new long[n + 1];
        nValues[0] = 2;
        nValues[1] = 1;
        for (int i = 2; i <= n; i++) {
            nValues[i] = nValues[i-1] + nValues[i-2];
        }
        System.out.println(nValues[n]);

    }
}