import java.util.*;
 
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        boolean boo = true;
        String words[] = new String[n];
        words[0] = sc.next();
        String str[] = words[0].split("");
        String endC = str[str.length -1];
        for(int i=1; i<n; i++){
            String s = sc.next();
            if(Arrays.asList(words).contains(s)) boo = false;
            String nowStr[] = s.split("");
            String startC = nowStr[0];
            if(!startC.equals(endC)) boo = false;
            endC = nowStr[nowStr.length -1];
            words[i] = s;
        }
        if(boo) System.out.println("Yes");
        else System.out.println("No");
    }
}