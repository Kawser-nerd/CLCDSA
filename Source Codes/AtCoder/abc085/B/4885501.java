import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int N=Integer.parseInt(sc.next());
        Set<Integer> S=new HashSet<>();
        for (int i=0;i<N;i++){
            int d=Integer.parseInt(sc.next());
            S.add(d);
        }
        System.out.println(S.size());
    }
}