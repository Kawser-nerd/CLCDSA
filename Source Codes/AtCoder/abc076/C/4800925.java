import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String t = sc.next();
        StringBuilder sb;
        List<String> list = new ArrayList<>();
        boolean matched = true;
        for (int i = s.length() - t.length(); i >= 0; i--) {
            matched = true;
            for (int j = 0; j < t.length(); j++) {
                if(s.charAt(i + j) != '?'
                        && s.charAt(i + j) != t.charAt(j)){
                    matched = false;
                    break;
                }
            }
            if(matched){
                sb = new StringBuilder();
                if(i != 0) sb.append(s.substring(0, i));
                sb.append(t);
                if(i != s.length() - t.length()) sb.append(s.substring(i + t.length()));
                list.add(sb.toString().replace('?', 'a'));
            }
        }

        if(list.size() > 0){
            Collections.sort(list);
            System.out.println(list.get(0));
        }
        else System.out.println("UNRESTORABLE");
        sc.close();
    }

}