import java.io.InputStream;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String args[]) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        try{
            int n = Integer.parseInt(br.readLine());
            char[] s = br.readLine().toCharArray(), t = br.readLine().toCharArray();
            for(int i = 0; i <= n; ++i){
                boolean ok = true;
                for(int j = 0; j < n - i; ++j){
                    if(s[i + j] != t[j]){
                        ok = false;
                        break;
                    }
                }
                if(ok){
                    System.out.println(n + i);
                    return;
                }
            }
        }catch(IOException e){
            e.printStackTrace();
        }
    }
}