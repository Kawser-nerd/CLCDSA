import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String S = sc.next();
        int i = 0,
        max = 0;
        for(; i < S.length(); i++){
            if(isACGT(S.substring(i, i+1))){
                int length = 0;
                for(; i < S.length(); i++){
                    if(!isACGT(S.substring(i, i+1))){
                        break;
                    }
                    length++;
                }
                if(max < length){
                    max =length;
                }
            }
        }
        System.out.println(max);
    }

    public static boolean isACGT(String s){
        return s.equals("A") || s.equals("C") || s.equals("G") || s.equals("T");
    }
}