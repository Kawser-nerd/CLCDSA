import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main{
    public static void main(String[] args)throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
        String a = input.readLine();
        String b = input.readLine();
        String s = null;
        if (a.length() < b.length())
            s = "LESS";
        else if (a.length() > b.length())
            s = "GREATER";
        else {
            for (int i = 0; i < a.length(); i++) {
                if (a.charAt(i) > b.charAt(i)){
                    s = "GREATER";
                    break;
                }else if (a.charAt(i) < b.charAt(i)) {
                    s = "LESS";
                    break;
                }
            }
        }
        if (s == null)
            s = "EQUAL";

        out.write(s);
        out.write("\n");
        out.close();

    }
}