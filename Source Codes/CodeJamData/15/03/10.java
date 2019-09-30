package com.xs0;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.util.List;
import java.util.function.Consumer;

public class Dijkstra {
    public static void main(String[] args) throws Exception {
        for (File infile : new File("/home/mitja/codejam/dijkstra").listFiles((dir, name)->name.endsWith(".in"))) {
            File outfile = new File(infile.getParentFile(), infile.getName() + ".out");
            FileWriter outWriter = new FileWriter(outfile);
            Consumer<String> out = str -> {
                try {
                    outWriter.write(str);
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
                System.out.print(str);
            };

            List<String> lines = Files.readAllLines(infile.toPath());

            int linePos = 0;
            int nCases = Integer.parseInt(lines.get(linePos++));
            for (int a = 1; a <= nCases; a++) {
                long repeat = Long.parseLong(lines.get(linePos++).split(" ")[1]);
                String chars = lines.get(linePos++);

                boolean result = solve(repeat, chars);

                out.accept("Case #" + a + ": " + (result ? "YES" : "NO") + "\n");
            }

            outWriter.close();
        }
    }

    static final int E = 0;
    static final int I = 1;
    static final int J = 2;
    static final int K = 3;

    static final int _E = 4;
    static final int _I = 5;
    static final int _J = 6;
    static final int _K = 7;

    static int[][] mul = {
        {  E,  I,  J,  K, _E, _I, _J, _K },
        {  I, _E,  K, _J, _I,  E, _K,  J },
        {  J, _K, _E,  I, _J,  K,  E, _I },
        {  K,  J, _I, _E, _K, _J,  I,  E },
        { _E, _I, _J, _K,  E,  I,  J,  K },
        { _I,  E, _K,  J,  I, _E,  K, _J },
        { _J,  K,  E, _I,  J, _K, _E,  I },
        { _K, _J,  I,  E,  K,  J, _I, _E },
    };

    private static boolean solve(long repeat, String chars) {
        if (repeat > 12)
            repeat = 12 + repeat % 4;

        int[] all = repeat(chars, (int)repeat);

        int pos = 0;
        int left = all[pos++];
        while (left != I && pos < all.length)
            left = mul[left][all[pos++]];
        if (left != I || pos >= all.length)
            return false;

        int mid = all[pos++];
        while (mid != J && pos < all.length)
            mid = mul[mid][all[pos++]];
        if (mid != J || pos >= all.length)
            return false;

        int right = all[pos++];
        while (pos < all.length)
            right = mul[right][all[pos++]];
        return right == K;
    }

    static int[] repeat(String chars, int repeat) {
        StringBuilder sb = new StringBuilder();
        for (int a = 0; a < repeat; a++)
            sb.append(chars);
        return toIndexes(sb.toString());
    }

    static int[] toIndexes(String chars) {
        int[] res = new int[chars.length()];
        for (int a = 0, n = chars.length(); a < n; a++)
            res[a] = index(chars.charAt(a));
        return res;
    }

    static int index(char c) {
        return c - 'i' + 1;
    }
}
