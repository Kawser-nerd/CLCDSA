import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {    
    
    public static void main(String[] args){
        
        Scanner sc = new Scanner(System.in);

        
        int cnt = 0;
        
        StringBuilder buf = new StringBuilder();
        
        String S = sc.next();        
        String chk[] = S.split("");
        
        for(int i = 0;i < S.length();i++){
             String chker = chk[i];
             String regex = "[0-9]+";
             Pattern p = Pattern.compile(regex);
             Matcher m = p.matcher(chker);
             
             if(m.find()){
                 cnt++;
                 buf.append(chker);
             }
             
        }
        
        System.out.println(buf.toString());
        
    }        
}