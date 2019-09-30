import java.util.*;

public class Main
{

    static Scanner sc = new Scanner(System.in);
    static class Str{
        int[] chars = new int[26];
    }
    public static void main(String[] args) {
        int n = sc.nextInt();
        Str[] words = new Str[n];
        for (int i = 0; i < n; i++) {
            String s = sc.next();
            words[i] = new Str();
            for (int j = 0; j < s.length(); j++) {
                char c = s.charAt(j);
                words[i].chars[c - 'a'] += 1;
            }
        }
        Str fin = new Str();
        for (int i = 0; i < 26; i++) {
            int min_c = Integer.MAX_VALUE;
            for (int j = 0; j < n; j++) {
                min_c = Math.min(min_c, words[j].chars[i]);
            }
            fin.chars[i] = min_c;
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < fin.chars[i]; j++) {
                sb.append((char)(i + 'a'));
            }
        }
        System.out.println(sb.toString());
    }
}