import java.io.*;
import java.util.*;

/**
 * @author Chris Dziemborowicz <chris@dziemborowicz.com>
 * @version 2012.0414
 */
public class RecycledNumbers
{
    public static void main(String[] args)
            throws Exception
    {
        // Get input files
        File dir = new File("/Users/Chris/Documents/UniSVN/code-jam/recycled-numbers/data");
        File[] inputFiles = dir.listFiles(new FilenameFilter() {
            @Override
            public boolean accept(File dir, String name)
            {
                return name.endsWith(".in");
            }
        });

        // Process each input file
        for (File inputFile : inputFiles) {
            System.out.printf("Processing \"%s\"...\n", inputFile.getName());

            String outputPath = inputFile.getPath().replaceAll("\\.in$", ".out");
            BufferedWriter writer = new BufferedWriter(new FileWriter(outputPath));

            Scanner scanner = new Scanner(inputFile);
            System.out.printf("Number of test cases: %s\n", scanner.nextLine());

            int count = 0;
            while (scanner.hasNext()) {
                String line = scanner.nextLine();
                String output = String.format("Case #%d: %d\n", ++count, process(line));

                System.out.print(output);
                writer.write(output);
            }

            writer.close();
            System.out.println("Done.\n");
        }

        // Compare to reference files (if any)
        for (File inputFile : inputFiles) {
            System.out.printf("Verifying \"%s\"...\n", inputFile.getName());

            String referencePath = inputFile.getPath().replaceAll("\\.in$", ".ref");
            String outputPath = inputFile.getPath().replaceAll("\\.in$", ".out");

            File referenceFile = new File(referencePath);
            if (referenceFile.exists()) {
                InputStream referenceStream = new FileInputStream(referencePath);
                InputStream outputStream = new FileInputStream(outputPath);

                boolean matched = true;
                int referenceRead, outputRead;
                do {
                    byte[] referenceBuffer = new byte[4096];
                    byte[] outputBuffer = new byte[4096];

                    referenceRead = referenceStream.read(referenceBuffer);
                    outputRead = outputStream.read(outputBuffer);

                    matched = referenceRead == outputRead
                            && Arrays.equals(referenceBuffer, outputBuffer);
                } while (matched && referenceRead != -1);

                if (matched) {
                    System.out.println("Verified.\n");
                } else {
                    System.out.println("*** NOT VERIFIED ***\n");
                }
            } else {
                System.out.println("No reference file found.\n");
            }
        }
    }


    public static int process(String line)
    {
        Scanner scanner = new Scanner(line);
        final int a = scanner.nextInt();
        final int b = scanner.nextInt();
        final int[] pow10 = new int[] { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000,
                100000000, 1000000000 };

        int count = 0;
        for (int n = a; n < b; n++) {
            Set<Integer> set = new HashSet<Integer>();
            int numDigits = numDigits(n);
            for (int d = 1; d < numDigits; d++) {
                int back = n % pow10[d];
                int front = n / pow10[d];
                int m = front + back * pow10[numDigits - d];
                if (n < m && m <= b && numDigits == numDigits(m)) {
                    set.add(m);
                }
            }
            count += set.size();
        }
        return count;
    }


    public static int numDigits(int n)
    {
        if (n < 0) {
            return numDigits(-n);
        } else if (n < 1) {
            return 0;
        } else if (n < 10) {
            return 1;
        } else if (n < 100) {
            return 2;
        } else if (n < 1000) {
            return 3;
        } else if (n < 10000) {
            return 4;
        } else if (n < 100000) {
            return 5;
        } else if (n < 1000000) {
            return 6;
        } else if (n < 10000000) {
            return 7;
        } else if (n < 100000000) {
            return 8;
        } else if (n < 1000000000) {
            return 9;
        } else {
            return 10;
        }
    }
}