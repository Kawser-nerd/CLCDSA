import java.io.*;
import java.util.StringTokenizer;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st =new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int Q = Integer.parseInt(st.nextToken());
        char[] arr = br.readLine().toCharArray();
        int[] num = new int[N];
        num[0] = 0;
        for(int i=1;i<N;++i)
        {
            num[i] = num[i-1] + (arr[i-1]=='A'&&arr[i]=='C'?1:0);
        }
        for(int i=0;i<Q;++i)
        {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            bw.write((num[end-1] - num[start-1]) +"\n");
        }
        bw.close();

    }
}