import java.io.*;
import java.util.*;

/**
 * @author Chris Dziemborowicz <chris@dziemborowicz.com>
 * @version 2012.0414
 */
public class DancingWithTheGooglers
{
    public static void main(String[] args)
            throws Exception
    {
        // Get input files
        File dir = new File("/Users/Chris/Documents/UniSVN/code-jam/dancing-with-the-googlers/data");
        File[] inputFiles = dir.listFiles(new FilenameFilter() {
            @Override
            public boolean accept(File dir, String name)
            {
                return name.endsWith(".in");
            }
        });

        // Learn score mappings
        learn();

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


    private static int[] highestOrdinary = new int[31];
    private static int[] highestSurprising = new int[31];


    public static void learn()
    {
        Arrays.fill(highestOrdinary, -1);
        Arrays.fill(highestSurprising, -1);

        for (int i = 0; i <= 10; i++) {
            for (int j = i; j <= i + 2 && j <= 10; j++) {
                for (int k = j; k <= i + 2 && k <= 10; k++) {
                    int score = i + j + k;
                    if (k == i + 2) {
                        if (k > highestSurprising[score]) {
                            highestSurprising[score] = k;
                        }
                    } else {
                        if (k > highestOrdinary[score]) {
                            highestOrdinary[score] = k;
                        }
                    }
                }
            }
        }
    }


    public static int process(String line)
    {
        // Parse input
        Scanner scanner = new Scanner(line);
        int num = scanner.nextInt();
        int numSurprising = scanner.nextInt();
        int p = scanner.nextInt();
        int[] scores = new int[num];
        for (int i = 0; i < num; i++) {
            scores[i] = scanner.nextInt();
        }

        // Find surprising scores
        int count = 0;
        for (int score : scores) {
            if (highestOrdinary[score] >= p) {
                count++;
            } else if (numSurprising > 0 && highestSurprising[score] >= p) {
                numSurprising--;
                count++;
            }
        }
        return count;
    }
}