import java.io.*;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        char[] arr = br.readLine().toCharArray();
        int max = 0, cur = 0;
        for(char c : arr)
        {
            if( c =='A' || c=='T' || c=='C' || c=='G' )
            {
                max = Math.max(max,++cur);
            }
            else
            {
                cur = 0;
            }
        }
        bw.write(max+"");
        bw.close();

    }
}