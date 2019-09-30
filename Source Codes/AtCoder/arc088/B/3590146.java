import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int n  = s.length();
        int left = n/2-(n%2 ^ 1);
        int right = n/2;
        int width = -n%2;
        char mod = s.charAt(left);
        while(left >= 0 & right < n){
            if (s.charAt(right)!=mod | s.charAt(left)!=mod) {
                break;
            } else {
                width+=2;
            }
            left--;
            right++;
        }
        int k = n/2 + width/2 + n%2;
        System.out.println(k);
    }
}