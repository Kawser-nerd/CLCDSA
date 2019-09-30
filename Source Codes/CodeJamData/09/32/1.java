import java.io.*;
import java.util.*;

/**
 * Created by HREN_VAM.
 */
public class B implements Runnable{

    BufferedReader in;
    PrintWriter out;
    StringTokenizer st;
    public static final String filename = "b";

    public static double EPS = 1e-9;

    double dist(double x, double y, double z){
        return Math.sqrt(x * x + y * y + z * z);
    }

    public void solve(int testNumber)throws IOException{
        out.print("Case #" + testNumber + ": ");
        int n = nextInt();
        double x = 0;
        double y = 0;
        double z = 0;
        double dx = 0;
        double dy = 0;
        double dz = 0;
        for(int i = 0;i < n;i ++){
            x += nextDouble();
            y += nextDouble();
            z += nextDouble();
            dx += nextDouble();
            dy += nextDouble();
            dz += nextDouble();
        }
        x /= n;
        y /= n;
        z /= n;
        dx /= n;
        dy /= n;
        dz /= n;

        if((dist(dx, dy, dz) < EPS) || (dist(x, y, z) < EPS)){
            out.println(dist(x, y, z) + " " + 0);
            return;
        }
        double angle = -(x * dx + y * dy + z * dz) / dist(x, y, z) / dist(dx, dy, dz);
        if(angle < EPS){
            out.println(dist(x, y, z) + " " + 0);
            return;
        }
        if(angle > 1)angle = 1;
        double sin = Math.sqrt(1 - angle * angle);
        out.print(dist(x, y, z) * sin + " ");
        out.println(((dist(x, y, z) * angle) / dist(dx, dy, dz)));
    }

    public void run(){
        try{
            Locale.setDefault(Locale.US);
            //in = new BufferedReader(new InputStreamReader(System.in));
            in = new BufferedReader(new FileReader(filename + ".in"));
            out = new PrintWriter(System.out);
            out = new PrintWriter(new FileWriter(filename + ".out"));
            st = new StringTokenizer("");
            int t = nextInt();
            for(int i = 0;i < t;i ++){
                solve(i + 1);
            }
            out.close();
        }catch(IOException e){
            throw new RuntimeException(e);
        }
    }

    public static void main(String[] args){
        new Thread(new B()).start();
    }

    public String nextToken()throws IOException{
        while(!st.hasMoreTokens()){
            st = new StringTokenizer(in.readLine());
        }
        return st.nextToken();
    }

    public int nextInt()throws IOException{
        return Integer.parseInt(nextToken());
    }

    public double nextDouble()throws IOException{
        return Double.parseDouble(nextToken());
    }
}