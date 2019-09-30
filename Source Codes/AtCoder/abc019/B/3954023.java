import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        Pattern p = Pattern.compile("(.)\\1{0,}");
        Matcher m = p.matcher(s);
        while (m.find()) {
            System.out.print(m.group(0).charAt(0));
            System.out.print(m.group(0).length());
        }
        System.out.println();
    }
}