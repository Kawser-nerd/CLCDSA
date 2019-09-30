import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        
        String str = sc.next();
        int length = str.length();
        
        int min = Integer.MAX_VALUE;
        for(int i = 0; i < length - 2; i++){
            int tmp = Integer.parseInt(str.substring(i,i+3));
            min = Math.min(min, Math.abs(753 - tmp));
        }
        System.out.println(min);
    }
}