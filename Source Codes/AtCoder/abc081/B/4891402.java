import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args)throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int min = 0;
        int n = Integer.parseInt(input.readLine());
        StringTokenizer  tokenizer = new StringTokenizer(input.readLine());
        int [] value = new int[n];
        for (int i = 0; i < n; i++) {
            value[i] = Integer.parseInt(tokenizer.nextToken());
        }
        boolean state = true;
        while (state){
            for (int i = 0; i < n && state; i++) {
                if ((value[i] & 1) == 0){
                    value[i]  /=2;
                }else{
                    state = false;
                }
            }
            if (state)
             min++;
        }
        System.out.println(min);
    }

    static int log(int x, int base) {
        return (int)(Math.log(x) / Math.log(base));
    }
}