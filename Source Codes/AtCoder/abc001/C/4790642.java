import java.util.*;

public class Main
{
    private static double round(double d)
    {
        return Math.round(d * 10.0) / 10.0;
    }

    private static String degToDir(int deg)
    {
        String[] dirs = {"N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE",
                "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW"};
        int i = (deg + 112) % 3600 / 225;
        return dirs[i];
    }

    private static int vToW(double v)
    {
        double[] upper = {0.2, 1.5, 3.3, 5.4, 7.9, 10.7,
                13.8, 17.1, 20.7, 24.4, 28.4, 32.6};
        for (int i = 0; i < 12; i++)
        {
            if (v <= upper[i]) return i;
        }
        return 12;
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);

        final int deg = sc.nextInt();
        final int dis = sc.nextInt();

        double v = round(dis / 60.0);

        String dir = v > 0.2 ? degToDir(deg) : "C";
        int w = vToW(v);

        System.out.println(dir + " " + w);
    }
}