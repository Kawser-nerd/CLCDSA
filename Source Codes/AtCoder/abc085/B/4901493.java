import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args)throws Exception{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(input.readLine());
        boolean [] values = new boolean[101];
        int v;
        int count = 0;
        for (int i = 0; i < n; i++) {
            v = Integer.parseInt(input.readLine());
            if (!values[v])
                count++;
            values[v] = true;
        }
        System.out.println(count);
    }
}