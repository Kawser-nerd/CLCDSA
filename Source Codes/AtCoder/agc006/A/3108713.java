import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        String s =sc.next();
        String t = sc.next();
        int ans = 2*N;
        for(int start=0;start<N;start++){
            if(s.substring(start,N).equals(t.substring(0,N-start))){
                ans = N+start;
                break;
            }
        }
        System.out.println(ans);
    }
}