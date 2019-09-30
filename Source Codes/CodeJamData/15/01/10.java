package com.xs0;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.util.List;
import java.util.function.Consumer;

public class Ovation {
    public static void main(String[] args) throws Exception {
        for (File infile : new File("/home/mitja/codejam/ovation").listFiles((dir, name)->name.endsWith(".in"))) {
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

            int nCases = Integer.parseInt(lines.get(0));
            for (int a = 1; a <= nCases; a++) {
                String nums = lines.get(a).split(" ")[1];

                int standing = 0;
                int missing = 0;
                for (int shy = 0; shy < nums.length(); shy++) {
                    int thisShy = Character.digit(nums.charAt(shy), 10);
                    if (thisShy > 0) {
                        int needMore = shy > standing ? shy - standing : 0;
                        missing += needMore;
                        standing += needMore + thisShy;
                    }
                }

                out.accept("Case #" + a + ": " + missing + "\n");
            }

            outWriter.close();
        }
    }
}
