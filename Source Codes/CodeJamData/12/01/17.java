import java.io.*;
import java.util.*;

/**
 * @author Chris Dziemborowicz <chris@dziemborowicz.com>
 * @version 2012.0414
 */
public class SpeakingInTongues
{
    public static void main(String[] args)
            throws Exception
    {
        // Get input files
        File dir = new File("/Users/Chris/Documents/UniSVN/code-jam/speaking-in-tongues/data");
        File[] inputFiles = dir.listFiles(new FilenameFilter() {
            @Override
            public boolean accept(File dir, String name)
            {
                return name.endsWith(".in");
            }
        });

        // Learn language
        String[] googlerese = new String[] { "ejp mysljylc kd kxveddknmc re jsicpdrysi",
                "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
                "de kr kd eoya kw aej tysr re ujdr lkgc jv" };
        String[] english = new String[] { "our language is impossible to understand",
                "there are twenty six factorial possibilities",
                "so it is okay if you want to just give up" };
        learn(googlerese, english);

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
                String output = String.format("Case #%d: %s\n", ++count, process(line));

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


    private static char[] map = new char[36];


    public static void learn(String[] googlerese, String[] english)
    {
        map['y' - 'a'] = 'a';
        map['e' - 'a'] = 'o';
        map['q' - 'a'] = 'z';
        map['z' - 'a'] = 'q';

        for (int i = 0; i < googlerese.length; i++) {
            for (int j = 0; j < googlerese[i].length(); j++) {
                if (googlerese[i].charAt(j) != ' ') {
                    map[googlerese[i].charAt(j) - 'a'] = english[i].charAt(j);
                }
            }
        }
    }


    public static String process(String line)
    {
        StringBuilder sb = new StringBuilder(line.length());
        for (int i = 0; i < line.length(); i++) {
            char c = line.charAt(i);
            if (c == ' ') {
                sb.append(' ');
            } else {
                sb.append(map[c - 'a']);
            }
        }
        return sb.toString();
    }
}