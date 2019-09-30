import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a = sc.next();
        char[] A = a.toCharArray();
        int n = A.length;
        HashSet<Character> dic = new HashSet<>();
        ArrayList<int[]> interval = new ArrayList<>();
        int right = n-1;
        for(int i=n-1;i>=0;i--){
            dic.add(A[i]);
            if(dic.size()==26){
                interval.add(new int[]{i,right});
                right = i-1;
                dic = new HashSet<>();
            }
        }
        int tot = interval.size();
        if(tot==0){
            System.out.println(helper(A,0,A.length-1));
            System.exit(0);
        }
        StringBuilder res = new StringBuilder();
        int[] next = interval.get(tot-1);
        char cur = helper(A,0,next[0]-1);
        res.append(cur);
        for(int i=1;i<=tot;i++){
            int idx = find(A,next[0],cur);
            cur = helper(A,idx+1,next[1]);
            res.append(cur);
            if(i<tot) next = interval.get(tot-i-1);
        }
        System.out.println(res.toString());
    }
    static char helper(char[] A, int left, int right){
        int[] cnt = new int[26];
        for(int i=left;i<=right;i++) cnt[A[i]-'a']++;
        for(int i=0;i<26;i++){
            if(cnt[i]==0) return (char)(i+'a');
        }
        return 'z';
    }
    static int find(char[] A, int left, char target){
        for(int i=left;i<A.length-1;i++){
            if(A[i]==target) return i;
        }
        return A.length;
    }
}