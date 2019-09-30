import java.util.*;
 
class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();
        int[] D = new int[K];
        for(int i=0;i<K;i++) D[i]=sc.nextInt();
        HashSet<Integer> dic = new HashSet<>();
        for(int w:D) dic.add(w);
        int cur = N;
        while(cur<=99999){
            if(valid(cur,dic)) break;
            cur++;
        }
        System.out.println(cur);
    }
    static boolean valid(int N, HashSet<Integer> dic){
        String cur = Integer.toString(N);
        for(int i=0;i<cur.length();i++){
            int w = cur.charAt(i)-'0';
            if(dic.contains(w)) return false;
        }
        return true;
    }
}