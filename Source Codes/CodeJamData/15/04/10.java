package com.xs0;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.util.ArrayList;
import java.util.List;
import java.util.function.Consumer;

public class Ominoes {
    public static void main(String[] args) throws Exception {
        for (File infile : new File("/home/mitja/codejam/ominoes").listFiles((dir, name)->name.endsWith(".in"))) {
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
                String[] tmp = lines.get(linePos++).split(" ");

                int X = Integer.parseInt(tmp[0]);
                int R = Integer.parseInt(tmp[1]);
                int C = Integer.parseInt(tmp[2]);

                boolean canSolve = solve(X, R, C);

                out.accept("Case #" + a + ": " + (canSolve ? "GABRIEL" : "RICHARD") + "\n");
            }

            outWriter.close();
        }
    }

    private static boolean solve(int X, int R, int C) {
        if (X >= 7)
            return false;

        if ((R * C) % X != 0)
            return false;

        int min = Math.min(R, C);
        int max = Math.max(R, C);

        if (X > max)
            return false;

        if (X <= 2)
            return true;

        if (X == 3)         // []
            return min > 1; // [][]

        if (X == 4)         // [][]
            return min > 2; //   [][]

        if (X == 5)                                    // []         []
            return min >= 3 && (min != 3 || max > 5);  // [][]     [][][]
                                                       //   [][]       []

        assert X == 6;

        //  []
        //  [][][]
        //    []
        //    []

        // min == 4 => max == 3+3x
        // min == 5 => max == 6x
        return min > 3;
    }
}
