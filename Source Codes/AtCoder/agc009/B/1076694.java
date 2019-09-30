import java.io.*;
import java.util.*;
public class Main{
    static int dfs(ArrayList<Integer>list[],int idx,int par){
        int min = 0;
        //int cnt = 0;
        ArrayList<Integer>node = new ArrayList<>();
        for(int temp : list[idx]){
            if(temp == par)continue;
            int child = dfs(list,temp,idx);
            node.add(child);
        }
        Collections.sort(node);
        for(int temp : node){
            min = Math.max(temp,min) + 1;
        }
        //System.out.println(min + cnt + " " + idx);
        return min;
    }
    public static void main(String[] args)throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        ArrayList<Integer>list[] = new ArrayList[n + 1];
        for(int i = 1;i <= n;i++)
            list[i] = new ArrayList<>();
        for(int i = 2;i <= n;i++){
            int temp = Integer.parseInt(br.readLine());
            list[i].add(temp);
            list[temp].add(i);
        }
        System.out.println(dfs(list,1,-1));
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.