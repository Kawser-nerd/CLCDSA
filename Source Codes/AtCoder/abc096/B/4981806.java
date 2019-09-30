import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args)throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(input.readLine());
        int [] valuees = new int[3];
        for (int i = 0; i < 3; i++) {
            valuees[i] = Integer.parseInt(tokenizer.nextToken());
        }
        Arrays.sort(valuees);

        int k = Integer.parseInt(input.readLine());
        for (int i = 0; i < k; i++) {
            valuees[2] *= 2;
        }
        System.out.println(valuees[0] + valuees[1]+ valuees[2]);
    }
}