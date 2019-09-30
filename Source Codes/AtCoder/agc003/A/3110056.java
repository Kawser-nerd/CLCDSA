import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int N = 0;
        int S = 0;
        int E = 0;
        int W = 0;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='N') N = N|1;
            if(s.charAt(i)=='E') E = E|1;
            if(s.charAt(i)=='S') S = S|1;
            if(s.charAt(i)=='W') W = W|1;
        }
        int flag1 = N^S;
        int flag2 = E^W;
        String ans = (flag1==0&&flag2==0)?"Yes":"No";
        System.out.println(ans);
    }
}