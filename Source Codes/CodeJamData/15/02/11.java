package com.xs0;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.util.ArrayList;
import java.util.List;
import java.util.function.Consumer;

public class Pancakes {
    public static void main(String[] args) throws Exception {
        for (File infile : new File("/home/mitja/codejam/pancakes").listFiles((dir, name)->name.endsWith(".in"))) {
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
                linePos++; // skip
                ArrayList<Integer> nums = new ArrayList<>();
                for (String numStr : lines.get(linePos++).split(" "))
                    nums.add(Integer.valueOf(numStr));

                int best = solve(nums);

                out.accept("Case #" + a + ": " + best + "\n");
            }

            outWriter.close();
        }
    }

    private static int solve(ArrayList<Integer> nums) {
        int best = Integer.MAX_VALUE;
        for (int remain = 1; remain <= 1000; remain++) {
            int thisCase = remain + count(nums, remain);
            if (thisCase < best)
                best = thisCase;
        }
        return best;
    }

    private static int count(ArrayList<Integer> nums, int remain) {
        int res = 0;
        for (int num : nums)
            res += (num - 1) / remain;
        return res;
    }
}
