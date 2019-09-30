import java.util.*;

class Main{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        String S = sc.next();
        int cnt = 0;
        for(int i = 0; i < S.length(); i++){
          char c = S.charAt(i);
          if(c == '1') {
            cnt++;
          }
        }
        System.out.println(Math.min(cnt,S.length() - cnt)*2);
    }
}