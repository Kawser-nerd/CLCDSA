import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        long t_pre = 1, a_pre = 1;
        for(int i=0; i<n; i++){
            String[] str = br.readLine().split(" ");
            long t = Integer.parseInt(str[0]);
            long a = Integer.parseInt(str[1]);

            long rate = Math.max(t_pre/t + (t_pre%t==0 ?0:1), a_pre/a + (a_pre%a==0?0:1));
            t_pre = rate * t;
            a_pre = rate * a;
        }
        System.out.println(t_pre + a_pre);
    }
}