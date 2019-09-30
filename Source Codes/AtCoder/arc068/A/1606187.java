import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        long x = Long.valueOf(line);
        x -= 6;
        System.out.println((long)Math.ceil(x/5.5)+1);
    }
}