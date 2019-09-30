import java.io.*;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        String[] ABK = str.split(" ");
        int cont = 0;
        for (int i=Math.min(Integer.parseInt(ABK[0]),Integer.parseInt(ABK[1]));i>0;i--){
            if (Integer.parseInt(ABK[0])%i==0 && Integer.parseInt(ABK[1])%i==0){
                cont++;
                if (cont==Integer.parseInt(ABK[2])){
                    System.out.println(i);
                    return;
                }
            }
        }
    }
}