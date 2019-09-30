import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.regex.*;

public class Main {

    private static final Scanner scan = new Scanner(System.in);

    public static void main(String[] args) {
        String s = scan.nextLine();
        List<Character> list = new ArrayList<>();
        list.add('I');
        list.add('C');
        list.add('T');
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == list.get(0) || s.charAt(i) == list.get(0) - 'A' + 'a') {
                list.remove(0);
                if (list.size() == 0) {
                    System.out.println("YES");
                    return;
                }
            }
        }
        System.out.println("NO");
    }
}