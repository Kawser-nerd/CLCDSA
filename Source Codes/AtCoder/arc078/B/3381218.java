import java.util.*;

public class Main {
    public static int n;
    public static ArrayList<Integer>[] map;
    public static ArrayList<Integer> way;
    public static boolean[] check;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        map = new ArrayList[n];
        way = new ArrayList<Integer>();
        check = new boolean[n];
        for(int i=0; i<n; i++){
            map[i] = new ArrayList<Integer>();
        }
        for(int i=0; i<n-1; i++){
            int a = sc.nextInt() - 1;
            int b = sc.nextInt() - 1;
            map[a].add(b);
            map[b].add(a);
        }
        sc.close();

        bfs(n-1);
        way.add(n-1);


        int[] num = new int[n];
        Arrays.fill(check, false);
        for(int i=0; i<way.size(); i++){
            check[way.get(i)] = true;
        }
        for(int i=0; i<way.size(); i++){
            num[way.get(i)] = count(way.get(i));
        }
        int black = 0;
        for(int i=0; i<way.size()/2 + way.size()%2; i++){
            black += num[way.get(i)];
        }
        
        if(black <= n - black){
            System.out.println("Snuke");
        }else{
            System.out.println("Fennec");
        }
    }

    public static boolean bfs(int pos){
        if(pos == 0) return true;
        check[pos] = true;
        boolean ans = false;
        for(int i=0; i<map[pos].size(); i++){
            int next = map[pos].get(i);
            if(!check[next]){
                if(bfs(next)){
                    ans = true;
                    way.add(next);
                    break;
                }
            }
        }
        return ans;
    }

    public static int count(int pos){
        int ans = 1;
        check[pos] = true;
        for(int i=0; i<map[pos].size(); i++){
            int next = map[pos].get(i);
            if(!check[next]){
                ans += count(next);
            }
        }
        return ans;
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.