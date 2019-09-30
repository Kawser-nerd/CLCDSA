import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.regex.*;

public class Main {

    private static final Scanner scan = new Scanner(System.in);

    public static void main(String[] args) {
        int[] digit = new int[10];
        Map<Integer, Integer> map = new HashMap<>();
        Map<Integer, Integer> reverseMap = new HashMap<>();
        for (int i = 0; i < digit.length; i++) {
            digit[i] = scan.nextInt();
            map.put(i, digit[i]);
            reverseMap.put(digit[i], i);
        }
        int n = scan.nextInt();
        List<Integer> valueString = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String next = scan.next();
            String res = "";
            for (int j = 0; j < next.length(); j++) {
                res += Character.toString((char) (reverseMap.get(next.charAt(j) - '0') + '0'));
            }
            valueString.add(Integer.parseInt(res));
        }
        valueString.sort(Comparator.comparingInt(o -> o));
        for (int i = 0; i < n; i++) {
            String next = "" + valueString.get(i);
            String res = "";
            for (int j = 0; j < next.length(); j++) {
                res += Character.toString((char) (map.get(next.charAt(j) - '0') + '0'));
            }
            System.out.println(res);
        }
    }
}