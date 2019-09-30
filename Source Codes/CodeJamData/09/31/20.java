package year2009.round1B.a;


import java.io.*;
import java.util.Scanner;
import java.util.HashMap;

public class ProblemA implements Runnable {
    public static final String FILE_PREFIX = "A";


    public void run() {

        try {
            Scanner in = new Scanner(new BufferedReader(new FileReader(getInputFile())));
            PrintWriter out = new PrintWriter("output-"  + FILE_PREFIX + ".txt");
            int COUNT = in.nextInt();

            for (int pass = 0; pass < COUNT; pass ++) {

                char[] values = in.next().trim().toCharArray();
                HashMap<Character, Integer> assoc = new HashMap<Character, Integer>();
                int next = 1;
                for (int i = 0; i < values.length; i++) {
                    char value = values[i];
                    if (assoc.containsKey(value))  {
                        continue;
                    }
                    assoc.put(value, next);
                    if (next == 1) {
                        next = 0;
                    } else if (next == 0) {
                        next = 2;
                    } else {
                        next++;
                    }
                }
                int base = assoc.size();
                long ans = 0;

                if (base == 1) {
                    base = 2;
                }
                for (int i = 0; i < values.length; i++) {
                    char value = values[i];
                    ans = ans * base + assoc.get(value);
                    System.err.print(assoc.get(value) + " ");
                }
                System.err.print ("     " + base + "       ");
                System.err.println(ans);

                out.printf("Case #%d: ", pass + 1);

                out.print(ans);

                out.println();
            }




            out.close();
            in.close();
        } catch (Throwable e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new Thread(new ProblemA()).start();
    }

    public File getInputFile() {
        File result = null;
        File temp = new File("input" + FILE_PREFIX + ".txt");
        if (temp.exists())  {
            result = temp;
        }
        temp = new File(FILE_PREFIX + "-small-attempt.in");
        if (temp.exists())  {
            result = temp;
        }
        int index = 0;
        temp = new File(FILE_PREFIX + "-small-attempt" +index +  ".in");
        while (temp.exists())  {
            result = temp;
            index++;
            temp = new File(FILE_PREFIX + "-small-attempt" +index +  ".in");
        }
        temp = new File(FILE_PREFIX + "-large.in");
        if (temp.exists())  {
            result = temp;
        }
        System.out.println("Using " + result);
        return result;
    }
}