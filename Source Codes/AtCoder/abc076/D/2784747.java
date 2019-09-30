import java.util.*;

public class Main {
    static int modP = 1000000007;
    static long inf  = Long.MAX_VALUE;
    static int totalTime;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] T = new int[n];
        int[] V = new int[n];
        for(int i = 0; i < n; i++) {
            T[i] = in.nextInt();
        }
        for(int i = 0; i < n; i++) {
            V[i] = in.nextInt();
        }

        Restriction[] R = new Restriction[n+2];
        int currentTime = 0;
        for(int i = 0; i < n; i++) {
            R[i] = new Restriction(currentTime, currentTime+T[i], V[i]);
            currentTime += T[i];
        }
        totalTime = Arrays.stream(T).sum();
        R[n]   = new Restriction(0, 0, 0);
        R[n+1] = new Restriction(totalTime, totalTime, 0);

        float totalTraveled = 0f;
        float currentSpeed = 0f;
        for(float a = 0f; a < totalTime; a += 0.5f) {
            float nextLim = Float.MAX_VALUE;
            for(int i = 0; i < n+2; i++) {
                nextLim = Math.min(R[i].getLimit(a+0.5f), nextLim);
            }

            if(nextLim == currentSpeed) {
                totalTraveled += currentSpeed;
            }else if(nextLim > currentSpeed) {
                totalTraveled += currentSpeed + 0.5f;
                currentSpeed += 0.5f;
            }else if(nextLim < currentSpeed) {
                totalTraveled += currentSpeed - 0.5f;
                currentSpeed -= 0.5f;
            }
        }

        print(totalTraveled * 0.5f);
    }

    static void print(String s) {
        System.out.println(s);
    }

    static void print(int i) {
        System.out.println(i);
    }

    static void print(long i) {
        System.out.println(i);
    }

    static void print(float i) {
        System.out.println(i);
    }
}

class Restriction {
    int l, r, v;
    Restriction(int l, int r, int v) {
        this.l = l;
        this.r = r;
        this.v = v;
    }

    public float getLimit(float x) {
        if(x < l) {
             return (v + l - x);
         }else if(x > r) {
             return (v + x - r);
         }else{
             return v;
         }
    }
}