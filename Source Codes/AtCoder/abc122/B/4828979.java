import java.util.*;
public class Main {
    public static boolean isValid(char c){
        if(c == 'A' || c == 'C' || c == 'T' || c=='G'){
            return true;
        }
        return false;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int max = 0;
        for(int i = 0 ; i < s.length() ; i++){
            int count = 0;
            for(int j = i ; j < s.length() ; j++){
                if(isValid(s.charAt(j))){
                    count++;
                    max = Math.max(max,count);
                } else {
                    break;
                }
            }
        }
        System.out.println(max);
    }
}