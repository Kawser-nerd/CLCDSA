import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    public static void main(String[] args) {
        String s = scanner.next();
        String t = scanner.next();
        Matcher matcher = Pattern.compile("(.*)" + t.replaceAll(".", "[$0?]") + "(.*?)").matcher(s);
        System.out.println(matcher.matches() ? matcher.replaceFirst("$1" + t + "$2").replace('?', 'a') : "UNRESTORABLE");
    }
}