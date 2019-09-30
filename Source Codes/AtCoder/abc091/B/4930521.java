import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class Main {
    public static void main(String[] args)throws Exception{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(input.readLine());
        HashMap<String, Integer> blue = new HashMap<>();
        HashMap<String, Integer> red = new HashMap<>();
        String word;
        for (int i = 0; i < n; i++) {
            word = input.readLine();
            blue.put(word, blue.getOrDefault(word, 0) + 1);
        }
        int m = Integer.parseInt(input.readLine());
        for (int i = 0; i < m; i++) {
            word = input.readLine();
            red.put(word, red.getOrDefault(word, 0) + 1);
        }

        int max = 0;
        for (Map.Entry<String, Integer> blueEntry : blue.entrySet()) {
            max = Math.max(max, blueEntry.getValue() - red.getOrDefault(blueEntry.getKey() ,0));
        }

        System.out.println(max);
    }
}