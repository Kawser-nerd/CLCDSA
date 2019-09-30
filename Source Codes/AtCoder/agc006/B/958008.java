import java.lang.reflect.Array;
import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int x = Integer.parseInt(st.nextToken());
        if(x == 1 || x == 2*n - 1){
            System.out.print("No");
            return;
        }
        System.out.println("Yes");
        StringBuilder sb = new StringBuilder();
        int array[] = new int[2*n];
        array[n] = x;
        for(int i = n - 1;i >= 1;i--)
            array[i] = array[i + 1] - 1;
        for(int i = n + 1;i < array.length;i++)
            array[i] = array[i - 1] + 1;
        for(int i = 1;i < array.length;i++){
            if(array[i] <= 0)array[i] += 2*n - 1;
            if(array[i] > 2*n - 1)array[i] -= 2*n - 1;
        }
        for(int i = 1;i < 2*n;i++){
            sb.append(array[i]);
            sb.append('\n');
        }
        System.out.print(sb);
    }
}