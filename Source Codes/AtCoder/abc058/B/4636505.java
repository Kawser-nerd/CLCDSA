import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main{
    public static void main(String[] args)throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        String o = input.readLine();
        String e = input.readLine();

        StringBuilder out = new StringBuilder();

        for (int i = 0; i < Math.max(o.length(), e.length()); i++) {
            if (i < o.length())
                out.append(o.charAt(i));

            if (i < e.length())
                out.append(e.charAt(i));
        }
        System.out.println(out);
    }
}