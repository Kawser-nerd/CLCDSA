import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        BufferedWriter bufferedWriter = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = scanner.nextInt();
        int K = scanner.nextInt();

        int res;
        if (N % K == 0) res = 0;
        else res = 1;

        bufferedWriter.write(Integer.toString(res));

        bufferedWriter.close();
        scanner.close();
    }
}