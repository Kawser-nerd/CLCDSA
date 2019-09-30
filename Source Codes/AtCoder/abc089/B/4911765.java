import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args)throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(input.readLine());
        StringTokenizer tokenizer = new StringTokenizer(input.readLine());
        String [] charac = {"P", "W", "G", "Y"};
        boolean [] state = new boolean[4];
        String h;
        for (int i = 0; i < n; i++) {
            h = tokenizer.nextToken();
            for (int j = 0; j < 4; j++) {
                if (h.equals(charac[j])) {
                    state[j] = true;
                    break;
                }
            }
        }
        System.out.println(state[3]? "Four": "Three");
    }
}