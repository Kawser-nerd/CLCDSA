import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static boolean isChokugo(String s){
        boolean res = true;
        for(int i = 0; i < s.length(); i++){
            if(s.charAt(i) == 'c' && s.charAt(i + 1) == 'h'){
                i++;
            }else if(s.charAt(i) != 'o' && s.charAt(i) != 'k' && s.charAt(i) != 'u'){
                res = false;
                break;
            }
        }
        return res;
    }
    public static void main(String args[]){
        Scanner scan = new Scanner(System.in);
        String x = scan.nextLine();
        String ans = (isChokugo(x))? "YES" : "NO";
        System.out.println(ans);
    }
}