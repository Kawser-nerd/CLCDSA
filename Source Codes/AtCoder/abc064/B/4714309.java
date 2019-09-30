import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(input.readLine());
        ArrayList<Integer> s = new ArrayList<>();
        StringTokenizer tokenizer = new StringTokenizer(input.readLine());
        for (int i = 0; i < n; i++) {
            s.add(Integer.parseInt(tokenizer.nextToken()));
        }
        Collections.sort(s);
        int sum = 0;
        for (int i = 1; i < n; i++) {
            sum += s.get(i) - s.get(i-1);
        }
        System.out.println(sum);
    }
}