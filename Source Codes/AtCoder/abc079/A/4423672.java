import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String ans = "No";
        for(int i = 0; i < 2; i++){
            if(s.charAt(i) == s.charAt(i + 1) && s.charAt(i + 2) == s.charAt(i)){
                ans = "Yes";
                break;
            }
        }
        System.out.println(ans);
    }
}