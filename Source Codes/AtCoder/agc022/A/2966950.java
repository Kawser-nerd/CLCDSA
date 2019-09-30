import java.util.Scanner;
import java.util.Set;
import java.util.HashSet;
import java.util.TreeSet;
import java.util.Iterator;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String atoz = "abcdefghijklmnopqrstuvwxyz";
        for(String str : s.split("")){
            atoz = atoz.replace(str,"");
        }
        if(s.length() != 26){
            System.out.println(s + atoz.charAt(0));
            return;
        }
        int max = -1;
        char maxc = ' ';
        for(int i = 25;i >= 0;i--){
            char tmp = s.charAt(i);
            for(int j = i-1;j >= 0;j--){
                if(s.charAt(j) < tmp){
                    if(max < j){
                        max = j;
                        maxc = tmp;
                    }
                }
            }
        }
        if(max != -1){
            System.out.println(s.substring(0,max) + maxc);
            return;
        }
        System.out.println(-1);
    }
}