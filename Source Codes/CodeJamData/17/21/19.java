import javax.swing.*;
import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.TreeSet;

public class Steed2CruiseControl {
    static class Horse {
        double start, speed;

        double time(double len) {
            return (len - start) / speed;
        }
    }

    static double solve(double len, Horse[] horses) {
        Arrays.sort(horses, Comparator.comparingDouble(a -> a.start));

        Horse slowest = horses[horses.length - 1];
        for (int i = horses.length - 2; i >= 0; i--) {
            if (slowest.time(len) < horses[i].time(len))
                slowest = horses[i];
        }

        return len / slowest.time(len);
    }

    public static void main(String[] args) throws Exception {
        JFileChooser jfc = new JFileChooser();
        jfc.setCurrentDirectory(new File("c:\\codejam\\data"));
        jfc.showOpenDialog(null);

        LineNumberReader in = new LineNumberReader(new InputStreamReader(new FileInputStream(jfc.getSelectedFile()), "UTF-8"));
        FileOutputStream fos = new FileOutputStream(new File(jfc.getSelectedFile().toString() + ".out"));
        OutputStreamWriter out = new OutputStreamWriter(fos, "UTF-8");
        Writer writer = line -> {
            System.out.println(line);
            out.write(line + "\n");
        };

        int T = Integer.parseInt(in.readLine());
        for (int c = 1; c <= T; c++) {
            String[] tmp = in.readLine().split(" ");

            double len = Integer.parseInt(tmp[0]);
            int nHorses = Integer.parseInt(tmp[1]);

            Horse[] horses = new Horse[nHorses];
            for (int a = 0; a < nHorses; a++) {
                tmp = in.readLine().split(" ");
                horses[a] = new Horse();
                horses[a].start = Double.parseDouble(tmp[0]);
                horses[a].speed = Double.parseDouble(tmp[1]);
            }

            writer.write("Case #" + c + ": " + solve(len, horses));
        }

        out.flush();
        fos.close();
    }

    interface Writer {
        void write(String s) throws Exception;
    }
}
