import java.util.*;
import static java.lang.System.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int n=sc.nextInt();
        int c=1;
        int[] ans=new int[n+1];
        int i=1;
        while (c<=n){
            if(d(i)){
                ans[c++]=i;
            }
            i++;
        }
        out.println(ans[n]);
    }
    static boolean d(int i){
        String s=String.valueOf(i);
        HashSet<Character> k=new HashSet<>();
        for (int j = 0; j < s.length(); j++) {
            k.add(s.charAt(j));
        }
        return k.size()==1;
    }
}