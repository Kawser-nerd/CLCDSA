import java.util.Scanner;

public class Main {
    public static void main(String args[]){
        Scanner scan = new Scanner(System.in);
        String s1 = scan.next();
        String s2 = scan.next();
        String ans;
        if(s1.length() > s2.length()){
            ans = "GREATER";
        }else if(s1.length() < s2.length()){
            ans = "LESS";
        }else{
            ans = (s1.compareTo(s2) > 0)? "GREATER" : (s1.compareTo(s2) == 0)? "EQUAL" : "LESS";
        }
        System.out.println(ans);
    }
}