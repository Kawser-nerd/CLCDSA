import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String S = sc.next();
        String T = sc.next();
        int q = sc.nextInt();
        char[] s = S.toCharArray();
        char[] t = T.toCharArray();
        int[] fs = new int[s.length+1];
        int[] ft = new int[t.length+1];
        for(int i=1;i<=s.length;i++) fs[i] = fs[i-1]+(s[i-1]=='A'?1:2);
        for(int i=1;i<=t.length;i++) ft[i] = ft[i-1]+(t[i-1]=='A'?1:2);
        for(int i=0;i<q;i++){
            int a = sc.nextInt();
            int b = sc.nextInt();
            int c = sc.nextInt();
            int d = sc.nextInt();
            int curS = fs[b]-fs[a-1];
            int curT = ft[d]-ft[c-1];
            String ans = (curS%3)==(curT%3)?"YES":"NO";
            System.out.println(ans);
        }
    }
}