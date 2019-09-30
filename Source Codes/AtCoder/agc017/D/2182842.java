import java.util.ArrayList;
import java.util.List;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;
class Main{
    static int grundy(int v, int pare){
        int res = 0;
        for(int u : Edge[v])if(u!=pare)res^=(1+grundy(u,v));
        return res;
    }

    static List<Integer> Edge[];
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int N = scan.nextInt();
        Edge = new ArrayList[N];
        for(int i=0;i<N;++i)Edge[i]=new ArrayList<>();
        for(int i=0;i<N-1;++i){
            int x = scan.nextInt()-1;
            int y= scan.nextInt()-1;
            Edge[x].add(y);
            Edge[y].add(x);
        }
        if(grundy(0,-1)==0){
            System.out.println("Bob");
        }else{
            System.out.println("Alice");
        }
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.