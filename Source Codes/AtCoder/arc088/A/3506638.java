import java.util.*;
class Main{
    /*
     * ?? -> nextInt() (???????ni())
     * ?? -> next()
     * 1? -> nextLine()
     * ?? : nextLIne?next(),nextInt()???????????????????????????????
     */
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        long x = sc.nextLong();
        long y = sc.nextLong();

        long v = x;
        int ans = 0;
        while(v <= y){
            v *= 2;
            ans++;
        }
        System.out.println(ans);
    }
}