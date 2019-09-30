import java.io.*;
import java.util.*;

/**
 * Created by vikas.k on 27/12/16.
 */
public class Main {
    public static void main(String[] args){
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));

        int n = sc.nextInt();
        int k = sc.nextInt();

        List<List<Integer>> str = new ArrayList<>();

        for(int i=0;i<n;i++){
            str.add(new ArrayList<>());
        }

        for(int i=0;i<n-1;i++){
            int x = sc.nextInt();
            int y = sc.nextInt();

            str.get(x-1).add(y-1);
            str.get(y-1).add(x-1);
        }

        int ret = Integer.MAX_VALUE;

        if(k%2 == 0){
            for(int i=0;i<n;i++){
                Queue<Integer> q = new LinkedList<>();
                int[] dist = new int[n];
                Arrays.fill(dist,-1);
                dist[i] = 0;
                q.add(i);
                int cnt =0;

                while (!q.isEmpty()){
                    int v = q.poll();
                    if(dist[v] > k/2) cnt++;
                    for (int j:str.get(v)){
                        if(dist[j] == -1){
                            dist[j] = dist[v]+1;
                            q.add(j);
                        }
                    }
                }
                ret = Math.min(cnt,ret);
            }
        }else{
            for(int i=0;i<n;i++){
                for(int j:str.get(i)){
                    Queue<Integer> q = new LinkedList<>();
                    int[] dist = new int[n];
                    Arrays.fill(dist,-1);
                    dist[i] = 0;dist[j] = 0;
                    q.add(i);q.add(j);
                    int cnt =0;

                    while (!q.isEmpty()){
                        int v = q.poll();
                        if(dist[v] > k/2) cnt++;
                        for (int g:str.get(v)){
                            if(dist[g] == -1){
                                dist[g] = dist[v]+1;
                                q.add(g);
                            }
                        }
                    }
                    ret = Math.min(cnt,ret);
                }
            }
        }
        out.println(ret);
        out.close();
    }

    public static PrintWriter out;

    private static class MyScanner{
        BufferedReader bufferedReader;
        StringTokenizer stringTokenizer;

        private MyScanner(){
            bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        }

        private String next(){
            if(stringTokenizer == null || !stringTokenizer.hasMoreElements()){
                try {
                    stringTokenizer = new StringTokenizer(bufferedReader.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return stringTokenizer.nextToken();
        }

        private int nextInt(){
            return Integer.parseInt(next());
        }
        private String nextLine(){
            String ret= "";
            try {
                ret= bufferedReader.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return ret;
        }
    }
}