import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args)throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(input.readLine());
        int a = Integer.parseInt(tokenizer.nextToken());
        int b = Integer.parseInt(tokenizer.nextToken());
        int c = Integer.parseInt(tokenizer.nextToken());

        Set<Integer> hashSet = new HashSet<>();
        StringBuilder out = new StringBuilder();
        for (int i = a; i < a+c && i <= b; i++) {
            if (!hashSet.contains(i)){
                out.append(i).append("\n");
                hashSet.add(i);
            }
        }

        for (int i = b - c + 1; i <=b && i > a ; i++) {
            if (!hashSet.contains(i)){
                out.append(i).append("\n");
                hashSet.add(i);
            }
        }

//        System.out.println(hashSet.size());
        System.out.print(out);
    }
}