package common;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Helper {
    public static String[] getAllFileContentAsArray(String filename) throws Exception {
        BufferedReader in = new BufferedReader(new FileReader(filename));
        List<String> all = new ArrayList<String>();
        String s = in.readLine();
        while(s != null) {
            all.add(s);
            s = in.readLine();
        }
        in.close();
        return all.toArray(new String[0]);
    }
    public static void writeToFile(String[] cont, String filename) throws Exception {
        File file = new File(filename);
        file.delete();
        FileWriter w = null;
        try {
            w = new FileWriter(file, true);
            for (String s : cont) {
                w.write(s + "\n");
            }
        } finally {
            if (w != null) {
                w.close();
            }
        }
    }
    
    public static int[] getIntegersFromString(String s) throws Exception {
        List<Integer> a = new ArrayList<Integer>();
        for (String se : s.split(" ")) {
            try {
                Integer x = Integer.parseInt(se);
                a.add(x);
            } catch (Exception e) {                
            }
        }
        int[] ret = new int[a.size()];
        for (int i = 0; i < a.size(); ++i) {
            ret[i] = a.get(i).intValue();
        }
        return ret;
    }
    private Helper() {
    }

}
