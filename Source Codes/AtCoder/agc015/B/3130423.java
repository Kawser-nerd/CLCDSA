import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int len = s.length();
        long ans = len-1;
        for(int i=1;i<len-1;i++){
            if(s.charAt(i)=='U'){
                ans+=len-1-i;
                ans+=2*i;
            }
            else{
                ans += i;
                ans += 2*(len-1-i);
            }
        }
        ans += len-1;
        System.out.println(ans);
    }
}