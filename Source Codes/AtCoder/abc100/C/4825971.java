import java.io.*;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        int N = Integer.parseInt(str);
        str = br.readLine();
        long[] a = new long[N];
        int cont = 0;
        for (String s:str.split(" ")){
            a[cont] = Integer.parseInt(s);
            cont++;
        }
        int ans = 0;
        for (long i:a){
            while (i%2==0){
                if (i%2==0){
                    i/=2;
                    ans++;
                }
            }
        }
        System.out.println(ans);
    }
}