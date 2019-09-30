import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int count = 0;
        String S = sc.next();
        for(int i = 0;i < S.length();i++){
            if('+' == S.charAt(i)){
                count++;
            } else count--;
        }

        System.out.println(count);
    }
}